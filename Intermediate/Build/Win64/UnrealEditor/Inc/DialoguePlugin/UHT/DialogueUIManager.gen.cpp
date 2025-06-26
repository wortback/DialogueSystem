// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialoguePlugin/Public/Runtime/DialogueUIManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDialogueUIManager() {}

// Begin Cross Module References
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueUIManager();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueUIManager_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UWorldSubsystem();
UPackage* Z_Construct_UPackage__Script_DialoguePlugin();
// End Cross Module References

// Begin Class UDialogueUIManager
void UDialogueUIManager::StaticRegisterNativesUDialogueUIManager()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDialogueUIManager);
UClass* Z_Construct_UClass_UDialogueUIManager_NoRegister()
{
	return UDialogueUIManager::StaticClass();
}
struct Z_Construct_UClass_UDialogueUIManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Runtime/DialogueUIManager.h" },
		{ "ModuleRelativePath", "Public/Runtime/DialogueUIManager.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueUIManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UDialogueUIManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWorldSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_DialoguePlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueUIManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueUIManager_Statics::ClassParams = {
	&UDialogueUIManager::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueUIManager_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueUIManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueUIManager()
{
	if (!Z_Registration_Info_UClass_UDialogueUIManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueUIManager.OuterSingleton, Z_Construct_UClass_UDialogueUIManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueUIManager.OuterSingleton;
}
template<> DIALOGUEPLUGIN_API UClass* StaticClass<UDialogueUIManager>()
{
	return UDialogueUIManager::StaticClass();
}
UDialogueUIManager::UDialogueUIManager() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueUIManager);
UDialogueUIManager::~UDialogueUIManager() {}
// End Class UDialogueUIManager

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Runtime_DialogueUIManager_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueUIManager, UDialogueUIManager::StaticClass, TEXT("UDialogueUIManager"), &Z_Registration_Info_UClass_UDialogueUIManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueUIManager), 2583007917U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Runtime_DialogueUIManager_h_4189811949(TEXT("/Script/DialoguePlugin"),
	Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Runtime_DialogueUIManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Runtime_DialogueUIManager_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
