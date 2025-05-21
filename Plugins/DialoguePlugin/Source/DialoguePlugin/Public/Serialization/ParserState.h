// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Serialization/DialogueParserContext.h"


class FSentenceState;
class FChoiceState;
class FBranchState;
class FBranchDispatcherState;
class FChoiceTextState;
class FChoiceMetaState;
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
	static FBranchDispatcherState BranchDispatcher;
	static FChoiceTextState ChoiceTextState;
	static FChoiceMetaState ChoiceMetaState;
	static FMetaState MetaState;

	static FErrorState Error;
	static FDispatcherState Dispatcher;

public:
	virtual ~FParserState() {};

	virtual FParserState* ProcessLine(const FString& Line, FDialogueParserContext& Context) = 0;

protected:
	static FName GenerateID(FDialogueParserContext& Context)
	{
		return FName(*FString::Printf(TEXT("ID_%d"), ++Context.IDCounter));
	}

	static void ResetIDCounter(FDialogueParserContext& Context)
	{
		Context.IDCounter = 0;
	}

	bool CanParseMeta(const FString& Line)
	{
		return Line.Contains("[") && Line.Contains("]")
			&& (Line.Contains("condition") || Line.Contains("goto") || Line.Contains("set"));
	}

	FString ExtractTag(const FString& Line)
	{
		int32 Start, End;
		if (Line.FindChar('[', Start) && Line.FindChar(']', End) && End > Start)
		{
			return Line.Mid(Start + 1, End - Start - 1).TrimStartAndEnd();
		}
		return "";
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
	friend class FBranchDispatcherState;
public:
	virtual FParserState* ProcessLine(const FString& Line, FDialogueParserContext& Context) override;
private:
	FParserState* Dispatch(const FString& Line, FDialogueParserContext& Context);
};

class FBranchDispatcherState final : public FParserState
{
public:
	virtual FParserState* ProcessLine(const FString& Line, FDialogueParserContext& Context) override;
};

class FEndBlockState final : public FParserState
{
public:
	virtual FParserState* ProcessLine(const FString& Line, FDialogueParserContext& Context) override;

	void DecrementIndentation(FDialogueParserContext& Context)
	{
		Context.IndentationLevel--;
	}
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

class FChoiceMetaState final : public FParserState
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
	friend class FChoiceMetaState;
public:
	virtual FParserState* ProcessLine(const FString& Line, FDialogueParserContext& Context) override;
private:
	bool ParseGotoName(const FString& Line, FString& BranchName);
};

