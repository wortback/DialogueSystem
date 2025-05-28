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
	FDialogueParser() : State(&FParserState::Dispatcher), Context(nullptr) {}

	~FDialogueParser()
	{
		delete Context;
	}

	/** Parses the file. This method also handles dialogue flags validation, checks for infinite loops,
	 * and unreachable nodes
	 * @param FilePath
	 * @param OutAsset
	 *
	 * @return true if the file was parsed successfully and the generated data asset is valid
	 */
	bool ParseFile(const FString& FilePath, UDialogueDataAsset& OutAsset);

private:
	/** Reads the file line by line and serialises the data into DialogueNodes
	 * @param FilePath path to the file
	 *
	 * @return true if no errors happened during parsing, false otherwise
	 */
	bool ReadFile(const FString& FilePath);

	/** Logs the contents of all parsed nodes in the data asset
	 * @param Asset Asset that contains nodes to log
	 * 
	 */
	void LogParseResult(const UDialogueDataAsset& Asset) const;

	/** Extracts all flags from the file and tries to find the corresponding FlagDataAssets
	 * @return true if all flags are found, false otherwise
	 */
	bool ValidateFlags(const FString& FilePath);

	bool ValidateDialogueFlow(const UDialogueDataAsset& Asset);
};
