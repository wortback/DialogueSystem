// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialoguePlugin/Public/DialogueFlagUtils.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDialogueFlagUtils() {}

// Begin Cross Module References
DIALOGUEPLUGIN_API UEnum* Z_Construct_UEnum_DialoguePlugin_EFlagCompSymbol();
DIALOGUEPLUGIN_API UEnum* Z_Construct_UEnum_DialoguePlugin_EFlagOperator();
UPackage* Z_Construct_UPackage__Script_DialoguePlugin();
// End Cross Module References

// Begin Enum EFlagCompSymbol
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EFlagCompSymbol;
static UEnum* EFlagCompSymbol_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EFlagCompSymbol.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EFlagCompSymbol.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DialoguePlugin_EFlagCompSymbol, (UObject*)Z_Construct_UPackage__Script_DialoguePlugin(), TEXT("EFlagCompSymbol"));
	}
	return Z_Registration_Info_UEnum_EFlagCompSymbol.OuterSingleton;
}
template<> DIALOGUEPLUGIN_API UEnum* StaticEnum<EFlagCompSymbol>()
{
	return EFlagCompSymbol_StaticEnum();
}
struct Z_Construct_UEnum_DialoguePlugin_EFlagCompSymbol_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Equals.DisplayName", "Equals" },
		{ "Equals.Name", "EFlagCompSymbol::Equals" },
		{ "GreaterEquals.DisplayName", "GreaterEquals" },
		{ "GreaterEquals.Name", "EFlagCompSymbol::GreaterEquals" },
		{ "GreaterThan.DisplayName", "GreaterThan" },
		{ "GreaterThan.Name", "EFlagCompSymbol::GreaterThan" },
		{ "LessEquals.DisplayName", "LessEquals" },
		{ "LessEquals.Name", "EFlagCompSymbol::LessEquals" },
		{ "LessThan.DisplayName", "LessThan" },
		{ "LessThan.Name", "EFlagCompSymbol::LessThan" },
		{ "ModuleRelativePath", "Public/DialogueFlagUtils.h" },
		{ "None.DisplayName", "None" },
		{ "None.Name", "EFlagCompSymbol::None" },
		{ "NotEquals.DisplayName", "NotEquals" },
		{ "NotEquals.Name", "EFlagCompSymbol::NotEquals" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EFlagCompSymbol::GreaterThan", (int64)EFlagCompSymbol::GreaterThan },
		{ "EFlagCompSymbol::LessThan", (int64)EFlagCompSymbol::LessThan },
		{ "EFlagCompSymbol::GreaterEquals", (int64)EFlagCompSymbol::GreaterEquals },
		{ "EFlagCompSymbol::LessEquals", (int64)EFlagCompSymbol::LessEquals },
		{ "EFlagCompSymbol::Equals", (int64)EFlagCompSymbol::Equals },
		{ "EFlagCompSymbol::NotEquals", (int64)EFlagCompSymbol::NotEquals },
		{ "EFlagCompSymbol::None", (int64)EFlagCompSymbol::None },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_DialoguePlugin_EFlagCompSymbol_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_DialoguePlugin,
	nullptr,
	"EFlagCompSymbol",
	"EFlagCompSymbol",
	Z_Construct_UEnum_DialoguePlugin_EFlagCompSymbol_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_DialoguePlugin_EFlagCompSymbol_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_DialoguePlugin_EFlagCompSymbol_Statics::Enum_MetaDataParams), Z_Construct_UEnum_DialoguePlugin_EFlagCompSymbol_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_DialoguePlugin_EFlagCompSymbol()
{
	if (!Z_Registration_Info_UEnum_EFlagCompSymbol.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EFlagCompSymbol.InnerSingleton, Z_Construct_UEnum_DialoguePlugin_EFlagCompSymbol_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EFlagCompSymbol.InnerSingleton;
}
// End Enum EFlagCompSymbol

// Begin Enum EFlagOperator
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EFlagOperator;
static UEnum* EFlagOperator_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EFlagOperator.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EFlagOperator.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DialoguePlugin_EFlagOperator, (UObject*)Z_Construct_UPackage__Script_DialoguePlugin(), TEXT("EFlagOperator"));
	}
	return Z_Registration_Info_UEnum_EFlagOperator.OuterSingleton;
}
template<> DIALOGUEPLUGIN_API UEnum* StaticEnum<EFlagOperator>()
{
	return EFlagOperator_StaticEnum();
}
struct Z_Construct_UEnum_DialoguePlugin_EFlagOperator_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Add.DisplayName", "Add" },
		{ "Add.Name", "EFlagOperator::Add" },
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DialogueFlagUtils.h" },
		{ "None.DisplayName", "None" },
		{ "None.Name", "EFlagOperator::None" },
		{ "Set.DisplayName", "Set" },
		{ "Set.Name", "EFlagOperator::Set" },
		{ "Subtract.DisplayName", "Subtract" },
		{ "Subtract.Name", "EFlagOperator::Subtract" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EFlagOperator::Add", (int64)EFlagOperator::Add },
		{ "EFlagOperator::Subtract", (int64)EFlagOperator::Subtract },
		{ "EFlagOperator::Set", (int64)EFlagOperator::Set },
		{ "EFlagOperator::None", (int64)EFlagOperator::None },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_DialoguePlugin_EFlagOperator_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_DialoguePlugin,
	nullptr,
	"EFlagOperator",
	"EFlagOperator",
	Z_Construct_UEnum_DialoguePlugin_EFlagOperator_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_DialoguePlugin_EFlagOperator_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_DialoguePlugin_EFlagOperator_Statics::Enum_MetaDataParams), Z_Construct_UEnum_DialoguePlugin_EFlagOperator_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_DialoguePlugin_EFlagOperator()
{
	if (!Z_Registration_Info_UEnum_EFlagOperator.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EFlagOperator.InnerSingleton, Z_Construct_UEnum_DialoguePlugin_EFlagOperator_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EFlagOperator.InnerSingleton;
}
// End Enum EFlagOperator

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueFlagUtils_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EFlagCompSymbol_StaticEnum, TEXT("EFlagCompSymbol"), &Z_Registration_Info_UEnum_EFlagCompSymbol, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 590433254U) },
		{ EFlagOperator_StaticEnum, TEXT("EFlagOperator"), &Z_Registration_Info_UEnum_EFlagOperator, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 761068580U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueFlagUtils_h_2596806524(TEXT("/Script/DialoguePlugin"),
	nullptr, 0,
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueFlagUtils_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueFlagUtils_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
