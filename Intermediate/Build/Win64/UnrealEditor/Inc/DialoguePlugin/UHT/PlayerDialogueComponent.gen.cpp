// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialoguePlugin/Public/Runtime/PlayerDialogueComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlayerDialogueComponent() {}

// Begin Cross Module References
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UDialogueResolver_NoRegister();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UPlayerDialogueComponent();
DIALOGUEPLUGIN_API UClass* Z_Construct_UClass_UPlayerDialogueComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UPackage* Z_Construct_UPackage__Script_DialoguePlugin();
// End Cross Module References

// Begin Class UPlayerDialogueComponent
void UPlayerDialogueComponent::StaticRegisterNativesUPlayerDialogueComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPlayerDialogueComponent);
UClass* Z_Construct_UClass_UPlayerDialogueComponent_NoRegister()
{
	return UPlayerDialogueComponent::StaticClass();
}
struct Z_Construct_UClass_UPlayerDialogueComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Runtime/PlayerDialogueComponent.h" },
		{ "ModuleRelativePath", "Public/Runtime/PlayerDialogueComponent.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPlayerDialogueComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UPlayerDialogueComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_DialoguePlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerDialogueComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UPlayerDialogueComponent_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UDialogueResolver_NoRegister, (int32)VTABLE_OFFSET(UPlayerDialogueComponent, IDialogueResolver), false },  // 1879952696
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPlayerDialogueComponent_Statics::ClassParams = {
	&UPlayerDialogueComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	UE_ARRAY_COUNT(InterfaceParams),
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerDialogueComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UPlayerDialogueComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UPlayerDialogueComponent()
{
	if (!Z_Registration_Info_UClass_UPlayerDialogueComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPlayerDialogueComponent.OuterSingleton, Z_Construct_UClass_UPlayerDialogueComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPlayerDialogueComponent.OuterSingleton;
}
template<> DIALOGUEPLUGIN_API UClass* StaticClass<UPlayerDialogueComponent>()
{
	return UPlayerDialogueComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UPlayerDialogueComponent);
UPlayerDialogueComponent::~UPlayerDialogueComponent() {}
// End Class UPlayerDialogueComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Runtime_PlayerDialogueComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPlayerDialogueComponent, UPlayerDialogueComponent::StaticClass, TEXT("UPlayerDialogueComponent"), &Z_Registration_Info_UClass_UPlayerDialogueComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPlayerDialogueComponent), 3241160400U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Runtime_PlayerDialogueComponent_h_2878202202(TEXT("/Script/DialoguePlugin"),
	Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Runtime_PlayerDialogueComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Runtime_PlayerDialogueComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
