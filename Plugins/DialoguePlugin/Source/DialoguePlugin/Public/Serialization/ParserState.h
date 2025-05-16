// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


class FSentenceState;
class FChoiceState;
class FBranchState;

/**
 * 
 */
class DIALOGUEPLUGIN_API FParserState
{
public:
	static FSentenceState SentenceState;
	static FChoiceState ChoiceState;
	static FBranchState BranchState;

	/** ID counter for node IDs within the same dialogue data asset */
	static int32 IDCounter;

	virtual ~FParserState() {};

	virtual FParserState* ProcessLine(const FString& Line, class FDialogueParserContext& Context) = 0;

	static FName GenerateID()
	{
		return FName(*FString::Printf(TEXT("ID_%d"), ++IDCounter));
	}

	static void ResetIDCounter()
	{
		IDCounter = 0;
	}
};


class FSentenceState final : public FParserState
{
public:
	virtual FParserState* ProcessLine(const FString& Line, FDialogueParserContext& Context) override;

	bool ParseSentence(const FString& Line, FString& Speaker, FString& Text);
};

class FChoiceState final : public FParserState
{
public:
	virtual FParserState* ProcessLine(const FString& Line, FDialogueParserContext& Context) override;
};

class FBranchState final : public FParserState
{
public:
	virtual FParserState* ProcessLine(const FString& Line, FDialogueParserContext& Context) override;
};