// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialoguePlugin/Public/Editor/DFlagTableBuilder.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDFlagTableBuilder() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDFlagTableBuilder();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDFlagTableBuilder_NoRegister();
UPackage* Z_Construct_UPackage__Script_DialoguePlugin();
// End Cross Module References

// Begin Class UDFlagTableBuilder Function BuildGlobalFlagTable
struct Z_Construct_UFunction_UDFlagTableBuilder_BuildGlobalFlagTable_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Editor/DFlagTableBuilder.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDFlagTableBuilder_BuildGlobalFlagTable_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDFlagTableBuilder, nullptr, "BuildGlobalFlagTable", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDFlagTableBuilder_BuildGlobalFlagTable_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDFlagTableBuilder_BuildGlobalFlagTable_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UDFlagTableBuilder_BuildGlobalFlagTable()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDFlagTableBuilder_BuildGlobalFlagTable_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDFlagTableBuilder::execBuildGlobalFlagTable)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	UDFlagTableBuilder::BuildGlobalFlagTable();
	P_NATIVE_END;
}
// End Class UDFlagTableBuilder Function BuildGlobalFlagTable

// Begin Class UDFlagTableBuilder
void UDFlagTableBuilder::StaticRegisterNativesUDFlagTableBuilder()
{
	UClass* Class = UDFlagTableBuilder::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "BuildGlobalFlagTable", &UDFlagTableBuilder::execBuildGlobalFlagTable },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDFlagTableBuilder);
UClass* Z_Construct_UClass_UDFlagTableBuilder_NoRegister()
{
	return UDFlagTableBuilder::StaticClass();
}
struct Z_Construct_UClass_UDFlagTableBuilder_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Editor/DFlagTableBuilder.h" },
		{ "ModuleRelativePath", "Public/Editor/DFlagTableBuilder.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDFlagTableBuilder_BuildGlobalFlagTable, "BuildGlobalFlagTable" }, // 859804282
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDFlagTableBuilder>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UDFlagTableBuilder_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_DialoguePlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDFlagTableBuilder_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDFlagTableBuilder_Statics::ClassParams = {
	&UDFlagTableBuilder::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDFlagTableBuilder_Statics::Class_MetaDataParams), Z_Construct_UClass_UDFlagTableBuilder_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDFlagTableBuilder()
{
	if (!Z_Registration_Info_UClass_UDFlagTableBuilder.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDFlagTableBuilder.OuterSingleton, Z_Construct_UClass_UDFlagTableBuilder_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDFlagTableBuilder.OuterSingleton;
}
template<> DIALOGUEPLUGIN_API UClass* StaticClass<UDFlagTableBuilder>()
{
	return UDFlagTableBuilder::StaticClass();
}
UDFlagTableBuilder::UDFlagTableBuilder(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDFlagTableBuilder);
UDFlagTableBuilder::~UDFlagTableBuilder() {}
// End Class UDFlagTableBuilder

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Editor_DFlagTableBuilder_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDFlagTableBuilder, UDFlagTableBuilder::StaticClass, TEXT("UDFlagTableBuilder"), &Z_Registration_Info_UClass_UDFlagTableBuilder, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDFlagTableBuilder), 105898921U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Editor_DFlagTableBuilder_h_2592569201(TEXT("/Script/DialoguePlugin"),
	Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Editor_DFlagTableBuilder_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Editor_DFlagTableBuilder_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
