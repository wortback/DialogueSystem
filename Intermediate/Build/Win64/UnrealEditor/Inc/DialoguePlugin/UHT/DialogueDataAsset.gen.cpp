// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialoguePlugin/Public/DialogueDataAsset.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDialogueDataAsset() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UCondTreeWrapper_NoRegister();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueBranch();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueBranch_NoRegister();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueChoice();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueChoice_NoRegister();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueDataAsset();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueDataAsset_NoRegister();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueFlagSet();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueFlagSet_NoRegister();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueFork();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueFork_NoRegister();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueGotoNode();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueGotoNode_NoRegister();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueNodeBase();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueNodeBase_NoRegister();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueNodeLinkable();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueNodeLinkable_NoRegister();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueSentence();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueSentence_NoRegister();
DIALOGUEPLUGIN_API UEnum* Z_Construct_UEnum_DialoguePlugin_EFlagCompSymbol();
DIALOGUEPLUGIN_API UEnum* Z_Construct_UEnum_DialoguePlugin_EFlagOperator();
DIALOGUEPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FBranchWithCondition();
DIALOGUEPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FDialogueChoiceOption();
DIALOGUEPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FFlagCondition();
DIALOGUEPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FFlagEffect();
ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
UPackage* Z_Construct_UPackage__Script_DialoguePlugin();
// End Cross Module References

