// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialoguePlugin.h"
#include "ISettingsModule.h"
#include "DialoguePluginSettings.h"

#define LOCTEXT_NAMESPACE "FDialoguePluginModule"

void FDialoguePluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
    if (SettingsModule)
    {
        SettingsModule->RegisterSettings(
            "Project", "Plugins", "DiaLogUE Plugin",
            FText::FromString("DiaLogUE Plugin Pipeline"),
            FText::FromString("Configure the automated generation of different data assets and tables."),
            GetMutableDefault<UDialoguePluginSettings>()
        );
    }


}

void FDialoguePluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FDialoguePluginModule, DialoguePlugin)