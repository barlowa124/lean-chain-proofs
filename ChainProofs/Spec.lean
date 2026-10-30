import ChainProofs.Chain

/-
  Concrete instance for evaluation: hash a `Nat` entry by mixing
  payload and stored prev. Injectivity is not claimed here; the
  point is to exercise the verifier definition on real values.
-/

namespace ChainProofs

def demoHash : Entry Nat Nat → Nat
  | ⟨p, s⟩ => s * 104729 + p

def H0 : Nat := 0

def e1 : Entry Nat Nat := ⟨11, H0⟩
def e2 : Entry Nat Nat := ⟨22, demoHash e1⟩
def e3 : Entry Nat Nat := ⟨33, demoHash e2⟩

def good : List (Entry Nat Nat) := [e1, e2, e3]
def tampered : List (Entry Nat Nat) := [e1, ⟨23, demoHash e1⟩, e3]
def deleted : List (Entry Nat Nat) := [e1, e3]
def appended : List (Entry Nat Nat) := good ++ [⟨44, demoHash e3⟩]
def badAppend : List (Entry Nat Nat) := good ++ [⟨44, 0⟩]

#eval chainValid demoHash H0 good        -- expect true
#eval chainValid demoHash H0 tampered    -- expect false
#eval chainValid demoHash H0 deleted     -- expect false
#eval chainValid demoHash H0 appended    -- expect true
#eval chainValid demoHash H0 badAppend   -- expect false
#eval nextPrev demoHash 0 good           -- expect demoHash e3

end ChainProofs
