// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialoguePlugin/Public/Runtime/DialogueManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDialogueManager() {}

// Begin Cross Module References
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueDataAsset_NoRegister();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueManager();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueManager_NoRegister();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueUIManager_NoRegister();
DIALOGUEPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FDialogueRuntimeContext();
DIALOGUEPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FDisplayObject();
ENGINE_API UClass* Z_Construct_UClass_UWorldSubsystem();
UPackage* Z_Construct_UPackage__Script_DialoguePlugin();
// End Cross Module References

// Begin ScriptStruct FDisplayObject
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_DisplayObject;
class UScriptStruct* FDisplayObject::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_DisplayObject.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_DisplayObject.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDisplayObject, (UObject*)Z_Construct_UPackage__Script_DialoguePlugin(), TEXT("DisplayObject"));
	}
	return Z_Registration_Info_UScriptStruct_DisplayObject.OuterSingleton;
}
template<> DIALOGUEPLUGIN_API UScriptStruct* StaticStruct<FDisplayObject>()
{
	return FDisplayObject::StaticStruct();
}
struct Z_Construct_UScriptStruct_FDisplayObject_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Runtime/DialogueManager.h" },
	};
#endif // WITH_METADATA
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDisplayObject>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDisplayObject_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_DialoguePlugin,
	nullptr,
	&NewStructOps,
	"DisplayObject",
	nullptr,
	0,
	sizeof(FDisplayObject),
	alignof(FDisplayObject),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDisplayObject_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDisplayObject_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDisplayObject()
{
	if (!Z_Registration_Info_UScriptStruct_DisplayObject.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_DisplayObject.InnerSingleton, Z_Construct_UScriptStruct_FDisplayObject_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_DisplayObject.InnerSingleton;
}
// End ScriptStruct FDisplayObject

// Begin ScriptStruct FDialogueRuntimeContext
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_DialogueRuntimeContext;
class UScriptStruct* FDialogueRuntimeContext::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_DialogueRuntimeContext.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_DialogueRuntimeContext.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDialogueRuntimeContext, (UObject*)Z_Construct_UPackage__Script_DialoguePlugin(), TEXT("DialogueRuntimeContext"));
	}
	return Z_Registration_Info_UScriptStruct_DialogueRuntimeContext.OuterSingleton;
}
template<> DIALOGUEPLUGIN_API UScriptStruct* StaticStruct<FDialogueRuntimeContext>()
{
	return FDialogueRuntimeContext::StaticStruct();
}
struct Z_Construct_UScriptStruct_FDialogueRuntimeContext_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Runtime/DialogueManager.h" },
	};
#endif // WITH_METADATA
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDialogueRuntimeContext>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDialogueRuntimeContext_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_DialoguePlugin,
	nullptr,
	&NewStructOps,
	"DialogueRuntimeContext",
	nullptr,
	0,
	sizeof(FDialogueRuntimeContext),
	alignof(FDialogueRuntimeContext),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueRuntimeContext_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDialogueRuntimeContext_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDialogueRuntimeContext()
{
	if (!Z_Registration_Info_UScriptStruct_DialogueRuntimeContext.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_DialogueRuntimeContext.InnerSingleton, Z_Construct_UScriptStruct_FDialogueRuntimeContext_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_DialogueRuntimeContext.InnerSingleton;
}
// End ScriptStruct FDialogueRuntimeContext

// Begin Class UDialogueManager
void UDialogueManager::StaticRegisterNativesUDialogueManager()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDialogueManager);
UClass* Z_Construct_UClass_UDialogueManager_NoRegister()
{
	return UDialogueManager::StaticClass();
}
struct Z_Construct_UClass_UDialogueManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *\n */" },
#endif
		{ "IncludePath", "Runtime/DialogueManager.h" },
		{ "ModuleRelativePath", "Public/Runtime/DialogueManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentAsset_MetaData[] = {
		{ "ModuleRelativePath", "Public/Runtime/DialogueManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UIManager_MetaData[] = {
		{ "ModuleRelativePath", "Public/Runtime/DialogueManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentAsset;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UIManager;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDialogueManager_Statics::NewProp_CurrentAsset = { "CurrentAsset", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueManager, CurrentAsset), Z_Construct_UClass_UDialogueDataAsset_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentAsset_MetaData), NewProp_CurrentAsset_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDialogueManager_Statics::NewProp_UIManager = { "UIManager", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueManager, UIManager), Z_Construct_UClass_UDialogueUIManager_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UIManager_MetaData), NewProp_UIManager_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDialogueManager_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueManager_Statics::NewProp_CurrentAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueManager_Statics::NewProp_UIManager,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueManager_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UDialogueManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWorldSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_DialoguePlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueManager_Statics::ClassParams = {
	&UDialogueManager::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UDialogueManager_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueManager_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueManager_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDialogueManager()
{
	if (!Z_Registration_Info_UClass_UDialogueManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueManager.OuterSingleton, Z_Construct_UClass_UDialogueManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueManager.OuterSingleton;
}
template<> DIALOGUEPLUGIN_API UClass* StaticClass<UDialogueManager>()
{
	return UDialogueManager::StaticClass();
}
UDialogueManager::UDialogueManager() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueManager);
UDialogueManager::~UDialogueManager() {}
// End Class UDialogueManager

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Runtime_DialogueManager_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FDisplayObject::StaticStruct, Z_Construct_UScriptStruct_FDisplayObject_Statics::NewStructOps, TEXT("DisplayObject"), &Z_Registration_Info_UScriptStruct_DisplayObject, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDisplayObject), 688193568U) },
		{ FDialogueRuntimeContext::StaticStruct, Z_Construct_UScriptStruct_FDialogueRuntimeContext_Statics::NewStructOps, TEXT("DialogueRuntimeContext"), &Z_Registration_Info_UScriptStruct_DialogueRuntimeContext, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDialogueRuntimeContext), 2163726299U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueManager, UDialogueManager::StaticClass, TEXT("UDialogueManager"), &Z_Registration_Info_UClass_UDialogueManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueManager), 2350620755U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Runtime_DialogueManager_h_2781460141(TEXT("/Script/DialoguePlugin"),
	Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Runtime_DialogueManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Runtime_DialogueManager_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Runtime_DialogueManager_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Runtime_DialogueManager_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
