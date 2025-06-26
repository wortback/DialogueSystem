// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialoguePlugin/Public/RecursiveParser/CondSyntaxTree.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCondSyntaxTree() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UCondTreeWrapper();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UCondTreeWrapper_NoRegister();
UPackage* Z_Construct_UPackage__Script_DialoguePlugin();
// End Cross Module References

// Begin Class UCondTreeWrapper
void UCondTreeWrapper::StaticRegisterNativesUCondTreeWrapper()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCondTreeWrapper);
UClass* Z_Construct_UClass_UCondTreeWrapper_NoRegister()
{
	return UCondTreeWrapper::StaticClass();
}
struct Z_Construct_UClass_UCondTreeWrapper_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "RecursiveParser/CondSyntaxTree.h" },
		{ "ModuleRelativePath", "Public/RecursiveParser/CondSyntaxTree.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCondTreeWrapper>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UCondTreeWrapper_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_DialoguePlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCondTreeWrapper_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCondTreeWrapper_Statics::ClassParams = {
	&UCondTreeWrapper::StaticClass,
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
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCondTreeWrapper_Statics::Class_MetaDataParams), Z_Construct_UClass_UCondTreeWrapper_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCondTreeWrapper()
{
	if (!Z_Registration_Info_UClass_UCondTreeWrapper.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCondTreeWrapper.OuterSingleton, Z_Construct_UClass_UCondTreeWrapper_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCondTreeWrapper.OuterSingleton;
}
template<> DIALOGUEPLUGIN_API UClass* StaticClass<UCondTreeWrapper>()
{
	return UCondTreeWrapper::StaticClass();
}
UCondTreeWrapper::UCondTreeWrapper(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCondTreeWrapper);
UCondTreeWrapper::~UCondTreeWrapper() {}
// End Class UCondTreeWrapper

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_RecursiveParser_CondSyntaxTree_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCondTreeWrapper, UCondTreeWrapper::StaticClass, TEXT("UCondTreeWrapper"), &Z_Registration_Info_UClass_UCondTreeWrapper, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCondTreeWrapper), 3322310689U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_RecursiveParser_CondSyntaxTree_h_4002308080(TEXT("/Script/DialoguePlugin"),
	Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_RecursiveParser_CondSyntaxTree_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_RecursiveParser_CondSyntaxTree_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
