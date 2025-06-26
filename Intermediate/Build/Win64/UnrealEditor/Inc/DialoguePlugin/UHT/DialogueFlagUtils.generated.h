// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DialogueFlagUtils.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef DIALOGUEPLUGIN_DialogueFlagUtils_generated_h
#error "DialogueFlagUtils.generated.h already included, missing '#pragma once' in DialogueFlagUtils.h"
#endif
#define DIALOGUEPLUGIN_DialogueFlagUtils_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_wortb_Documents_Unreal_Projects_DialogueSystem_Plugins_DialoguePlugin_Source_DialoguePlugin_Public_DialogueFlagUtils_h


#define FOREACH_ENUM_EFLAGCOMPSYMBOL(op) \
	op(EFlagCompSymbol::GreaterThan) \
	op(EFlagCompSymbol::LessThan) \
	op(EFlagCompSymbol::GreaterEquals) \
	op(EFlagCompSymbol::LessEquals) \
	op(EFlagCompSymbol::Equals) \
	op(EFlagCompSymbol::NotEquals) \
	op(EFlagCompSymbol::None) 

enum class EFlagCompSymbol : uint8;
template<> struct TIsUEnumClass<EFlagCompSymbol> { enum { Value = true }; };
template<> DIALOGUEPLUGIN_API UEnum* StaticEnum<EFlagCompSymbol>();

#define FOREACH_ENUM_EFLAGOPERATOR(op) \
	op(EFlagOperator::Add) \
	op(EFlagOperator::Subtract) \
	op(EFlagOperator::Set) \
	op(EFlagOperator::None) 

enum class EFlagOperator : uint8;
template<> struct TIsUEnumClass<EFlagOperator> { enum { Value = true }; };
template<> DIALOGUEPLUGIN_API UEnum* StaticEnum<EFlagOperator>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
