// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialoguePlugin/Public/DialogueFlags/DialogueFlagManager.h"
#include "Runtime/Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDialogueFlagManager() {}

// Begin Cross Module References
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueFlagManager();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueFlagManager_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
UPackage* Z_Construct_UPackage__Script_DialoguePlugin();
// End Cross Module References

// Begin Class UDialogueFlagManager
void UDialogueFlagManager::StaticRegisterNativesUDialogueFlagManager()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDialogueFlagManager);
UClass* Z_Construct_UClass_UDialogueFlagManager_NoRegister()
{
	return UDialogueFlagManager::StaticClass();
}
struct Z_Construct_UClass_UDialogueFlagManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "DialogueFlags/DialogueFlagManager.h" },
		{ "ModuleRelativePath", "Public/DialogueFlags/DialogueFlagManager.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueFlagManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UDialogueFlagManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_DialoguePlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueFlagManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueFlagManager_Statics::ClassParams = {
	&UDialogueFlagManager::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueFlagManager_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueFlagManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueFlagManager()
{
	if (!Z_Registration_Info_UClass_UDialogueFlagManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueFlagManager.OuterSingleton, Z_Construct_UClass_UDialogueFlagManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueFlagManager.OuterSingleton;
}
template<> DIALOGUEPLUGIN_API UClass* StaticClass<UDialogueFlagManager>()
{
	return UDialogueFlagManager::StaticClass();
}
UDialogueFlagManager::UDialogueFlagManager() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueFlagManager);
UDialogueFlagManager::~UDialogueFlagManager() {}
// End Class UDialogueFlagManager

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueFlags_DialogueFlagManager_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueFlagManager, UDialogueFlagManager::StaticClass, TEXT("UDialogueFlagManager"), &Z_Registration_Info_UClass_UDialogueFlagManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueFlagManager), 2416175821U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueFlags_DialogueFlagManager_h_2760552201(TEXT("/Script/DialoguePlugin"),
	Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueFlags_DialogueFlagManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueFlags_DialogueFlagManager_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
