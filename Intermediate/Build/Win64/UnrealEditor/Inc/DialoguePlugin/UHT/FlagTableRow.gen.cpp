// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialoguePlugin/Public/DialogueFlags/FlagTableRow.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFlagTableRow() {}

// Begin Cross Module References
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueFlag_NoRegister();
DIALOGUEPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FFlagTableRow();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
UPackage* Z_Construct_UPackage__Script_DialoguePlugin();
// End Cross Module References

// Begin ScriptStruct FFlagTableRow
static_assert(std::is_polymorphic<FFlagTableRow>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FFlagTableRow cannot be polymorphic unless super FTableRowBase is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FlagTableRow;
class UScriptStruct* FFlagTableRow::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FlagTableRow.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FlagTableRow.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FFlagTableRow, (UObject*)Z_Construct_UPackage__Script_DialoguePlugin(), TEXT("FlagTableRow"));
	}
	return Z_Registration_Info_UScriptStruct_FlagTableRow.OuterSingleton;
}
template<> DIALOGUEPLUGIN_API UScriptStruct* StaticStruct<FFlagTableRow>()
{
	return FFlagTableRow::StaticStruct();
}
struct Z_Construct_UScriptStruct_FFlagTableRow_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * The name of the table row corresponds to the flag name referenced in the .dgl file.\n * E.g. in '[if LikesPizza == true]', the flag name is 'LikesPizza'\n * So the data table row could look like {Row Name: LikesPizza; FlagAsset: Game/Dialogue/DF_LikesPizza.DF_LikesPizza}\n */" },
#endif
		{ "ModuleRelativePath", "Public/DialogueFlags/FlagTableRow.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The name of the table row corresponds to the flag name referenced in the .dgl file.\nE.g. in '[if LikesPizza == true]', the flag name is 'LikesPizza'\nSo the data table row could look like {Row Name: LikesPizza; FlagAsset: Game/Dialogue/DF_LikesPizza.DF_LikesPizza}" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FlagAsset_MetaData[] = {
		{ "Category", "FlagTableRow" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The actual data asset representing this flag */" },
#endif
		{ "ModuleRelativePath", "Public/DialogueFlags/FlagTableRow.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The actual data asset representing this flag" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_FlagAsset;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFlagTableRow>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FFlagTableRow_Statics::NewProp_FlagAsset = { "FlagAsset", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFlagTableRow, FlagAsset), Z_Construct_UClass_UDialogueFlag_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FlagAsset_MetaData), NewProp_FlagAsset_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FFlagTableRow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFlagTableRow_Statics::NewProp_FlagAsset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFlagTableRow_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFlagTableRow_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_DialoguePlugin,
	Z_Construct_UScriptStruct_FTableRowBase,
	&NewStructOps,
	"FlagTableRow",
	Z_Construct_UScriptStruct_FFlagTableRow_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFlagTableRow_Statics::PropPointers),
	sizeof(FFlagTableRow),
	alignof(FFlagTableRow),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFlagTableRow_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FFlagTableRow_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FFlagTableRow()
{
	if (!Z_Registration_Info_UScriptStruct_FlagTableRow.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FlagTableRow.InnerSingleton, Z_Construct_UScriptStruct_FFlagTableRow_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FlagTableRow.InnerSingleton;
}
// End ScriptStruct FFlagTableRow

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueFlags_FlagTableRow_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FFlagTableRow::StaticStruct, Z_Construct_UScriptStruct_FFlagTableRow_Statics::NewStructOps, TEXT("FlagTableRow"), &Z_Registration_Info_UScriptStruct_FlagTableRow, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FFlagTableRow), 1211495919U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueFlags_FlagTableRow_h_2030320690(TEXT("/Script/DialoguePlugin"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueFlags_FlagTableRow_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueFlags_FlagTableRow_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
