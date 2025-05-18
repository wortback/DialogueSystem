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

DECLARE_LOG_CATEGORY_EXTERN(DialogueParsing, Log, All);


#define DLOG(Verbosity, Format, ...) \
	UE_LOG(DialogueParsing, Verbosity, TEXT(Format), ##__VA_ARGS__)

#define PARSER_ERROR(Line) \
	UE_LOG(DialogueParsing, Error, TEXT("Failed to process the line: %s"), *Line)

# define PARSER_ERROR_INDENTATION(Line, ContextIndentationLevel, LineIndentationLevel) \
	UE_LOG(DialogueParsing, Error, TEXT("Failed to process the line: %s"), *Line) \
	UE_LOG(DialogueParsing, Error, TEXT("Indentation level mismatch! Expected %d, got %d"), ContextIndentationLevel, LineIndentationLevel);