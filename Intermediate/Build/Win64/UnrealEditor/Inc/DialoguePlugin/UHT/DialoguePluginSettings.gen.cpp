// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialoguePlugin/Public/DialoguePluginSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDialoguePluginSettings() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialoguePluginSettings();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialoguePluginSettings_NoRegister();
UPackage* Z_Construct_UPackage__Script_DialoguePlugin();
// End Cross Module References

// Begin Class UDialoguePluginSettings
void UDialoguePluginSettings::StaticRegisterNativesUDialoguePluginSettings()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDialoguePluginSettings);
UClass* Z_Construct_UClass_UDialoguePluginSettings_NoRegister()
{
	return UDialoguePluginSettings::StaticClass();
}
struct Z_Construct_UClass_UDialoguePluginSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * This file contains settings for the DiaLogUE Plugin.\n * Contains settings for the automated dialogue assets build pipeline.\n */" },
#endif
		{ "IncludePath", "DialoguePluginSettings.h" },
		{ "ModuleRelativePath", "Public/DialoguePluginSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "This file contains settings for the DiaLogUE Plugin.\nContains settings for the automated dialogue assets build pipeline." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GlobalFlagTableOutputPath_MetaData[] = {
		{ "Category", "Flag Table Builder" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Where to save the generated data table(e.g. / Game / Dialogue / Generated) */" },
#endif
		{ "ModuleRelativePath", "Public/DialoguePluginSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Where to save the generated data table(e.g. / Game / Dialogue / Generated)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GlobalFlagTableAssetName_MetaData[] = {
		{ "Category", "Flag Table Builder" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** What to call the asset (e.g. DT_FlagTable) */" },
#endif
		{ "ModuleRelativePath", "Public/DialoguePluginSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "What to call the asset (e.g. DT_FlagTable)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_GlobalFlagTableOutputPath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_GlobalFlagTableAssetName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialoguePluginSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UDialoguePluginSettings_Statics::NewProp_GlobalFlagTableOutputPath = { "GlobalFlagTableOutputPath", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialoguePluginSettings, GlobalFlagTableOutputPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GlobalFlagTableOutputPath_MetaData), NewProp_GlobalFlagTableOutputPath_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UDialoguePluginSettings_Statics::NewProp_GlobalFlagTableAssetName = { "GlobalFlagTableAssetName", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialoguePluginSettings, GlobalFlagTableAssetName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GlobalFlagTableAssetName_MetaData), NewProp_GlobalFlagTableAssetName_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDialoguePluginSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialoguePluginSettings_Statics::NewProp_GlobalFlagTableOutputPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialoguePluginSettings_Statics::NewProp_GlobalFlagTableAssetName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialoguePluginSettings_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UDialoguePluginSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_DialoguePlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialoguePluginSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialoguePluginSettings_Statics::ClassParams = {
	&UDialoguePluginSettings::StaticClass,
	"EditorPerProjectUserSettings",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UDialoguePluginSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UDialoguePluginSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialoguePluginSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialoguePluginSettings_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialoguePluginSettings()
{
	if (!Z_Registration_Info_UClass_UDialoguePluginSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialoguePluginSettings.OuterSingleton, Z_Construct_UClass_UDialoguePluginSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialoguePluginSettings.OuterSingleton;
}
template<> DIALOGUEPLUGIN_API UClass* StaticClass<UDialoguePluginSettings>()
{
	return UDialoguePluginSettings::StaticClass();
}
UDialoguePluginSettings::UDialoguePluginSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialoguePluginSettings);
UDialoguePluginSettings::~UDialoguePluginSettings() {}
// End Class UDialoguePluginSettings

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialoguePluginSettings_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialoguePluginSettings, UDialoguePluginSettings::StaticClass, TEXT("UDialoguePluginSettings"), &Z_Registration_Info_UClass_UDialoguePluginSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialoguePluginSettings), 2467218823U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialoguePluginSettings_h_4074534163(TEXT("/Script/DialoguePlugin"),
	Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialoguePluginSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialoguePluginSettings_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
