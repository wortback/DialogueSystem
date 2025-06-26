// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialoguePlugin/Public/Runtime/DialogueResolver.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDialogueResolver() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueResolver();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueResolver_NoRegister();
UPackage* Z_Construct_UPackage__Script_DialoguePlugin();
// End Cross Module References

// Begin Interface UDialogueResolver
void UDialogueResolver::StaticRegisterNativesUDialogueResolver()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDialogueResolver);
UClass* Z_Construct_UClass_UDialogueResolver_NoRegister()
{
	return UDialogueResolver::StaticClass();
}
struct Z_Construct_UClass_UDialogueResolver_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Runtime/DialogueResolver.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IDialogueResolver>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UDialogueResolver_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_DialoguePlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueResolver_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueResolver_Statics::ClassParams = {
	&UDialogueResolver::StaticClass,
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
	0x000840A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueResolver_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueResolver_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueResolver()
{
	if (!Z_Registration_Info_UClass_UDialogueResolver.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueResolver.OuterSingleton, Z_Construct_UClass_UDialogueResolver_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueResolver.OuterSingleton;
}
template<> DIALOGUEPLUGIN_API UClass* StaticClass<UDialogueResolver>()
{
	return UDialogueResolver::StaticClass();
}
UDialogueResolver::UDialogueResolver(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueResolver);
UDialogueResolver::~UDialogueResolver() {}
// End Interface UDialogueResolver

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Runtime_DialogueResolver_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueResolver, UDialogueResolver::StaticClass, TEXT("UDialogueResolver"), &Z_Registration_Info_UClass_UDialogueResolver, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueResolver), 1879952696U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Runtime_DialogueResolver_h_122846120(TEXT("/Script/DialoguePlugin"),
	Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Runtime_DialogueResolver_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Runtime_DialogueResolver_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
