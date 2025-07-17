# Asset Building Pipeline

## Asset Parser

> How to build all necessary uassets.

In the DiaLogUE Plugin Settings (found under the project settings), you can find *OpenAssetParserOnStartup* attribute. When set to true, it invokes the asset parser tab that triggers parsing and asset generation for the uassets consimed by the runtime system of the plugin. 

![AssetParser](../images/AssetParserWindow.png)

---

## Functions

1. **Browse .dgl file**: .dgl file has to be first parsed into a uasset. For that, select a .dgl file in the explorer window that popes up upon clicking the button.
2. **Parse file**: after the file is selected, *Path/To/File.dgl* will be updated. Click on this button to generate a uasset. If the generation was successful, you will see a success message in the *Ouput Log* window. If parsing fails, you will see the line and the error that caused the failure. 
3. **Build FlagTable**: If you use any dialogue flags in the .dgl file, you have to create them beforehand. The parser will also check if all referenced flags are found in the project directory. The flag builder scans the whole */Game* dir, so your flag assets can be scattered across multiple folders. 