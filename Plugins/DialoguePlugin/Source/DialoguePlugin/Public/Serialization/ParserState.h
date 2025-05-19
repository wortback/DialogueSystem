// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Serialization/DialogueParserContext.h"


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

public:

	virtual ~FParserState() {};

	virtual FParserState* ProcessLine(const FString& Line, FDialogueParserContext& Context) = 0;

	static FName GenerateID(FDialogueParserContext& Context)
	{
		return FName(*FString::Printf(TEXT("ID_%d"), ++Context.IDCounter));
	}

	static void ResetIDCounter(FDialogueParserContext& Context)
	{
		Context.IDCounter = 0;
	}

	void ResetIndentationAfterChoice(FDialogueParserContext& Context)
	{
		// If it's the first sentence after a choice, we need to reduce the indentation level
		if (Context.CurrentNode && Context.CurrentNode->IsA(UDialogueChoice::StaticClass()))
		{
			Context.IndentationLevel--;
		}
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

private:
	bool ParseSentence(const FString& Line, FString& Speaker, FString& Text);

	FParserState* ProcessBlockLine(const FString& Line, FDialogueParserContext& Context);

	FParserState* ProcessNoIndentLine(const FString& Line, FDialogueParserContext& Context);
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

private:
	bool ParseBranchName(const FString& Line, FString& BranchName);
};

class FMetaState final : public FParserState
{
public:
	virtual FParserState* ProcessLine(const FString& Line, FDialogueParserContext& Context) override;
};

