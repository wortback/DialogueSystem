// Copyright Ellufin Soft, Inc. All Rights Reserved.

#pragma once


/* Boilerplate
 *****************************************************************************/

#include "Misc/MonolithicHeaderBoilerplate.h"
MONOLITHIC_HEADER_BOILERPLATE()


/* Public dependencies
 *****************************************************************************/

#include "Core.h"


/* Public Logging
 *****************************************************************************/

DIALOGUEPLUGIN_API DECLARE_LOG_CATEGORY_EXTERN(DialogueParsing, Log, All);
DIALOGUEPLUGIN_API DECLARE_LOG_CATEGORY_EXTERN(DialogueValidation, Log, All);
DIALOGUEPLUGIN_API DECLARE_LOG_CATEGORY_EXTERN(DialogueRuntime, Log, All);
DIALOGUEPLUGIN_API DECLARE_LOG_CATEGORY_EXTERN(DialogueAssetGeneration, Log, All);

// For logging related to the syntax tree in the recursive parser
DIALOGUEPLUGIN_API DECLARE_LOG_CATEGORY_EXTERN(DialogueCondST, Log, All);


#define DLOG(Verbosity, Format, ...) \
	UE_LOG(DialogueParsing, Verbosity, TEXT(Format), ##__VA_ARGS__)

#define VLOG(Verbosity, Format, ...) \
	UE_LOG(DialogueValidation, Verbosity, TEXT(Format), ##__VA_ARGS__)

#define PARSER_ERROR(Line) \
	UE_LOG(DialogueParsing, Error, TEXT("Failed to process the line: %s"), *Line)

#define PARSER_ERROR_INDENTATION(Line, ContextIndentationLevel, LineIndentationLevel) \
	UE_LOG(DialogueParsing, Error, TEXT("Failed to process the line: %s"), *Line) \
	UE_LOG(DialogueParsing, Error, TEXT("Indentation level mismatch! Expected %d, got %d"), ContextIndentationLevel, LineIndentationLevel);

#define TO_IMPLEMENT(LogType, MethodName) \
	UE_LOG(LogType, Warning, TEXT("Method %s is not implemented!"), *MethodName) \
