// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


class FSentenceState;
class FChoiceState;
class FBranchState;
class FChoiceTextState;
class FMetaState;
class FErrorState;
class FDispatcherState;

/**
 * 
 */
class DIALOGUEPLUGIN_API FParserState
{
public:
	static FSentenceState SentenceState;
	static FChoiceState ChoiceState;
	static FBranchState BranchState;
	static FChoiceTextState ChoiceTextState;
	static FMetaState MetaState;

	static FErrorState Error;
	static FDispatcherState Dispatcher;

	/** ID counter for node IDs within the same dialogue data asset */
	static int32 IDCounter;

public:

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

//////////////////////////////////////////////////////////////////////////
// Meta States
//////////////////////////////////////////////////////////////////////////

class FErrorState final : public FParserState
{
public:
	virtual FParserState* ProcessLine(const FString& Line, FDialogueParserContext& Context) override;
};

class FDispatcherState final : public FParserState
{
public:
	virtual FParserState* ProcessLine(const FString& Line, FDialogueParserContext& Context) override;
};


//////////////////////////////////////////////////////////////////////////
// FParserState derived classes
//////////////////////////////////////////////////////////////////////////

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

class FChoiceTextState final : public FParserState
{
public:
	virtual FParserState* ProcessLine(const FString& Line, FDialogueParserContext& Context) override;
};

class FBranchState final : public FParserState
{
public:
	virtual FParserState* ProcessLine(const FString& Line, FDialogueParserContext& Context) override;
};

class FMetaState final : public FParserState
{
public:
	virtual FParserState* ProcessLine(const FString& Line, FDialogueParserContext& Context) override;
};

