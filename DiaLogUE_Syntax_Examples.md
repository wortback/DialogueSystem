
# DiaLogUE Syntax Examples

Here you can find examples of **valid and invalid DiaLogUE syntax**.

---

## Available Dialogue Nodes

- [Sentence](#sentence)
- [Choice Block](#choice-block)
- [Branch Block](#branch-block)
- [Set Meta](#set-meta)
- [If-Else Conditional](#if-else-conditional)
- [Comment Syntax](#comment-syntax)

---

### Sentence

A **sentence** node contains the speaker’s name and text in double quotation marks, separated by a colon.

**Valid syntax:**
```python
Speaker: "The weather is great today."
```

**Invalid syntax:**
```python
Speaker "The weather is great today."
Speaker: The weather is great today."
Speaker: "The weather is great today.
```

---

### Choice Block

A **choice block** contains choice options. Each option consists of a choice text and optional meta.
Meta can include:
- `[condition 'expr']` — the choice is only shown if expression `'expr'` is satisfied. `==, <=, >=, !=, <, >` are supported.
- `[goto 'branch_name']` — after picking this option, dialogue jumps to the branch with this name

**Valid syntax:**
```python
SpeakerA: "What do you want to eat?"
[choice]
	"Pizza"
	[condition F_LikesPizza == true]
	[goto B_Pizza] 
[choice]
	"Sushi"
	[condition F_LikesSushi==true]
[choice]
	"I'm not hungry."
[choice]
	"Something light."
	[goto B_CrazyAdventure]
```

**Invalid syntax:**
- No choice text
- Choice text doesn’t come first
- Choice text is not surrounded by double quotation marks

```python
SpeakerA: "What do you want to eat?"
[choice]
	[condition F_LikesPizza == true]
	[goto B_Pizza] 
[choice]
	[condition F_LikesSushi==true]
	"Sushi"
[choice]
	"I'm not hungry.
[choice]
	Something light."
	[goto B_CrazyAdventure]
```

---

### Branch Block

A **branch block** contains other dialogue nodes such as sentences and choices.  
**IMPORTANT:** Nested branches are **not allowed**!

**Valid syntax:**
```python
[branch B_CoolAdventure]
	SpeakerA: "What do you want to do?"
	[choice]
		"Go skating!"
	[choice]
		"Go jogging."
	SpeakerA: "Great, let's go!"
	SpeakerB: "Wait a moment. I thought of something better!"
	[goto B_CrazyAdventure]
```

**Invalid syntax:**
- Wrong indentation
- Missing branch name

```python
[branch]
	SpeakerA: "What do you want to do?"

[branch B_CoolAdventure]
		SpeakerA: "What do you want to do?"
	[choice]
		"Go skating!"
	[choice]
		"Go jogging."
SpeakerA: "Great, let's go!"
```

---

### Set Meta

The **set** meta data allows changing a flag’s state (both integer and boolean flags are supported).

**Valid syntax:**
```python
[set F_LikesElephants=true]
[set F_ElephantCount+10]
[set F_GiraffeCount-10]
```

**Invalid syntax:**
- Missing or improper brackets

```python
[set F_LikesElephants=true
set F_LikesElephants=true]
```

---

### If-Else Conditional

**if-else** conditionals allow branching without declaring a branch, based on a flag’s state. `==, <=, >=, !=, <, >` are supported.
Nested if-else branches are supported too. 
**IMPORTANT:** Every *else* must have at least one *if* predecessor!

**Valid syntax:**
```python
[if F_GiraffeLove>=10]
	SpeakerA: "I'm taking this giraffe home!"

[if F_ElephantLove>15]
	SpeakerA: "I'm a huge fan of elephants!"
    [if F_HomeBig==true]
        SpeakerA: "I will take this elephant home."

[if F_LikesElephants==true]
	SpeakerA: "I will take care of this elephant for the rest of my life!"
[else]
	SpeakerA: "Let me think."
```

WIP: Support for multiple expressions with if-statements (e.g. [if expr && expr]) is currently in development.

---

## Comment Syntax

- Use `#` at the start of a line for comments.
- Comment lines are ignored by the parser.

**Example:**
```python
# This is a comment
SpeakerA: "What do you want to eat?" # This is also a comment
```

---
