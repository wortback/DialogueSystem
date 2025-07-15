// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialoguePluginEditor.h"

#include "DialoguePluginSettings.h"
#include "Editor/DialogueAssetParserWidget.h"
#include "EditorUtilitySubsystem.h"
#include "ISettingsModule.h"
#include "EditorUtilityWidgetBlueprint.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleRegistry.h"
#include "Styling/SlateTypes.h"

#define LOCTEXT_NAMESPACE "FDialoguePluginEditorModule"

UEditorUtilityWidgetBlueprint* FDialoguePluginEditorModule::GetAssetParserEUWBP()
{
	const UDialoguePluginSettings* Settings = GetDefault<UDialoguePluginSettings>();
	return LoadObject<UEditorUtilityWidgetBlueprint>(nullptr,
		*Settings->AssetParserWidget, nullptr, LOAD_None, nullptr);
}

const FName FDialoguePluginEditorModule::DialogueParserTabName(TEXT("DialogueParserTab"));

void FDialoguePluginEditorModule::StartupModule()
{
	FCoreDelegates::OnPostEngineInit.AddRaw(this, &FDialoguePluginEditorModule::OnPostEngineInit);

	StyleSet = MakeShareable(new FSlateStyleSet("DialoguePluginStyle"));
	FString ContentDir = IPluginManager::Get().FindPlugin("DialoguePlugin")->GetBaseDir();
	StyleSet->SetContentRoot(ContentDir / TEXT("Resources"));

	// Register your custom icon (place your icon file in YourPlugin/Resources/Icons/)
	StyleSet->Set("DialogueParser.Icon", new FSlateImageBrush(
		StyleSet->RootToContentDir(TEXT("Icons/Icon_filled_16x.png")),
		FVector2D(16.0f, 16.0f)));

	// Register the style set
	FSlateStyleRegistry::RegisterSlateStyle(*StyleSet);
}

void FDialoguePluginEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	// unload the parser tab
	FCoreDelegates::OnPostEngineInit.RemoveAll(this);
	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(DialogueParserTabName);

	if (StyleSet.IsValid())
	{
		FSlateStyleRegistry::UnRegisterSlateStyle(*StyleSet);
		ensure(StyleSet.IsUnique());
		StyleSet.Reset();
	}
}

void FDialoguePluginEditorModule::OnPostEngineInit()
{
	FGlobalTabmanager::Get()->RegisterTabSpawner(
		DialogueParserTabName,
		FOnSpawnTab::CreateRaw(this, &FDialoguePluginEditorModule::SpawnDialogueParserTab))
		.SetDisplayName(NSLOCTEXT("DialogueEditor", "DialogueParserTabTitle", "AssetParser"))
		.SetMenuType(ETabSpawnerMenuType::Hidden)
		.SetTooltipText(NSLOCTEXT("DialogueEditor", "DialogueParserTabTooltip", "Parse .dgl assets and generate the flag table"))
		.SetIcon(FSlateIcon("DialoguePluginStyle", "DialogueParser.Icon"));

	// Only open the tab if the user desires so
	const UDialoguePluginSettings* Settings = GetDefault<UDialoguePluginSettings>();
	if (Settings->bOpenAssetParserOnStartup)
		FGlobalTabmanager::Get()->TryInvokeTab(DialogueParserTabName);
}

TSharedRef<SDockTab> FDialoguePluginEditorModule::SpawnDialogueParserTab(const FSpawnTabArgs& Args)
{
	TSharedRef<SDockTab> NewTab = SNew(SDockTab).TabRole(ETabRole::NomadTab);

	TSharedPtr<SDockTab> SharedPointer = GetAssetParserEUWBP()->SpawnEditorUITab(Args);
	 if (SharedPointer.IsValid())
	 {
		 NewTab = GetAssetParserEUWBP()->SpawnEditorUITab(Args);
	 }

	return NewTab;
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FDialoguePluginEditorModule, DialoguePlugin)