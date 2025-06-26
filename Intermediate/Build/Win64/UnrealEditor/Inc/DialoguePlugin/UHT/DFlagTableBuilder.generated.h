// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Editor/DFlagTableBuilder.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef DIALOGUEPLUGIN_DFlagTableBuilder_generated_h
#error "DFlagTableBuilder.generated.h already included, missing '#pragma once' in DFlagTableBuilder.h"
#endif
#define DIALOGUEPLUGIN_DFlagTableBuilder_generated_h

#define FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Editor_DFlagTableBuilder_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execBuildGlobalFlagTable);


#define FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Editor_DFlagTableBuilder_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDFlagTableBuilder(); \
	friend struct Z_Construct_UClass_UDFlagTableBuilder_Statics; \
public: \
	DECLARE_CLASS(UDFlagTableBuilder, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DialoguePlugin"), NO_API) \
	DECLARE_SERIALIZER(UDFlagTableBuilder)


#define FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Editor_DFlagTableBuilder_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDFlagTableBuilder(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UDFlagTableBuilder(UDFlagTableBuilder&&); \
	UDFlagTableBuilder(const UDFlagTableBuilder&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDFlagTableBuilder); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDFlagTableBuilder); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDFlagTableBuilder) \
	NO_API virtual ~UDFlagTableBuilder();


#define FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Editor_DFlagTableBuilder_h_12_PROLOG
#define FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Editor_DFlagTableBuilder_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Editor_DFlagTableBuilder_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Editor_DFlagTableBuilder_h_15_INCLASS_NO_PURE_DECLS \
	FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Editor_DFlagTableBuilder_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> DIALOGUEPLUGIN_API UClass* StaticClass<class UDFlagTableBuilder>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Editor_DFlagTableBuilder_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
