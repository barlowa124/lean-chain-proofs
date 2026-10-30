/-
  Hash-chain receipt verifier, modeled after trust-tools/inference_receipts.

  Each entry carries a payload and a stored `prev` hash. A chain is
  valid when the first entry points at the genesis hash `H0` and every
  later entry's `prev` equals the hash of its predecessor entry
  (payload and stored hash together). The hash itself is abstract;
  collision resistance appears as an explicit injectivity hypothesis.
-/

namespace ChainProofs

/-- A chain entry: payload plus the stored hash of its predecessor. -/
structure Entry (D H : Type) where
  payload : D
  prev    : H

variable {D H : Type} [DecidableEq H]
variable (entryHash : Entry D H → H) (H0 : H)

/-- Tail check: every entry's `prev` equals the hash `ph` handed down
    from the entry that came before it. -/
def linkValid (entryHash : Entry D H → H) : H → List (Entry D H) → Bool
  | _,  []          => true
  | ph, e :: rest   => decide (e.prev = ph) && linkValid entryHash (entryHash e) rest

/-- Whole-chain verifier: first entry points at genesis, the rest link. -/
def chainValid (entryHash : Entry D H → H) (H0 : H) : List (Entry D H) → Bool
  | []        => true
  | e :: rest => decide (e.prev = H0) && linkValid entryHash (entryHash e) rest

/-- The `prev` value the next entry must store after `l`. -/
def nextPrev (entryHash : Entry D H → H) (ph : H) : List (Entry D H) → H
  | []      => ph
  | e :: l  => nextPrev entryHash (entryHash e) l

/-! ## Prefix (append-only) lemmas -/

theorem linkValid_prefix (ph : H) (l₁ l₂ : List (Entry D H)) :
    linkValid entryHash ph (l₁ ++ l₂) = true → linkValid entryHash ph l₁ = true := by
  induction l₁ generalizing ph with
  | nil => intro _; rfl
  | cons e rest ih =>
    intro hv
    simp only [List.cons_append, linkValid, Bool.and_eq_true, decide_eq_true_eq] at hv ⊢
    exact ⟨hv.1, ih _ hv.2⟩

/-- Any prefix of a valid chain is a valid chain: verification of a
    log is stable under appends, so appending cannot retroactively
    invalidate what was already verified. -/
theorem chainValid_prefix (l₁ l₂ : List (Entry D H)) :
    chainValid entryHash H0 (l₁ ++ l₂) = true → chainValid entryHash H0 l₁ = true := by
  cases l₁ with
  | nil => intro _; rfl
  | cons e rest =>
    intro hv
    simp only [List.cons_append, chainValid, Bool.and_eq_true, decide_eq_true_eq] at hv ⊢
    exact ⟨hv.1, linkValid_prefix entryHash _ _ _ hv.2⟩

/-- Extension is pinned: if `l` is valid and `l ++ [e]` is valid, the
    appended entry must store exactly the hash `nextPrev` predicts. -/
theorem linkValid_next (ph : H) (l : List (Entry D H)) (e : Entry D H)
    (rest : List (Entry D H)) :
    linkValid entryHash ph (l ++ e :: rest) = true →
    e.prev = nextPrev entryHash ph l := by
  induction l generalizing ph with
  | nil =>
    intro hv
    simp only [List.nil_append, linkValid, Bool.and_eq_true, decide_eq_true_eq]
      at hv
    exact hv.1
  | cons a l' ih =>
    intro hv
    simp only [List.cons_append, linkValid, Bool.and_eq_true, decide_eq_true_eq] at hv
    exact ih _ hv.2

/-- `nextPrev` after a list ending in `a` is `entryHash a`. -/
theorem nextPrev_concat (ph : H) (a : Entry D H) (l : List (Entry D H)) :
    nextPrev entryHash ph (l ++ [a]) = entryHash a := by
  induction l generalizing ph with
  | nil => rfl
  | cons e l' ih => exact ih _

/-! ## Tamper and deletion detection

    Collision resistance enters as the explicit hypothesis `inj`.
    Under it, any entry whose stored `prev` was bound to a different
    predecessor fails its link check. -/

/-- Core link fact: one mismatching link anywhere in the tail makes
    the whole check fail. -/
theorem linkValid_false_of_bad_link
    (ph : H) (pre : List (Entry D H)) (x y : Entry D H)
    (rest : List (Entry D H))
    (hne : entryHash x ≠ y.prev) :
    linkValid entryHash ph (pre ++ x :: y :: rest) = false := by
  induction pre generalizing ph with
  | nil =>
    simp only [List.nil_append, linkValid]
    rw [Bool.and_eq_false_iff]
    right
    rw [Bool.and_eq_false_iff]
    left
    rw [decide_eq_false_iff_not]
    intro h
    exact hne h.symm
  | cons a pre' ih =>
    simp only [List.cons_append, linkValid]
    rw [Bool.and_eq_false_iff]
    right
    exact ih _

/-- Tampering with an entry's payload while keeping every stored
    `prev` is detected at the link to its successor: the successor
    still stores the hash of the untampered entry. -/
theorem tamper_detected
    (ph : H) (pre : List (Entry D H))
    (x x' y : Entry D H) (rest : List (Entry D H))
    (inj : Function.Injective entryHash)
    (hx : x'.payload ≠ x.payload) (hy : y.prev = entryHash x) :
    linkValid entryHash ph (pre ++ x' :: y :: rest) = false := by
  apply linkValid_false_of_bad_link entryHash
  intro h
  have hxx : x' = x := inj (hy ▸ h)
  exact absurd rfl (hxx ▸ hx)

/-- Deleting a middle entry is detected: the entry after the gap
    stores the deleted entry's hash, which cannot match the hash of
    the entry now before it, since injectivity plus distinctness
    excludes `entryHash x = entryHash y`. -/
theorem deletion_detected
    (ph : H) (pre : List (Entry D H))
    (x y z : Entry D H) (rest : List (Entry D H))
    (inj : Function.Injective entryHash)
    (hz : z.prev = entryHash y) (hdiff : x ≠ y) :
    linkValid entryHash ph (pre ++ x :: z :: rest) = false := by
  apply linkValid_false_of_bad_link entryHash
  intro h
  have hxy : x = y := inj (hz ▸ h)
  exact hdiff hxy

end ChainProofs
