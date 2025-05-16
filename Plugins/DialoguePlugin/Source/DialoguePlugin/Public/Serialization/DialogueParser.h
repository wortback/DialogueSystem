// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueDataAsset.h"
#include "ParserState.h"
#include "Serialization/DialogueParserContext.h"

/**
 * Main parser class that manages I/O and parsing loop
 */
class DIALOGUEPLUGIN_API FDialogueParser
{
	TArray<FString> FileLines;

	FParserState* State;
	FDialogueParserContext* Context;

public:
	FDialogueParser() : State(&FParserState::SentenceState), Context(nullptr)
	{
		FParserState::ResetIDCounter();
	}

	~FDialogueParser()
	{
		delete Context;
	}

	bool ParseFile(const FString& FilePath, UDialogueDataAsset& OutAsset);

private:
	bool ReadFile(const FString& FilePath);

	void LogParseResult(const UDialogueDataAsset& OutAsset);
};
