// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DialoguePluginSettings.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef DIALOGUEPLUGIN_DialoguePluginSettings_generated_h
#error "DialoguePluginSettings.generated.h already included, missing '#pragma once' in DialoguePluginSettings.h"
#endif
#define DIALOGUEPLUGIN_DialoguePluginSettings_generated_h

#define FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialoguePluginSettings_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDialoguePluginSettings(); \
	friend struct Z_Construct_UClass_UDialoguePluginSettings_Statics; \
public: \
	DECLARE_CLASS(UDialoguePluginSettings, UObject, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/DialoguePlugin"), NO_API) \
	DECLARE_SERIALIZER(UDialoguePluginSettings) \
	static const TCHAR* StaticConfigName() {return TEXT("EditorPerProjectUserSettings");} \



#define FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialoguePluginSettings_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDialoguePluginSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UDialoguePluginSettings(UDialoguePluginSettings&&); \
	UDialoguePluginSettings(const UDialoguePluginSettings&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDialoguePluginSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDialoguePluginSettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDialoguePluginSettings) \
	NO_API virtual ~UDialoguePluginSettings();


#define FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialoguePluginSettings_h_13_PROLOG
#define FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialoguePluginSettings_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialoguePluginSettings_h_16_INCLASS_NO_PURE_DECLS \
	FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialoguePluginSettings_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> DIALOGUEPLUGIN_API UClass* StaticClass<class UDialoguePluginSettings>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialoguePluginSettings_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
