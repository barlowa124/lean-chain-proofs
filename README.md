# lean-chain-proofs

A Lean 4 formalization of the hash-chain receipt verifier from
`trust-tools/inference_receipts`, plus two small tools: an
AI-assisted prover that has a local model propose tactic proofs
while the Lean kernel decides pass or fail, and a per-declaration
elaboration profiler.

No `sorry` anywhere in the library.

## What is proved

`ChainProofs/Chain.lean` models a receipt chain abstractly: entries
of type `Entry D H` carry a `payload : D` and a stored `prev : H`,
and `entryHash : Entry D H → H` is an abstract function. Collision
resistance enters the theorems only as the explicit hypothesis
`Function.Injective entryHash`.

| Theorem | Statement |
| --- | --- |
| `chainValid_prefix` | `chainValid h H0 (l₁ ++ l₂) = true → chainValid h H0 l₁ = true`. Every prefix of a valid chain verifies, so appends cannot retroactively invalidate an already-verified log. |
| `linkValid_next` | In a valid tail, each entry's `prev` is exactly `nextPrev entryHash ph l`, so the next admissible append is pinned. |
| `nextPrev_concat` | `nextPrev` after a list ending in `a` is `entryHash a`. |
| `linkValid_false_of_bad_link` | One link `pre ++ x :: y :: rest` with `entryHash x ≠ y.prev` makes the whole check `false`. |
| `tamper_detected` | Under injectivity, rewriting entry `x`'s payload while keeping every stored `prev` fails verification at the successor link. |
| `deletion_detected` | Under injectivity plus `x ≠ y`, deleting middle entry `y` fails verification at the successor link. |

`ChainProofs/Spec.lean` is a concrete `Nat` instance with a mixer
hash. Its `#eval` checks confirm the expected values. A good chain
verifies and a payload-tampered chain fails. A middle-deleted chain
fails too. A correct append verifies and a bad-previous append
fails. The demo hash makes no injectivity claim. The theorems
quantify over the abstract `entryHash` with the hypothesis stated.

## The tools

`tools/propose.py` splices a model's proposed tactic body into a
template file and runs the real `lean` binary on it. The fixed
lemma set has eight statements. Reference proofs pass 8/8 under
`--check-gold`. Committed runs in `results/`:

| Model | Pass rate |
| --- | --- |
| qwen3-coder:30b | 0/8 (`results/propose_log.json`) |
| gemma3:27b | 1/8 (`results/propose_log_gemma3-27b.json`) |

The logs keep each model's raw proposal text next to the kernel's
first error. Both models failed mostly on invented lemma names
(`chainValid_eq_true`, `linkValid_def`) and Lean 3-era syntax. The
one gemma3 pass was a bare `rfl` on `nil_tail`.

`tools/profile_elab.py` splits each `.lean` file into top-level
commands, re-emits it with a `#time` prefix per command, runs `lean`,
and pairs the `time: Nms` lines back to declarations. Output lands
in `results/elab_profile.{json,md}` (38 declarations profiled on
this tree, max 4 ms for `structure Entry` and `def linkValid`).

## Run it

```bash
# toolchain: Lean 4.35.0 tarball from github.com/leanprover/lean4 releases
export PATH=$HOME/.local/opt/lean/bin:$PATH
lake build            # rebuilds .lake/build (oleans are committed)
python3 tools/profile_elab.py
python3 tools/propose.py --check-gold   # 8/8 reference proofs
PROPOSE_MODEL=gemma3:27b python3 tools/propose.py   # needs ollama
```

## Limits

- `entryHash` is an abstract function. Nothing here says anything
  about a concrete hash like SHA-256 beyond the injectivity
  hypothesis the theorems carry.
- The model does not cover sequence numbers or signatures, and it
  leaves out the checkpoint receipts the Rust project uses. It
  captures the core hash-link structure only.
- Detection theorems are stated for non-final positions. Tampering
  with the last entry's payload alone is not caught by link checks.
  In the real system the closing checkpoint covers that case.
- The profiler's command splitter is a column-0 keyword heuristic
  tuned to this repo's style, not a Lean parser.
- `.lake/build` is committed per the project brief. `lake build`
  reproduces it.
