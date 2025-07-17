# Dialogue System DiaLogUE Parser Architecture

## 1. Script‑Parsing Subsystem

> How external plain‑text scripts are turned into runtime assets.

## 2. Main Classes

| Class                   | Role                                                                                                                                                                                                      |
| ----------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `FDialogueParser`       | Top‑level importer; reads a text file, orchestrates line‑by‑line parsing via the state machine, validates flags & dialogue flow, then populates a `UDialogueDataAsset`.                                   |
| `FDialogueParserContext`| Temporary workspace shared by every state; tracks the asset being built, current/previous nodes, indentation level, nesting stacks and any missing flag references.                                       |
| `FParserState` + derived singletons | Implements a finite‑state machine. Each static state (e.g. `FSentenceState`, `FChoiceState`, `FBranchState`, `FForkState`) handles one language construct, mutates the asset, and returns the next state. |

## 3. High‑level Flow

1. **Kick‑off (**`FDialogueParser`**)** – Allocates a fresh context, clears any existing nodes in the asset, runs a **flag extraction pass** to catch undefined flags early.
2. **Line Streaming (**`FDialogueParser`**)** – Reads the source file into memory, then iterates each non‑comment line through the current `FParserState`, which may transition to another state after processing.
3. **Validation** – After construction, helper passes detect missing branch references, empty fork branches, and shallow cycles (`A → B → A`), logging designer‑friendly warnings.
4. **Finalise** – Marks the asset dirty so the editor saves it; returns success/failure to the caller. The parser exists only in editor builds – shipped games include only the cooked `UDialogueDataAsset`s.

---

