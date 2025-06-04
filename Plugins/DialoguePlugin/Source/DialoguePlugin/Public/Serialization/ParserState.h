// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Serialization/DialogueParserContext.h"


struct FParsedFlag
{
	FString Name;
	EFlagCompSymbol Comp = EFlagCompSymbol::None;
	EFlagOperator Operator = EFlagOperator::None;
	bool bValue = false;
	int32 nValue = INT_MAX;

	/** Convert this flag data into the condition data used in the dialogue asset */
	FFlagCondition ToFlagCondition()
	{
		FFlagCondition Condition;
		Condition.FlagName = Name;
		Condition.ComparisonSymbol = Comp;
		Condition.IntValue = nValue;
		Condition.BoolValue = bValue;
		return Condition;
	}

	/** Convert this flag data into the flag effect data used in the dialogue asset */
	FFlagEffect ToFlagEffect()
	{
		FFlagEffect Effect;
		Effect.FlagName = Name;
		Effect.Operator = Operator;
		Effect.IntValue = nValue;
		Effect.BoolValue = bValue;
		return Effect;
	}
};

class FSentenceState;
class FChoiceState;
class FBranchState;
class FBranchDispatcherState;
class FChoiceTextState;
class FChoiceMetaState;
class FMetaState;
class FErrorState;
class FDispatcherState;
class FExtractFlagsState;
class FForkState;
class FNestedDispatcherState;


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
	static FChoiceMetaState ChoiceMetaState;
	static FMetaState MetaState;
	static FExtractFlagsState ExtractFlagsState;
	static FForkState ConditionalState;

	static FErrorState Error;
	static FDispatcherState Dispatcher;
	static FBranchDispatcherState BranchDispatcher;
	static FNestedDispatcherState NestedDispatcher;

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

	/**
	 * Extracts the tag from a line, e.g. "[goto BranchName]"
	 * If the line does not contain a tag, it returns an empty string.
	 * If the line contains only an opening or (exclusive) closing brace, it returns false.
	 * 
	 * @param Line The line to extract the tag from
	 * @param Tag The output string that will hold the extracted tag
	 * 
	 * @return true if the tag was successfully extracted, false otherwise
	 */
	bool ExtractTag(const FString& Line, FString& Tag)
	{
		int32 Start, End;
		if (Line.FindChar('[', Start) && Line.FindChar(']', End) && End > Start)
		{
			Tag = Line.Mid(Start + 1, End - Start - 1).TrimStartAndEnd();
			return true;
		}
		// No braces -> sentence
		if (!Line.FindChar('[', Start) && !Line.FindChar(']', End))
		{
			Tag = "";
			return true;
		}
		return false;
	}

	FString TrimSquareBrackets(const FString& Line)
	{
		FString Trimmed = Line.TrimStartAndEnd();
		Trimmed = Trimmed.Replace(TEXT("["), TEXT(""));
		Trimmed = Trimmed.Replace(TEXT("]"), TEXT(""));
		return Trimmed.TrimStartAndEnd();
	}

	bool ParseNameFromLine(const FString& Line, FString& OutName, const FString& ContextDescription)
	{
		FString Trimmed = TrimSquareBrackets(Line);

		if (!Trimmed.Split(" ", nullptr, &OutName, ESearchCase::IgnoreCase))
		{
			DLOG(Error, "Missing a space between the %s and name in %s", *ContextDescription, *Line);
			return false;
		}

		OutName = OutName.TrimStartAndEnd();

		if (OutName.IsEmpty())
		{
			DLOG(Error, "Name is empty in: %s", *Line);
			return false;
		}
		return true;
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
	friend class FNestedDispatcherState;
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

class FNestedDispatcherState final : public FParserState
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

class FExtractFlagsState final : public FParserState
{
	friend class FMetaState;
	friend class FChoiceMetaState;
	friend class FForkState;
public:
	virtual FParserState* ProcessLine(const FString& Line, FDialogueParserContext& Context) override;
private:
	UDialogueFlag* FindFlag(const FString& FlagName);

	bool ParseFlagName(const FString& Line, FString& FlagName);

	bool ParseFlagExpression(const FString& Line, FParsedFlag& OutFlag);
};

class FForkState final : public FParserState {
	friend class FBranchState;
public:
	virtual FParserState* ProcessLine(const FString& Line, FDialogueParserContext& Context) override;

	void CreateAndLinkNestingBlock(FDialogueParserContext& Context, const FFlagCondition& Condition);
};