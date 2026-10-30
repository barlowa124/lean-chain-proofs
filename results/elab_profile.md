| file | declaration | elab ms |
|---|---|---|
| ChainProofs/Chain.lean | structure Entry | 4 |
| ChainProofs/Chain.lean | def linkValid | 3 |
| ChainProofs/Chain.lean | def chainValid | 2 |
| ChainProofs/Chain.lean | def nextPrev | 2 |
| ChainProofs/Chain.lean | theorem linkValid_prefix | 2 |
| ChainProofs/Chain.lean | theorem deletion_detected | 2 |
| ChainProofs/Spec.lean | def appended | 2 |
| ChainProofs/Spec.lean | def badAppend | 2 |
| ChainProofs/Chain.lean | theorem chainValid_prefix | 1 |
| ChainProofs/Chain.lean | theorem linkValid_next | 1 |
| ChainProofs/Chain.lean | theorem nextPrev_concat | 1 |
| ChainProofs/Chain.lean | theorem linkValid_false_of_bad_link | 1 |
| ChainProofs/Chain.lean | theorem tamper_detected | 1 |
| ChainProofs/Spec.lean | def demoHash | 1 |
| ChainProofs/Spec.lean | def H0 | 1 |
| ChainProofs/Spec.lean | def e2 | 1 |
| ChainProofs/Spec.lean | def good | 1 |
| ChainProofs/Spec.lean | def tampered | 1 |
| ChainProofs/Spec.lean | def deleted | 1 |
| ChainProofs/Chain.lean | /- | 0 |
| ChainProofs/Chain.lean | namespace ChainProofs | 0 |
| ChainProofs/Chain.lean | variable {D H : Type} [DecidableEq H] | 0 |
| ChainProofs/Chain.lean | variable (entryHash : Entry D H → H) (H0 : H) | 0 |
| ChainProofs/Chain.lean | /-! ## Prefix (append-only) lemmas -/ | 0 |
| ChainProofs/Chain.lean | /-! ## Tamper and deletion detection | 0 |
| ChainProofs/Chain.lean | end ChainProofs | 0 |
| ChainProofs/Spec.lean | import ChainProofs.Chain | 0 |
| ChainProofs/Spec.lean | instance for | 0 |
| ChainProofs/Spec.lean | namespace ChainProofs | 0 |
| ChainProofs/Spec.lean | def e1 | 0 |
| ChainProofs/Spec.lean | def e3 | 0 |
| ChainProofs/Spec.lean | #eval chainValid demoHash H0 good | 0 |
| ChainProofs/Spec.lean | #eval chainValid demoHash H0 tampered | 0 |
| ChainProofs/Spec.lean | #eval chainValid demoHash H0 deleted | 0 |
| ChainProofs/Spec.lean | #eval chainValid demoHash H0 appended | 0 |
| ChainProofs/Spec.lean | #eval chainValid demoHash H0 badAppend | 0 |
| ChainProofs/Spec.lean | #eval nextPrev demoHash 0 good | 0 |
| ChainProofs/Spec.lean | end ChainProofs | 0 |
