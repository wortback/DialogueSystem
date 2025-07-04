# Dialogue System Architecture Overview

The plugin consists of two modules: **DialoguePlugin** and **DialoguePluginEditor**. The first module contains logic related to runtime whereas the editor module has tools for automatic generation and validation of the dialogue assets (such as the ones containing the actual dialogues, flags, data tables, and so on).

## High-level Overview of the Workflow

1. You begin by writing a dialogue snippet in DiaLogUE language and saving it as `.dgl` file.
2. If you reference any dialogue flags in the snippet, those should be created beforehand and their IDs (`UDialogueFlag: FName FlagName`) should match the signatures you use in your `.dgl` file
3. The plain text file is then parsed by the DiaLogUE parser that outputs a `.uasset`
4. The generated `.uasset` can then be referenced by any actor or component that implenemts `IDialogueResolver` inteface.
5. In order to use flags, a global flag table should be first build. The path to it can be set in the plugin settings. `UDialogueFlagManager` will be looking for it at that location too, so moving the table away is not recomended. 
6. During runtime, the generated `.uasset` is consumed by `UDialogueManager`.
7. `UDialogueManager` handles the beginning and the end of the dialogue session and works together with `UDialogueUIManager` and `UDialogueFlagManager` to render the dialogue on screen and serialise the changes to dialogue flags respectedly. 

## Useful links

[Runtime Architecture](runtime_architecture.md)
[Parser Architecture](parser_architecture.md)