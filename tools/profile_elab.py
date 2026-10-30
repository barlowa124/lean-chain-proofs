#!/usr/bin/env python3
"""Per-declaration elaboration profiler for this repo's Lean files.

Splits each .lean file into top-level commands, inserts `#time`
markers after every command, runs `lean` on the instrumented copy,
and pairs each reported `time: Nms` line with the command that
preceded it. Writes results/elab_profile.json and .md.

The command splitter is a heuristic tuned to this repo's style:
a command starts at column 0 with a keyword like `theorem` or `def`,
and `/-` block comments are tracked so comment bodies never split a
command. Multi-line declarations must end with a blank line or the
next column-0 keyword.
"""
import json
import re
import subprocess
import sys
import tempfile
from pathlib import Path

STARTERS = re.compile(
    r"^(theorem|lemma|def|structure|inductive|instance|abbrev|axiom|"
    r"opaque|variable|namespace|section|open|import|end\b|#|example|"
    r"class|/-|/-!|/--|@\[|noncomputable)"
)


def split_commands(path: Path):
    """Split into top-level command blocks.

    A new command starts at column 0 with a keyword, unless we are
    inside a `/-` block comment. A `/---/` docstring stays attached
    to the declaration that follows it.
    """
    lines = path.read_text().splitlines(keepends=True)
    commands, cur, depth = [], [], 0
    for ln in lines:
        is_doc = ln.lstrip().startswith("/--")
        starts = (
            depth == 0
            and bool(STARTERS.match(ln))
            and not ln.startswith("--")
            and not is_doc
        )
        if starts and cur:
            commands.append("".join(cur).rstrip())
            cur = []
        cur.append(ln)
        depth += ln.count("/-") - ln.count("-/")
        depth = max(depth, 0)
    if cur:
        commands.append("".join(cur).rstrip())
    return [c for c in commands if c.strip()]


def instrument(commands):
    out = []
    for c in commands:
        out.append("#time")
        out.append(c)
    return "\n\n".join(out) + "\n"


def label(cmd):
    m = re.search(r"\b(theorem|lemma|def|structure|inductive|instance|example)\s+([\w'.]+)", cmd)
    if m:
        return f"{m.group(1)} {m.group(2)}"
    first = cmd.splitlines()[0].strip()
    first = first.split("--", 1)[0].strip()
    return first[:70]


def main():
    lean_path = subprocess.run(
        ["lake", "env", "sh", "-c", "echo $LEAN_PATH"],
        capture_output=True, text=True, cwd=Path(__file__).parent.parent,
    ).stdout.strip()
    rows = []
    import os
    env = dict(os.environ, LEAN_PATH=lean_path)
    for src in sorted(Path("ChainProofs").glob("*.lean")):
        cmds = split_commands(src)
        with tempfile.NamedTemporaryFile(
            mode="w", suffix=".lean", dir="/tmp", delete=False
        ) as f:
            f.write(instrument(cmds))
            tmp = f.name
        proc = subprocess.run(
            ["lean", tmp], capture_output=True, text=True, env=env
        )
        times = re.findall(r"^time: (\d+)ms", proc.stdout, re.M)
        if len(times) != len(cmds):
            print(
                f"warning: {src} produced {len(times)} timings for "
                f"{len(cmds)} commands; skipping",
                file=sys.stderr,
            )
            continue
        for c, t in zip(cmds, times):
            rows.append({"file": str(src), "decl": label(c), "ms": int(t)})
    out_json = Path("results/elab_profile.json")
    out_json.write_text(json.dumps(rows, indent=2))
    lines = ["| file | declaration | elab ms |", "|---|---|---|"]
    for r in sorted(rows, key=lambda r: -r["ms"]):
        lines.append(f"| {r['file']} | {r['decl']} | {r['ms']} |")
    Path("results/elab_profile.md").write_text("\n".join(lines) + "\n")
    print(f"{len(rows)} declarations profiled -> results/elab_profile.md")


if __name__ == "__main__":
    sys.exit(main())
