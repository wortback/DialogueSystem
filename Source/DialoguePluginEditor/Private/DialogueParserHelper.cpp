// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueParserHelper.h"

#include "DialoguePluginSettings.h"
#include "PackageTools.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Serialization/DialogueParser.h"
#include "../../../../Plugins/Editor/EditorScriptingUtilities/Source/EditorScriptingUtilities/Public/EditorAssetLibrary.h"
#include "UObject/SavePackage.h"
#include "DialogueLogging.h"

UDialogueDataAsset* UDialogueParserHelper::RunParser(FFilePath DGLFile)
{
#if WITH_EDITOR
    const UDialoguePluginSettings* Settings = GetDefault<UDialoguePluginSettings>();

    const FString AssetFolder = Settings->DialogueAssetOutputPath;        
    const FString AssetName = FPaths::GetBaseFilename(DGLFile.FilePath);
    FString PackageName = UPackageTools::SanitizePackageName(AssetFolder / AssetName);

    UPackage* Package = nullptr;
    UDialogueDataAsset* AssetPtr = nullptr;

    // LOAD existing package + asset
    if (UEditorAssetLibrary::DoesAssetExist(PackageName))
    {
        Package = LoadPackage(nullptr, *PackageName, LOAD_NoWarn);
        Package->FullyLoad();   // make sure everything is in memory

        AssetPtr = FindObject<UDialogueDataAsset>(Package, *AssetName);
        if (!AssetPtr)
        {
            UE_LOG(DialogueAssetGeneration, Error,
                TEXT("Asset '%s' exists but is not a UDialogueDataAsset – aborting."), *PackageName);
            return nullptr;
        }

        UE_LOG(DialogueAssetGeneration, Log, TEXT("Overwriting existing asset '%s'."), *PackageName);
    }
    // CREATE a brand-new package + asset
    else
    {
        Package = CreatePackage(*PackageName);
        AssetPtr = NewObject<UDialogueDataAsset>(Package, UDialogueDataAsset::StaticClass(),
            *AssetName, RF_Public | RF_Standalone);

        FAssetRegistryModule::AssetCreated(AssetPtr);
        UE_LOG(DialogueAssetGeneration, Log, TEXT("Creating new asset '%s'."), *PackageName);
    }

    // Parse the .dgl file into the asset
    FDialogueParser Parser;
    if (!Parser.ParseFile(DGLFile.FilePath, *AssetPtr))
    {
        UE_LOG(DialogueAssetGeneration, Error, TEXT("Failed to parse %s"), *DGLFile.FilePath);
        return nullptr;
    }

    // Mark dirty + save
    AssetPtr->MarkPackageDirty();

    const FString FilePath = FPackageName::LongPackageNameToFilename(
        PackageName, FPackageName::GetAssetPackageExtension());

    FSavePackageArgs SaveArgs = FSavePackageArgs();
    SaveArgs.SaveFlags = RF_Public | RF_Standalone;

    if (!UPackage::SavePackage(Package, AssetPtr, *FilePath, SaveArgs))
    {
        UE_LOG(DialogueAssetGeneration, Error, TEXT("Could not save package %s"), *FilePath);
        return nullptr;
    }

    UE_LOG(DialogueAssetGeneration, Log, TEXT("Dialogue asset ready: %s"), *PackageName);
    return AssetPtr;
#else
    return nullptr; 
#endif
}
