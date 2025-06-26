// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Runtime/DialogueResolver.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef DIALOGUEPLUGIN_DialogueResolver_generated_h
#error "DialogueResolver.generated.h already included, missing '#pragma once' in DialogueResolver.h"
#endif
#define DIALOGUEPLUGIN_DialogueResolver_generated_h

#define FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Runtime_DialogueResolver_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	DIALOGUEPLUGIN_API UDialogueResolver(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UDialogueResolver(UDialogueResolver&&); \
	UDialogueResolver(const UDialogueResolver&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(DIALOGUEPLUGIN_API, UDialogueResolver); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDialogueResolver); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDialogueResolver) \
	DIALOGUEPLUGIN_API virtual ~UDialogueResolver();


#define FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Runtime_DialogueResolver_h_16_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUDialogueResolver(); \
	friend struct Z_Construct_UClass_UDialogueResolver_Statics; \
public: \
	DECLARE_CLASS(UDialogueResolver, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/DialoguePlugin"), DIALOGUEPLUGIN_API) \
	DECLARE_SERIALIZER(UDialogueResolver)


#define FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Runtime_DialogueResolver_h_16_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Runtime_DialogueResolver_h_16_GENERATED_UINTERFACE_BODY() \
	FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Runtime_DialogueResolver_h_16_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Runtime_DialogueResolver_h_16_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IDialogueResolver() {} \
public: \
	typedef UDialogueResolver UClassType; \
	typedef IDialogueResolver ThisClass; \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Runtime_DialogueResolver_h_13_PROLOG
#define FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Runtime_DialogueResolver_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Runtime_DialogueResolver_h_16_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> DIALOGUEPLUGIN_API UClass* StaticClass<class UDialogueResolver>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_Runtime_DialogueResolver_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