// Begin ScriptStruct FFlagCondition
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FlagCondition;
class UScriptStruct* FFlagCondition::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FlagCondition.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FlagCondition.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FFlagCondition, (UObject*)Z_Construct_UPackage__Script_DialoguePlugin(), TEXT("FlagCondition"));
	}
	return Z_Registration_Info_UScriptStruct_FlagCondition.OuterSingleton;
}
template<> DIALOGUEPLUGIN_API UScriptStruct* StaticStruct<FFlagCondition>()
{
	return FFlagCondition::StaticStruct();
}
struct Z_Construct_UScriptStruct_FFlagCondition_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FlagName_MetaData[] = {
		{ "Category", "FlagCondition" },
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ComparisonSymbol_MetaData[] = {
		{ "Category", "FlagCondition" },
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IntValue_MetaData[] = {
		{ "Category", "FlagCondition" },
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoolValue_MetaData[] = {
		{ "Category", "FlagCondition" },
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_FlagName;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ComparisonSymbol_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ComparisonSymbol;
	static const UECodeGen_Private::FIntPropertyParams NewProp_IntValue;
	static void NewProp_BoolValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_BoolValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFlagCondition>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FFlagCondition_Statics::NewProp_FlagName = { "FlagName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFlagCondition, FlagName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FlagName_MetaData), NewProp_FlagName_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FFlagCondition_Statics::NewProp_ComparisonSymbol_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FFlagCondition_Statics::NewProp_ComparisonSymbol = { "ComparisonSymbol", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFlagCondition, ComparisonSymbol), Z_Construct_UEnum_DialoguePlugin_EFlagCompSymbol, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ComparisonSymbol_MetaData), NewProp_ComparisonSymbol_MetaData) }; // 590433254
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FFlagCondition_Statics::NewProp_IntValue = { "IntValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFlagCondition, IntValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IntValue_MetaData), NewProp_IntValue_MetaData) };
void Z_Construct_UScriptStruct_FFlagCondition_Statics::NewProp_BoolValue_SetBit(void* Obj)
{
	((FFlagCondition*)Obj)->BoolValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FFlagCondition_Statics::NewProp_BoolValue = { "BoolValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FFlagCondition), &Z_Construct_UScriptStruct_FFlagCondition_Statics::NewProp_BoolValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoolValue_MetaData), NewProp_BoolValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FFlagCondition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFlagCondition_Statics::NewProp_FlagName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFlagCondition_Statics::NewProp_ComparisonSymbol_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFlagCondition_Statics::NewProp_ComparisonSymbol,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFlagCondition_Statics::NewProp_IntValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFlagCondition_Statics::NewProp_BoolValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFlagCondition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFlagCondition_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_DialoguePlugin,
	nullptr,
	&NewStructOps,
	"FlagCondition",
	Z_Construct_UScriptStruct_FFlagCondition_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFlagCondition_Statics::PropPointers),
	sizeof(FFlagCondition),
	alignof(FFlagCondition),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFlagCondition_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FFlagCondition_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FFlagCondition()
{
	if (!Z_Registration_Info_UScriptStruct_FlagCondition.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FlagCondition.InnerSingleton, Z_Construct_UScriptStruct_FFlagCondition_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FlagCondition.InnerSingleton;
}
// End ScriptStruct FFlagCondition

// Begin ScriptStruct FFlagEffect
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FlagEffect;
class UScriptStruct* FFlagEffect::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FlagEffect.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FlagEffect.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FFlagEffect, (UObject*)Z_Construct_UPackage__Script_DialoguePlugin(), TEXT("FlagEffect"));
	}
	return Z_Registration_Info_UScriptStruct_FlagEffect.OuterSingleton;
}
template<> DIALOGUEPLUGIN_API UScriptStruct* StaticStruct<FFlagEffect>()
{
	return FFlagEffect::StaticStruct();
}
struct Z_Construct_UScriptStruct_FFlagEffect_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FlagName_MetaData[] = {
		{ "Category", "FlagEffect" },
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Operator_MetaData[] = {
		{ "Category", "FlagEffect" },
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IntValue_MetaData[] = {
		{ "Category", "FlagEffect" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Value to be added/subtracted/set (depending on the operator) from the value in the flag */" },
#endif
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Value to be added/subtracted/set (depending on the operator) from the value in the flag" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoolValue_MetaData[] = {
		{ "Category", "FlagEffect" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Value the bool flag is gonna be set to */" },
#endif
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Value the bool flag is gonna be set to" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_FlagName;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Operator_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Operator;
	static const UECodeGen_Private::FIntPropertyParams NewProp_IntValue;
	static void NewProp_BoolValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_BoolValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFlagEffect>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FFlagEffect_Statics::NewProp_FlagName = { "FlagName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFlagEffect, FlagName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FlagName_MetaData), NewProp_FlagName_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FFlagEffect_Statics::NewProp_Operator_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FFlagEffect_Statics::NewProp_Operator = { "Operator", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFlagEffect, Operator), Z_Construct_UEnum_DialoguePlugin_EFlagOperator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Operator_MetaData), NewProp_Operator_MetaData) }; // 761068580
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FFlagEffect_Statics::NewProp_IntValue = { "IntValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFlagEffect, IntValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IntValue_MetaData), NewProp_IntValue_MetaData) };
void Z_Construct_UScriptStruct_FFlagEffect_Statics::NewProp_BoolValue_SetBit(void* Obj)
{
	((FFlagEffect*)Obj)->BoolValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FFlagEffect_Statics::NewProp_BoolValue = { "BoolValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FFlagEffect), &Z_Construct_UScriptStruct_FFlagEffect_Statics::NewProp_BoolValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoolValue_MetaData), NewProp_BoolValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FFlagEffect_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFlagEffect_Statics::NewProp_FlagName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFlagEffect_Statics::NewProp_Operator_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFlagEffect_Statics::NewProp_Operator,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFlagEffect_Statics::NewProp_IntValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFlagEffect_Statics::NewProp_BoolValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFlagEffect_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFlagEffect_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_DialoguePlugin,
	nullptr,
	&NewStructOps,
	"FlagEffect",
	Z_Construct_UScriptStruct_FFlagEffect_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFlagEffect_Statics::PropPointers),
	sizeof(FFlagEffect),
	alignof(FFlagEffect),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFlagEffect_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FFlagEffect_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FFlagEffect()
{
	if (!Z_Registration_Info_UScriptStruct_FlagEffect.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FlagEffect.InnerSingleton, Z_Construct_UScriptStruct_FFlagEffect_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FlagEffect.InnerSingleton;
}
// End ScriptStruct FFlagEffect

// Begin Class UDialogueNodeBase
void UDialogueNodeBase::StaticRegisterNativesUDialogueNodeBase()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDialogueNodeBase);
UClass* Z_Construct_UClass_UDialogueNodeBase_NoRegister()
{
	return UDialogueNodeBase::StaticClass();
}
struct Z_Construct_UClass_UDialogueNodeBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DialogueDataAsset.h" },
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ID_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_ID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueNodeBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UDialogueNodeBase_Statics::NewProp_ID = { "ID", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueNodeBase, ID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ID_MetaData), NewProp_ID_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDialogueNodeBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueNodeBase_Statics::NewProp_ID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueNodeBase_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UDialogueNodeBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_DialoguePlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueNodeBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueNodeBase_Statics::ClassParams = {
	&UDialogueNodeBase::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UDialogueNodeBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueNodeBase_Statics::PropPointers),
	0,
	0x000000A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueNodeBase_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueNodeBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueNodeBase()
{
	if (!Z_Registration_Info_UClass_UDialogueNodeBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueNodeBase.OuterSingleton, Z_Construct_UClass_UDialogueNodeBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueNodeBase.OuterSingleton;
}
template<> DIALOGUEPLUGIN_API UClass* StaticClass<UDialogueNodeBase>()
{
	return UDialogueNodeBase::StaticClass();
}
UDialogueNodeBase::UDialogueNodeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueNodeBase);
UDialogueNodeBase::~UDialogueNodeBase() {}
// End Class UDialogueNodeBase

// Begin Class UDialogueNodeLinkable
void UDialogueNodeLinkable::StaticRegisterNativesUDialogueNodeLinkable()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDialogueNodeLinkable);
UClass* Z_Construct_UClass_UDialogueNodeLinkable_NoRegister()
{
	return UDialogueNodeLinkable::StaticClass();
}
struct Z_Construct_UClass_UDialogueNodeLinkable_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DialogueDataAsset.h" },
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NextID_MetaData[] = {
		{ "Category", "Dialogue" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** ID of the next node to jump to */" },
#endif
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "ID of the next node to jump to" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_NextID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueNodeLinkable>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UDialogueNodeLinkable_Statics::NewProp_NextID = { "NextID", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueNodeLinkable, NextID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NextID_MetaData), NewProp_NextID_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDialogueNodeLinkable_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueNodeLinkable_Statics::NewProp_NextID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueNodeLinkable_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UDialogueNodeLinkable_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDialogueNodeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_DialoguePlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueNodeLinkable_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueNodeLinkable_Statics::ClassParams = {
	&UDialogueNodeLinkable::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UDialogueNodeLinkable_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueNodeLinkable_Statics::PropPointers),
	0,
	0x000000A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueNodeLinkable_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueNodeLinkable_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueNodeLinkable()
{
	if (!Z_Registration_Info_UClass_UDialogueNodeLinkable.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueNodeLinkable.OuterSingleton, Z_Construct_UClass_UDialogueNodeLinkable_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueNodeLinkable.OuterSingleton;
}
template<> DIALOGUEPLUGIN_API UClass* StaticClass<UDialogueNodeLinkable>()
{
	return UDialogueNodeLinkable::StaticClass();
}
UDialogueNodeLinkable::UDialogueNodeLinkable(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueNodeLinkable);
UDialogueNodeLinkable::~UDialogueNodeLinkable() {}
// End Class UDialogueNodeLinkable

// Begin Class UDialogueFlagSet
void UDialogueFlagSet::StaticRegisterNativesUDialogueFlagSet()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDialogueFlagSet);
UClass* Z_Construct_UClass_UDialogueFlagSet_NoRegister()
{
	return UDialogueFlagSet::StaticClass();
}
struct Z_Construct_UClass_UDialogueFlagSet_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "DialogueDataAsset.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FlagEffect_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_FlagEffect;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueFlagSet>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDialogueFlagSet_Statics::NewProp_FlagEffect = { "FlagEffect", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueFlagSet, FlagEffect), Z_Construct_UScriptStruct_FFlagEffect, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FlagEffect_MetaData), NewProp_FlagEffect_MetaData) }; // 2558471645
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDialogueFlagSet_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueFlagSet_Statics::NewProp_FlagEffect,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueFlagSet_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UDialogueFlagSet_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDialogueNodeLinkable,
	(UObject* (*)())Z_Construct_UPackage__Script_DialoguePlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueFlagSet_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueFlagSet_Statics::ClassParams = {
	&UDialogueFlagSet::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UDialogueFlagSet_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueFlagSet_Statics::PropPointers),
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueFlagSet_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueFlagSet_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueFlagSet()
{
	if (!Z_Registration_Info_UClass_UDialogueFlagSet.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueFlagSet.OuterSingleton, Z_Construct_UClass_UDialogueFlagSet_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueFlagSet.OuterSingleton;
}
template<> DIALOGUEPLUGIN_API UClass* StaticClass<UDialogueFlagSet>()
{
	return UDialogueFlagSet::StaticClass();
}
UDialogueFlagSet::UDialogueFlagSet(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueFlagSet);
UDialogueFlagSet::~UDialogueFlagSet() {}
// End Class UDialogueFlagSet

// Begin Class UDialogueGotoNode
void UDialogueGotoNode::StaticRegisterNativesUDialogueGotoNode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDialogueGotoNode);
UClass* Z_Construct_UClass_UDialogueGotoNode_NoRegister()
{
	return UDialogueGotoNode::StaticClass();
}
struct Z_Construct_UClass_UDialogueGotoNode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "DialogueDataAsset.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueGotoNode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UDialogueGotoNode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDialogueNodeLinkable,
	(UObject* (*)())Z_Construct_UPackage__Script_DialoguePlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGotoNode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueGotoNode_Statics::ClassParams = {
	&UDialogueGotoNode::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueGotoNode_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueGotoNode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueGotoNode()
{
	if (!Z_Registration_Info_UClass_UDialogueGotoNode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueGotoNode.OuterSingleton, Z_Construct_UClass_UDialogueGotoNode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueGotoNode.OuterSingleton;
}
template<> DIALOGUEPLUGIN_API UClass* StaticClass<UDialogueGotoNode>()
{
	return UDialogueGotoNode::StaticClass();
}
UDialogueGotoNode::UDialogueGotoNode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueGotoNode);
UDialogueGotoNode::~UDialogueGotoNode() {}
// End Class UDialogueGotoNode

// Begin Class UDialogueSentence
void UDialogueSentence::StaticRegisterNativesUDialogueSentence()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDialogueSentence);
UClass* Z_Construct_UClass_UDialogueSentence_NoRegister()
{
	return UDialogueSentence::StaticClass();
}
struct Z_Construct_UClass_UDialogueSentence_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "DialogueDataAsset.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Speaker_MetaData[] = {
		{ "Category", "Dialogue" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Speaker name to be displayed */" },
#endif
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Speaker name to be displayed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
		{ "Category", "Dialogue" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** What the speaker is currently saying */" },
#endif
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "What the speaker is currently saying" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Speaker;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Text;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueSentence>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UDialogueSentence_Statics::NewProp_Speaker = { "Speaker", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSentence, Speaker), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Speaker_MetaData), NewProp_Speaker_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UDialogueSentence_Statics::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSentence, Text), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_MetaData), NewProp_Text_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDialogueSentence_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSentence_Statics::NewProp_Speaker,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSentence_Statics::NewProp_Text,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueSentence_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UDialogueSentence_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDialogueNodeLinkable,
	(UObject* (*)())Z_Construct_UPackage__Script_DialoguePlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueSentence_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueSentence_Statics::ClassParams = {
	&UDialogueSentence::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UDialogueSentence_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueSentence_Statics::PropPointers),
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueSentence_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueSentence_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueSentence()
{
	if (!Z_Registration_Info_UClass_UDialogueSentence.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueSentence.OuterSingleton, Z_Construct_UClass_UDialogueSentence_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueSentence.OuterSingleton;
}
template<> DIALOGUEPLUGIN_API UClass* StaticClass<UDialogueSentence>()
{
	return UDialogueSentence::StaticClass();
}
UDialogueSentence::UDialogueSentence(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueSentence);
UDialogueSentence::~UDialogueSentence() {}
// End Class UDialogueSentence

// Begin Class UDialogueBranch
void UDialogueBranch::StaticRegisterNativesUDialogueBranch()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDialogueBranch);
UClass* Z_Construct_UClass_UDialogueBranch_NoRegister()
{
	return UDialogueBranch::StaticClass();
}
struct Z_Construct_UClass_UDialogueBranch_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * A single conditional path evaluated during a fork.\n * If RequiredFlagState is satisfied, this branch is chosen and FirstID is used to enter its Content map.\n */" },
#endif
		{ "IncludePath", "DialogueDataAsset.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A single conditional path evaluated during a fork.\nIf RequiredFlagState is satisfied, this branch is chosen and FirstID is used to enter its Content map." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Content_ValueProp_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Content_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FirstID_MetaData[] = {
		{ "Category", "Dialogue" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** ID of the first node in the content map to jump to */" },
#endif
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "ID of the first node in the content map to jump to" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Content_ValueProp;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Content_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_Content;
	static const UECodeGen_Private::FNamePropertyParams NewProp_FirstID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueBranch>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDialogueBranch_Statics::NewProp_Content_ValueProp = { "Content", nullptr, (EPropertyFlags)0x0002000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UDialogueNodeBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Content_ValueProp_MetaData), NewProp_Content_ValueProp_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UDialogueBranch_Statics::NewProp_Content_Key_KeyProp = { "Content_Key", nullptr, (EPropertyFlags)0x0002000000080009, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UDialogueBranch_Statics::NewProp_Content = { "Content", nullptr, (EPropertyFlags)0x001000800000001d, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueBranch, Content), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Content_MetaData), NewProp_Content_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UDialogueBranch_Statics::NewProp_FirstID = { "FirstID", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueBranch, FirstID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FirstID_MetaData), NewProp_FirstID_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDialogueBranch_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueBranch_Statics::NewProp_Content_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueBranch_Statics::NewProp_Content_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueBranch_Statics::NewProp_Content,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueBranch_Statics::NewProp_FirstID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueBranch_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UDialogueBranch_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDialogueNodeLinkable,
	(UObject* (*)())Z_Construct_UPackage__Script_DialoguePlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueBranch_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueBranch_Statics::ClassParams = {
	&UDialogueBranch::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UDialogueBranch_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueBranch_Statics::PropPointers),
	0,
	0x008000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueBranch_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueBranch_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueBranch()
{
	if (!Z_Registration_Info_UClass_UDialogueBranch.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueBranch.OuterSingleton, Z_Construct_UClass_UDialogueBranch_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueBranch.OuterSingleton;
}
template<> DIALOGUEPLUGIN_API UClass* StaticClass<UDialogueBranch>()
{
	return UDialogueBranch::StaticClass();
}
UDialogueBranch::UDialogueBranch(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueBranch);
UDialogueBranch::~UDialogueBranch() {}
// End Class UDialogueBranch

// Begin ScriptStruct FDialogueChoiceOption
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_DialogueChoiceOption;
class UScriptStruct* FDialogueChoiceOption::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_DialogueChoiceOption.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_DialogueChoiceOption.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDialogueChoiceOption, (UObject*)Z_Construct_UPackage__Script_DialoguePlugin(), TEXT("DialogueChoiceOption"));
	}
	return Z_Registration_Info_UScriptStruct_DialogueChoiceOption.OuterSingleton;
}
template<> DIALOGUEPLUGIN_API UScriptStruct* StaticStruct<FDialogueChoiceOption>()
{
	return FDialogueChoiceOption::StaticStruct();
}
struct Z_Construct_UScriptStruct_FDialogueChoiceOption_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
		{ "Category", "Choice Option" },
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AffectedFlags_MetaData[] = {
		{ "Category", "Choice Option" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Flags that will change state after this response is selected */" },
#endif
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Flags that will change state after this response is selected" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TreeWrapper_MetaData[] = {
		{ "Category", "DialogueChoiceOption" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Tree object for complex conditions */" },
#endif
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Tree object for complex conditions" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GotoID_MetaData[] = {
		{ "Category", "Choice Option" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** opt. Jumps to the ID is this choice is selected */" },
#endif
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "opt. Jumps to the ID is this choice is selected" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Text;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AffectedFlags_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_AffectedFlags;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TreeWrapper;
	static const UECodeGen_Private::FNamePropertyParams NewProp_GotoID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDialogueChoiceOption>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDialogueChoiceOption_Statics::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueChoiceOption, Text), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_MetaData), NewProp_Text_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDialogueChoiceOption_Statics::NewProp_AffectedFlags_Inner = { "AffectedFlags", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FFlagEffect, METADATA_PARAMS(0, nullptr) }; // 2558471645
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FDialogueChoiceOption_Statics::NewProp_AffectedFlags = { "AffectedFlags", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueChoiceOption, AffectedFlags), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AffectedFlags_MetaData), NewProp_AffectedFlags_MetaData) }; // 2558471645
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FDialogueChoiceOption_Statics::NewProp_TreeWrapper = { "TreeWrapper", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueChoiceOption, TreeWrapper), Z_Construct_UClass_UCondTreeWrapper_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TreeWrapper_MetaData), NewProp_TreeWrapper_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FDialogueChoiceOption_Statics::NewProp_GotoID = { "GotoID", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueChoiceOption, GotoID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GotoID_MetaData), NewProp_GotoID_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDialogueChoiceOption_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueChoiceOption_Statics::NewProp_Text,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueChoiceOption_Statics::NewProp_AffectedFlags_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueChoiceOption_Statics::NewProp_AffectedFlags,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueChoiceOption_Statics::NewProp_TreeWrapper,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueChoiceOption_Statics::NewProp_GotoID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueChoiceOption_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDialogueChoiceOption_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_DialoguePlugin,
	nullptr,
	&NewStructOps,
	"DialogueChoiceOption",
	Z_Construct_UScriptStruct_FDialogueChoiceOption_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueChoiceOption_Statics::PropPointers),
	sizeof(FDialogueChoiceOption),
	alignof(FDialogueChoiceOption),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueChoiceOption_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDialogueChoiceOption_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDialogueChoiceOption()
{
	if (!Z_Registration_Info_UScriptStruct_DialogueChoiceOption.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_DialogueChoiceOption.InnerSingleton, Z_Construct_UScriptStruct_FDialogueChoiceOption_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_DialogueChoiceOption.InnerSingleton;
}
// End ScriptStruct FDialogueChoiceOption

// Begin Class UDialogueChoice
void UDialogueChoice::StaticRegisterNativesUDialogueChoice()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDialogueChoice);
UClass* Z_Construct_UClass_UDialogueChoice_NoRegister()
{
	return UDialogueChoice::StaticClass();
}
struct Z_Construct_UClass_UDialogueChoice_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "DialogueDataAsset.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Options_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Options_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Options;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueChoice>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDialogueChoice_Statics::NewProp_Options_Inner = { "Options", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDialogueChoiceOption, METADATA_PARAMS(0, nullptr) }; // 1893498849
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UDialogueChoice_Statics::NewProp_Options = { "Options", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueChoice, Options), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Options_MetaData), NewProp_Options_MetaData) }; // 1893498849
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDialogueChoice_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueChoice_Statics::NewProp_Options_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueChoice_Statics::NewProp_Options,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueChoice_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UDialogueChoice_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDialogueNodeLinkable,
	(UObject* (*)())Z_Construct_UPackage__Script_DialoguePlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueChoice_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueChoice_Statics::ClassParams = {
	&UDialogueChoice::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UDialogueChoice_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueChoice_Statics::PropPointers),
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueChoice_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueChoice_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueChoice()
{
	if (!Z_Registration_Info_UClass_UDialogueChoice.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueChoice.OuterSingleton, Z_Construct_UClass_UDialogueChoice_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueChoice.OuterSingleton;
}
template<> DIALOGUEPLUGIN_API UClass* StaticClass<UDialogueChoice>()
{
	return UDialogueChoice::StaticClass();
}
UDialogueChoice::UDialogueChoice(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueChoice);
UDialogueChoice::~UDialogueChoice() {}
// End Class UDialogueChoice

// Begin ScriptStruct FBranchWithCondition
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_BranchWithCondition;
class UScriptStruct* FBranchWithCondition::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_BranchWithCondition.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_BranchWithCondition.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FBranchWithCondition, (UObject*)Z_Construct_UPackage__Script_DialoguePlugin(), TEXT("BranchWithCondition"));
	}
	return Z_Registration_Info_UScriptStruct_BranchWithCondition.OuterSingleton;
}
template<> DIALOGUEPLUGIN_API UScriptStruct* StaticStruct<FBranchWithCondition>()
{
	return FBranchWithCondition::StaticStruct();
}
struct Z_Construct_UScriptStruct_FBranchWithCondition_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TreeWrapper_MetaData[] = {
		{ "Category", "BranchWithCondition" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Tree object for complex conditions */" },
#endif
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Tree object for complex conditions" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Branch_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TreeWrapper;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Branch;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FBranchWithCondition>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FBranchWithCondition_Statics::NewProp_TreeWrapper = { "TreeWrapper", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBranchWithCondition, TreeWrapper), Z_Construct_UClass_UCondTreeWrapper_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TreeWrapper_MetaData), NewProp_TreeWrapper_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FBranchWithCondition_Statics::NewProp_Branch = { "Branch", nullptr, (EPropertyFlags)0x001200000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBranchWithCondition, Branch), Z_Construct_UClass_UDialogueBranch_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Branch_MetaData), NewProp_Branch_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FBranchWithCondition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBranchWithCondition_Statics::NewProp_TreeWrapper,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBranchWithCondition_Statics::NewProp_Branch,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBranchWithCondition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FBranchWithCondition_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_DialoguePlugin,
	nullptr,
	&NewStructOps,
	"BranchWithCondition",
	Z_Construct_UScriptStruct_FBranchWithCondition_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBranchWithCondition_Statics::PropPointers),
	sizeof(FBranchWithCondition),
	alignof(FBranchWithCondition),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000005),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBranchWithCondition_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FBranchWithCondition_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FBranchWithCondition()
{
	if (!Z_Registration_Info_UScriptStruct_BranchWithCondition.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_BranchWithCondition.InnerSingleton, Z_Construct_UScriptStruct_FBranchWithCondition_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_BranchWithCondition.InnerSingleton;
}
// End ScriptStruct FBranchWithCondition

// Begin Class UDialogueFork
void UDialogueFork::StaticRegisterNativesUDialogueFork()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDialogueFork);
UClass* Z_Construct_UClass_UDialogueFork_NoRegister()
{
	return UDialogueFork::StaticClass();
}
struct Z_Construct_UClass_UDialogueFork_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** * A node that contains multiple if/else-branches, each with its own condition.\n * The conditions are evaluated in order, and the first one that matches is executed.\n * If no conditions match, the last branch (if any) is executed as an \"else\" case.\n */" },
#endif
		{ "IncludePath", "DialogueDataAsset.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A node that contains multiple if/else-branches, each with its own condition.\nThe conditions are evaluated in order, and the first one that matches is executed.\nIf no conditions match, the last branch (if any) is executed as an \"else\" case." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NestingLevel_MetaData[] = {
		{ "Category", "Nesting" },
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Branches_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_NestingLevel;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Branches_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Branches;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueFork>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UDialogueFork_Statics::NewProp_NestingLevel = { "NestingLevel", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueFork, NestingLevel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NestingLevel_MetaData), NewProp_NestingLevel_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDialogueFork_Statics::NewProp_Branches_Inner = { "Branches", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FBranchWithCondition, METADATA_PARAMS(0, nullptr) }; // 4088266830
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UDialogueFork_Statics::NewProp_Branches = { "Branches", nullptr, (EPropertyFlags)0x0010008000000015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueFork, Branches), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Branches_MetaData), NewProp_Branches_MetaData) }; // 4088266830
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDialogueFork_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueFork_Statics::NewProp_NestingLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueFork_Statics::NewProp_Branches_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueFork_Statics::NewProp_Branches,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueFork_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UDialogueFork_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDialogueNodeLinkable,
	(UObject* (*)())Z_Construct_UPackage__Script_DialoguePlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueFork_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueFork_Statics::ClassParams = {
	&UDialogueFork::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UDialogueFork_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueFork_Statics::PropPointers),
	0,
	0x008000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueFork_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueFork_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueFork()
{
	if (!Z_Registration_Info_UClass_UDialogueFork.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueFork.OuterSingleton, Z_Construct_UClass_UDialogueFork_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueFork.OuterSingleton;
}
template<> DIALOGUEPLUGIN_API UClass* StaticClass<UDialogueFork>()
{
	return UDialogueFork::StaticClass();
}
UDialogueFork::UDialogueFork(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueFork);
UDialogueFork::~UDialogueFork() {}
// End Class UDialogueFork

// Begin Class UDialogueDataAsset
void UDialogueDataAsset::StaticRegisterNativesUDialogueDataAsset()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDialogueDataAsset);
UClass* Z_Construct_UClass_UDialogueDataAsset_NoRegister()
{
	return UDialogueDataAsset::StaticClass();
}
struct Z_Construct_UClass_UDialogueDataAsset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *\n */" },
#endif
		{ "IncludePath", "DialogueDataAsset.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DialogueName_MetaData[] = {
		{ "Category", "DialogueDataAsset" },
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DialogueMap_ValueProp_MetaData[] = {
		{ "Category", "DialogueDataAsset" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DialogueMap_MetaData[] = {
		{ "Category", "DialogueDataAsset" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueDataAsset.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_DialogueName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DialogueMap_ValueProp;
	static const UECodeGen_Private::FNamePropertyParams NewProp_DialogueMap_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_DialogueMap;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueDataAsset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UDialogueDataAsset_Statics::NewProp_DialogueName = { "DialogueName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueDataAsset, DialogueName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DialogueName_MetaData), NewProp_DialogueName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDialogueDataAsset_Statics::NewProp_DialogueMap_ValueProp = { "DialogueMap", nullptr, (EPropertyFlags)0x0106000000080009, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UDialogueNodeBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DialogueMap_ValueProp_MetaData), NewProp_DialogueMap_ValueProp_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UDialogueDataAsset_Statics::NewProp_DialogueMap_Key_KeyProp = { "DialogueMap_Key", nullptr, (EPropertyFlags)0x0102000000080009, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UDialogueDataAsset_Statics::NewProp_DialogueMap = { "DialogueMap", nullptr, (EPropertyFlags)0x011400800000001d, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueDataAsset, DialogueMap), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DialogueMap_MetaData), NewProp_DialogueMap_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDialogueDataAsset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueDataAsset_Statics::NewProp_DialogueName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueDataAsset_Statics::NewProp_DialogueMap_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueDataAsset_Statics::NewProp_DialogueMap_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueDataAsset_Statics::NewProp_DialogueMap,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueDataAsset_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UDialogueDataAsset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_DialoguePlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueDataAsset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueDataAsset_Statics::ClassParams = {
	&UDialogueDataAsset::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UDialogueDataAsset_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueDataAsset_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueDataAsset_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueDataAsset_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueDataAsset()
{
	if (!Z_Registration_Info_UClass_UDialogueDataAsset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueDataAsset.OuterSingleton, Z_Construct_UClass_UDialogueDataAsset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueDataAsset.OuterSingleton;
}
template<> DIALOGUEPLUGIN_API UClass* StaticClass<UDialogueDataAsset>()
{
	return UDialogueDataAsset::StaticClass();
}
UDialogueDataAsset::UDialogueDataAsset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueDataAsset);
UDialogueDataAsset::~UDialogueDataAsset() {}
// End Class UDialogueDataAsset

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueDataAsset_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FFlagCondition::StaticStruct, Z_Construct_UScriptStruct_FFlagCondition_Statics::NewStructOps, TEXT("FlagCondition"), &Z_Registration_Info_UScriptStruct_FlagCondition, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FFlagCondition), 966454006U) },
		{ FFlagEffect::StaticStruct, Z_Construct_UScriptStruct_FFlagEffect_Statics::NewStructOps, TEXT("FlagEffect"), &Z_Registration_Info_UScriptStruct_FlagEffect, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FFlagEffect), 2558471645U) },
		{ FDialogueChoiceOption::StaticStruct, Z_Construct_UScriptStruct_FDialogueChoiceOption_Statics::NewStructOps, TEXT("DialogueChoiceOption"), &Z_Registration_Info_UScriptStruct_DialogueChoiceOption, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDialogueChoiceOption), 1893498849U) },
		{ FBranchWithCondition::StaticStruct, Z_Construct_UScriptStruct_FBranchWithCondition_Statics::NewStructOps, TEXT("BranchWithCondition"), &Z_Registration_Info_UScriptStruct_BranchWithCondition, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FBranchWithCondition), 4088266830U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueNodeBase, UDialogueNodeBase::StaticClass, TEXT("UDialogueNodeBase"), &Z_Registration_Info_UClass_UDialogueNodeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueNodeBase), 2963655953U) },
		{ Z_Construct_UClass_UDialogueNodeLinkable, UDialogueNodeLinkable::StaticClass, TEXT("UDialogueNodeLinkable"), &Z_Registration_Info_UClass_UDialogueNodeLinkable, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueNodeLinkable), 1493616399U) },
		{ Z_Construct_UClass_UDialogueFlagSet, UDialogueFlagSet::StaticClass, TEXT("UDialogueFlagSet"), &Z_Registration_Info_UClass_UDialogueFlagSet, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueFlagSet), 1870448418U) },
		{ Z_Construct_UClass_UDialogueGotoNode, UDialogueGotoNode::StaticClass, TEXT("UDialogueGotoNode"), &Z_Registration_Info_UClass_UDialogueGotoNode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueGotoNode), 2540344478U) },
		{ Z_Construct_UClass_UDialogueSentence, UDialogueSentence::StaticClass, TEXT("UDialogueSentence"), &Z_Registration_Info_UClass_UDialogueSentence, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueSentence), 1050976872U) },
		{ Z_Construct_UClass_UDialogueBranch, UDialogueBranch::StaticClass, TEXT("UDialogueBranch"), &Z_Registration_Info_UClass_UDialogueBranch, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueBranch), 2409763330U) },
		{ Z_Construct_UClass_UDialogueChoice, UDialogueChoice::StaticClass, TEXT("UDialogueChoice"), &Z_Registration_Info_UClass_UDialogueChoice, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueChoice), 1327653725U) },
		{ Z_Construct_UClass_UDialogueFork, UDialogueFork::StaticClass, TEXT("UDialogueFork"), &Z_Registration_Info_UClass_UDialogueFork, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueFork), 1148042708U) },
		{ Z_Construct_UClass_UDialogueDataAsset, UDialogueDataAsset::StaticClass, TEXT("UDialogueDataAsset"), &Z_Registration_Info_UClass_UDialogueDataAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueDataAsset), 1233863045U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueDataAsset_h_2501129714(TEXT("/Script/DialoguePlugin"),
	Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueDataAsset_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueDataAsset_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueDataAsset_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueDataAsset_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
