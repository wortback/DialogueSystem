// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class UEditorUtilityWidgetBlueprint;
class FSlateStyleSet;

class FDialoguePluginEditorModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	void OnPostEngineInit();

private:
	static const FName DialogueParserTabName;

	TSharedPtr<FSlateStyleSet> StyleSet;

	TSharedRef<SDockTab> SpawnDialogueParserTab(const FSpawnTabArgs& Args);

	UEditorUtilityWidgetBlueprint* GetAssetParserEUWBP();
};
