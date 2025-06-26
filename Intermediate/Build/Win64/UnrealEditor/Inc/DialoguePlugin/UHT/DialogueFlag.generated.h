// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DialogueFlag.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef DIALOGUEPLUGIN_DialogueFlag_generated_h
#error "DialogueFlag.generated.h already included, missing '#pragma once' in DialogueFlag.h"
#endif
#define DIALOGUEPLUGIN_DialogueFlag_generated_h

#define FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueFlag_h_25_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDialogueFlag(); \
	friend struct Z_Construct_UClass_UDialogueFlag_Statics; \
public: \
	DECLARE_CLASS(UDialogueFlag, UDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DialoguePlugin"), NO_API) \
	DECLARE_SERIALIZER(UDialogueFlag)


#define FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueFlag_h_25_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDialogueFlag(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UDialogueFlag(UDialogueFlag&&); \
	UDialogueFlag(const UDialogueFlag&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDialogueFlag); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDialogueFlag); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDialogueFlag) \
	NO_API virtual ~UDialogueFlag();


#define FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueFlag_h_22_PROLOG
#define FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueFlag_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueFlag_h_25_INCLASS_NO_PURE_DECLS \
	FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueFlag_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> DIALOGUEPLUGIN_API UClass* StaticClass<class UDialogueFlag>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueFlag_h


#define FOREACH_ENUM_EFLAGTYPE(op) \
	op(EFlagType::Boolean) \
	op(EFlagType::Numeric) 

enum class EFlagType : uint8;
template<> struct TIsUEnumClass<EFlagType> { enum { Value = true }; };
template<> DIALOGUEPLUGIN_API UEnum* StaticEnum<EFlagType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
