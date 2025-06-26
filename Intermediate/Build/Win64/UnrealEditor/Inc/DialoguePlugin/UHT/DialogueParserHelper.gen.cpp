// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialoguePlugin/Public/DialogueParserHelper.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDialogueParserHelper() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueDataAsset_NoRegister();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueParserHelper();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueParserHelper_NoRegister();
UPackage* Z_Construct_UPackage__Script_DialoguePlugin();
// End Cross Module References

// Begin Class UDialogueParserHelper Function RunParser
struct Z_Construct_UFunction_UDialogueParserHelper_RunParser_Statics
{
	struct DialogueParserHelper_eventRunParser_Parms
	{
		UDialogueDataAsset* Asset;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "ModuleRelativePath", "Public/DialogueParserHelper.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Asset;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDialogueParserHelper_RunParser_Statics::NewProp_Asset = { "Asset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueParserHelper_eventRunParser_Parms, Asset), Z_Construct_UClass_UDialogueDataAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDialogueParserHelper_RunParser_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueParserHelper_RunParser_Statics::NewProp_Asset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueParserHelper_RunParser_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueParserHelper_RunParser_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDialogueParserHelper, nullptr, "RunParser", nullptr, nullptr, Z_Construct_UFunction_UDialogueParserHelper_RunParser_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueParserHelper_RunParser_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDialogueParserHelper_RunParser_Statics::DialogueParserHelper_eventRunParser_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueParserHelper_RunParser_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueParserHelper_RunParser_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UDialogueParserHelper_RunParser_Statics::DialogueParserHelper_eventRunParser_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDialogueParserHelper_RunParser()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueParserHelper_RunParser_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueParserHelper::execRunParser)
{
	P_GET_OBJECT(UDialogueDataAsset,Z_Param_Asset);
	P_FINISH;
	P_NATIVE_BEGIN;
	UDialogueParserHelper::RunParser(Z_Param_Asset);
	P_NATIVE_END;
}
// End Class UDialogueParserHelper Function RunParser

// Begin Class UDialogueParserHelper
void UDialogueParserHelper::StaticRegisterNativesUDialogueParserHelper()
{
	UClass* Class = UDialogueParserHelper::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "RunParser", &UDialogueParserHelper::execRunParser },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDialogueParserHelper);
UClass* Z_Construct_UClass_UDialogueParserHelper_NoRegister()
{
	return UDialogueParserHelper::StaticClass();
}
struct Z_Construct_UClass_UDialogueParserHelper_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *\n */" },
#endif
		{ "IncludePath", "DialogueParserHelper.h" },
		{ "ModuleRelativePath", "Public/DialogueParserHelper.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDialogueParserHelper_RunParser, "RunParser" }, // 2721573501
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueParserHelper>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UDialogueParserHelper_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_DialoguePlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueParserHelper_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueParserHelper_Statics::ClassParams = {
	&UDialogueParserHelper::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueParserHelper_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueParserHelper_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueParserHelper()
{
	if (!Z_Registration_Info_UClass_UDialogueParserHelper.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueParserHelper.OuterSingleton, Z_Construct_UClass_UDialogueParserHelper_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueParserHelper.OuterSingleton;
}
template<> DIALOGUEPLUGIN_API UClass* StaticClass<UDialogueParserHelper>()
{
	return UDialogueParserHelper::StaticClass();
}
UDialogueParserHelper::UDialogueParserHelper(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueParserHelper);
UDialogueParserHelper::~UDialogueParserHelper() {}
// End Class UDialogueParserHelper

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueParserHelper_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueParserHelper, UDialogueParserHelper::StaticClass, TEXT("UDialogueParserHelper"), &Z_Registration_Info_UClass_UDialogueParserHelper, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueParserHelper), 2764810404U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueParserHelper_h_1826799925(TEXT("/Script/DialoguePlugin"),
	Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueParserHelper_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueParserHelper_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
