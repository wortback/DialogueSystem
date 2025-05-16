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
DEFINE_LOG_CATEGORY(DialogueParsing);

#define DLOG(Verbosity, Format, ...) \
	UE_LOG(DialogueParsing, Verbosity, TEXT(Format), ##__VA_ARGS__)