#!/usr/bin/env python3
"""AI-assisted proof tool.

A local model proposes tactic proofs for a fixed lemma set. Each
proposal is spliced into a template file, the Lean kernel checks it,
and pass/fail lands in results/propose_log.json with a pass rate.

The lemma set mixes definitional facts about the chain verifier with
plain Nat facts so the log shows model strength on both.

Usage:
  python3 tools/propose.py --check-gold   # verify reference proofs
  python3 tools/propose.py                # run the model
"""
import json
import os
import re
import subprocess
import sys
import tempfile
import time
import urllib.request
from pathlib import Path

ROOT = Path(__file__).parent.parent
MODEL = os.environ.get("PROPOSE_MODEL", "qwen3-coder:30b")
OLLAMA = os.environ.get("OLLAMA_HOST", "http://localhost:11434")

LEAN_BIN = Path.home() / ".local/opt/lean/bin"
if not (LEAN_BIN / "lake").exists():
    LEAN_BIN = None


def _lake_env_path():
    lake = str(LEAN_BIN / "lake") if LEAN_BIN else "lake"
    env = dict(os.environ)
    if LEAN_BIN:
        env["PATH"] = str(LEAN_BIN) + ":" + env.get("PATH", "")
    return subprocess.run(
        [lake, "env", "sh", "-c", "echo $LEAN_PATH"],
        capture_output=True, text=True, cwd=ROOT, env=env,
    ).stdout.strip()

PREAMBLE = """import ChainProofs
open ChainProofs

variable {D H : Type} [DecidableEq H]
variable (entryHash : Entry D H → H) (H0 : H) (ph : H) (p : D)

"""

# (name, statement after `:=`, gold tactic body)
LEMMAS = [
    ("nil_tail", "linkValid entryHash ph [] = true", "rfl"),
    ("nil_chain", "chainValid entryHash H0 [] = true", "rfl"),
    ("nextPrev_nil", "nextPrev entryHash ph [] = ph", "rfl"),
    ("nextPrev_one", "(a : Entry D H) → nextPrev entryHash ph [a] = entryHash a",
     "intro a; rfl"),
    ("single_link", "linkValid entryHash ph [⟨p, ph⟩] = true",
     "simp [linkValid]"),
    ("add_zero", "(n : Nat) → n + 0 = n", "intro n; omega"),
    ("append_nil_prefix",
     "(l : List (Entry D H)) → chainValid entryHash H0 (l ++ []) = true → "
     "chainValid entryHash H0 l = true",
     "intro l h; exact chainValid_prefix _ _ _ _ h"),
    ("concrete_nil",
     "chainValid (D := Nat) (H := Nat) (fun _ => 0) 0 [] = true",
     "rfl"),
]


def lean_file(name, stmt, body):
    indented = "\n".join("  " + ln if ln.strip() else ln
                         for ln in body.splitlines())
    return PREAMBLE + f"theorem try_{name} : {stmt} := by\n{indented}\n"


def check(name, stmt, body):
    with tempfile.NamedTemporaryFile(mode="w", suffix=".lean",
                                     dir="/tmp", delete=False) as f:
        f.write(lean_file(name, stmt, body))
        tmp = f.name
    env = dict(os.environ)
    env["LEAN_PATH"] = _lake_env_path()
    if LEAN_BIN:
        env["PATH"] = str(LEAN_BIN) + ":" + env.get("PATH", "")
    t0 = time.time()
    proc = subprocess.run(["lean", tmp], capture_output=True,
                          text=True, env=env, timeout=120)
    err = (proc.stdout + proc.stderr).strip()
    ok = proc.returncode == 0 and "sorry" not in body
    return ok, err[:800], round(time.time() - t0, 2)


def propose(stmt):
    prompt = (
        "You are proving a theorem in Lean 4 (no Mathlib; core Lean only).\n"
        "The following names are already in scope from `import ChainProofs` "
        "under `open ChainProofs`: `linkValid`, `chainValid`, `nextPrev`,\n"
        "`Entry` (a structure with fields `payload : D` and `prev : H`),\n"
        "`linkValid_prefix`, `chainValid_prefix`, `nextPrev_concat`,\n"
        "`linkValid_next`, `tamper_detected`, `deletion_detected`.\n"
        "Variables in scope: `entryHash : Entry D H → H`, `H0 : H`, "
        "`ph : H`, `p : D`, `[DecidableEq H]`.\n\n"
        f"Theorem: `theorem try : {stmt} := by`\n\n"
        "Reply with ONLY the tactic body that proves it. No `sorry`, "
        "no comments, no markdown fence."
    )
    req = urllib.request.Request(
        OLLAMA + "/api/generate",
        data=json.dumps({
            "model": MODEL, "prompt": prompt, "stream": False,
            "options": {"temperature": 0.2, "num_predict": 200},
        }).encode(),
        headers={"Content-Type": "application/json"},
    )
    last = None
    for attempt in range(3):
        try:
            with urllib.request.urlopen(req, timeout=300) as r:
                text = json.load(r)["response"].strip()
            break
        except Exception as e:  # transient 500s on the shared GPU box
            last = e
            time.sleep(10 * (attempt + 1))
    else:
        raise last
    text = re.sub(r"^```(?:lean|lean4)?\s*|```$", "", text,
                  flags=re.M).strip()
    return text


def main():
    gold_only = "--check-gold" in sys.argv
    log = {"model": "gold" if gold_only else MODEL, "lemmas": []}
    for name, stmt, gold in LEMMAS:
        body = gold if gold_only else propose(stmt)
        ok, err, secs = check(name, stmt, body)
        log["lemmas"].append({
            "name": name, "statement": stmt, "proof": body,
            "pass": ok, "lean_secs": secs,
            "error": "" if ok else err,
        })
        print(f"{name}: {'PASS' if ok else 'FAIL'} ({secs}s)")
        if not ok:
            print("  proof:", body.replace(chr(10), " | ")[:120])
            print("  err:", err.splitlines()[0] if err else "?")
    npass = sum(1 for l in log["lemmas"] if l["pass"])
    log["pass_rate"] = f"{npass}/{len(LEMMAS)}"
    Path("results/propose_log.json").write_text(json.dumps(log, indent=2))
    print("pass rate:", log["pass_rate"])


if __name__ == "__main__":
    sys.exit(main())
