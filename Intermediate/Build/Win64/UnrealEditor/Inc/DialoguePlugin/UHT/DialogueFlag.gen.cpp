// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialoguePlugin/Public/DialogueFlag.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDialogueFlag() {}

// Begin Cross Module References
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueFlag();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueFlag_NoRegister();
DIALOGUEPLUGIN_API UEnum* Z_Construct_UEnum_DialoguePlugin_EFlagType();
ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
UPackage* Z_Construct_UPackage__Script_DialoguePlugin();
// End Cross Module References

// Begin Enum EFlagType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EFlagType;
static UEnum* EFlagType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EFlagType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EFlagType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DialoguePlugin_EFlagType, (UObject*)Z_Construct_UPackage__Script_DialoguePlugin(), TEXT("EFlagType"));
	}
	return Z_Registration_Info_UEnum_EFlagType.OuterSingleton;
}
template<> DIALOGUEPLUGIN_API UEnum* StaticEnum<EFlagType>()
{
	return EFlagType_StaticEnum();
}
struct Z_Construct_UEnum_DialoguePlugin_EFlagType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Boolean.Name", "EFlagType::Boolean" },
		{ "ModuleRelativePath", "Public/DialogueFlag.h" },
		{ "Numeric.Name", "EFlagType::Numeric" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EFlagType::Boolean", (int64)EFlagType::Boolean },
		{ "EFlagType::Numeric", (int64)EFlagType::Numeric },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_DialoguePlugin_EFlagType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_DialoguePlugin,
	nullptr,
	"EFlagType",
	"EFlagType",
	Z_Construct_UEnum_DialoguePlugin_EFlagType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_DialoguePlugin_EFlagType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_DialoguePlugin_EFlagType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_DialoguePlugin_EFlagType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_DialoguePlugin_EFlagType()
{
	if (!Z_Registration_Info_UEnum_EFlagType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EFlagType.InnerSingleton, Z_Construct_UEnum_DialoguePlugin_EFlagType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EFlagType.InnerSingleton;
}
// End Enum EFlagType

// Begin Class UDialogueFlag
void UDialogueFlag::StaticRegisterNativesUDialogueFlag()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDialogueFlag);
UClass* Z_Construct_UClass_UDialogueFlag_NoRegister()
{
	return UDialogueFlag::StaticClass();
}
struct Z_Construct_UClass_UDialogueFlag_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * This class represents flags that can be used in the dialogue to track certain states.\n * E.g. they can track player choices or relationships between the player and other characters.\n * Flags can be boolean or numeric. \n */" },
#endif
		{ "IncludePath", "DialogueFlag.h" },
		{ "IsBlueprintBase", "false" },
		{ "ModuleRelativePath", "Public/DialogueFlag.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "This class represents flags that can be used in the dialogue to track certain states.\nE.g. they can track player choices or relationships between the player and other characters.\nFlags can be boolean or numeric." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FlagName_MetaData[] = {
		{ "Category", "Flag Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Must be identical to the flag name used in the text file */" },
#endif
		{ "ModuleRelativePath", "Public/DialogueFlag.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Must be identical to the flag name used in the text file" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FlagDescription_MetaData[] = {
		{ "Category", "Flag Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Just for reference. Is not displayed anywhere */" },
#endif
		{ "ModuleRelativePath", "Public/DialogueFlag.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Just for reference. Is not displayed anywhere" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FlagType_MetaData[] = {
		{ "Category", "Flag Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Numeric or boolean */" },
#endif
		{ "ModuleRelativePath", "Public/DialogueFlag.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Numeric or boolean" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoolValue_MetaData[] = {
		{ "Category", "DialogueFlag" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If bool, this value will be taken into account when evaluating */" },
#endif
		{ "ModuleRelativePath", "Public/DialogueFlag.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If bool, this value will be taken into account when evaluating" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IntValue_MetaData[] = {
		{ "Category", "DialogueFlag" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If numeric, this value will be taken into account when evaluating */" },
#endif
		{ "ModuleRelativePath", "Public/DialogueFlag.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If numeric, this value will be taken into account when evaluating" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_FlagName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FlagDescription;
	static const UECodeGen_Private::FBytePropertyParams NewProp_FlagType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_FlagType;
	static void NewProp_BoolValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_BoolValue;
	static const UECodeGen_Private::FIntPropertyParams NewProp_IntValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueFlag>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UDialogueFlag_Statics::NewProp_FlagName = { "FlagName", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueFlag, FlagName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FlagName_MetaData), NewProp_FlagName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UDialogueFlag_Statics::NewProp_FlagDescription = { "FlagDescription", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueFlag, FlagDescription), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FlagDescription_MetaData), NewProp_FlagDescription_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UDialogueFlag_Statics::NewProp_FlagType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UDialogueFlag_Statics::NewProp_FlagType = { "FlagType", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueFlag, FlagType), Z_Construct_UEnum_DialoguePlugin_EFlagType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FlagType_MetaData), NewProp_FlagType_MetaData) }; // 3397836668
void Z_Construct_UClass_UDialogueFlag_Statics::NewProp_BoolValue_SetBit(void* Obj)
{
	((UDialogueFlag*)Obj)->BoolValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDialogueFlag_Statics::NewProp_BoolValue = { "BoolValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDialogueFlag), &Z_Construct_UClass_UDialogueFlag_Statics::NewProp_BoolValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoolValue_MetaData), NewProp_BoolValue_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UDialogueFlag_Statics::NewProp_IntValue = { "IntValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueFlag, IntValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IntValue_MetaData), NewProp_IntValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDialogueFlag_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueFlag_Statics::NewProp_FlagName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueFlag_Statics::NewProp_FlagDescription,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueFlag_Statics::NewProp_FlagType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueFlag_Statics::NewProp_FlagType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueFlag_Statics::NewProp_BoolValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueFlag_Statics::NewProp_IntValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueFlag_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UDialogueFlag_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_DialoguePlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueFlag_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueFlag_Statics::ClassParams = {
	&UDialogueFlag::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UDialogueFlag_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueFlag_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueFlag_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueFlag_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueFlag()
{
	if (!Z_Registration_Info_UClass_UDialogueFlag.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueFlag.OuterSingleton, Z_Construct_UClass_UDialogueFlag_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueFlag.OuterSingleton;
}
template<> DIALOGUEPLUGIN_API UClass* StaticClass<UDialogueFlag>()
{
	return UDialogueFlag::StaticClass();
}
UDialogueFlag::UDialogueFlag(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueFlag);
UDialogueFlag::~UDialogueFlag() {}
// End Class UDialogueFlag

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueFlag_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EFlagType_StaticEnum, TEXT("EFlagType"), &Z_Registration_Info_UEnum_EFlagType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3397836668U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueFlag, UDialogueFlag::StaticClass, TEXT("UDialogueFlag"), &Z_Registration_Info_UClass_UDialogueFlag, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueFlag), 1365016661U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueFlag_h_1642863307(TEXT("/Script/DialoguePlugin"),
	Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueFlag_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueFlag_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueFlag_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueFlag_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
