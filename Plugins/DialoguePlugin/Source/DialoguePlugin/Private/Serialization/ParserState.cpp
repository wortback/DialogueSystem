// Fill out your copyright notice in the Description page of Project Settings.


#include "Serialization/ParserState.h"

#include <DialogueLogging.h>

#include "DialogueDataAsset.h"
#include "Serialization/DialogueParserContext.h"


FSentenceState FParserState::SentenceState;
FChoiceState FParserState::ChoiceState;
FBranchState FParserState::BranchState;
FChoiceTextState FParserState::ChoiceTextState;
FMetaState FParserState::MetaState;
FErrorState FParserState::Error;
FDispatcherState FParserState::Dispatcher;

int32 FParserState::IDCounter = 0;



#pragma region FSentenceState
FParserState* FSentenceState::ProcessLine(const FString& Line, FDialogueParserContext& Context)
{
	DLOG(Log, "Parsing a sentence...");

	// If it's the first sentence after a choice or branch, we need to reduce the indentation level
	if (Context.CurrentNode &&
		(Context.CurrentNode->IsA(UDialogueChoice::StaticClass())
			|| Context.CurrentNode->IsA(UDialogueBranch::StaticClass())))
	{
		Context.IndentationLevel--;
	}

	if (GetIndentLevel(Line) == Context.IndentationLevel)
	{
		// Parse the line into speaker and text and create a sentence node
		FString Speaker, Text;
		if (!ParseSentence(Line, Speaker, Text)) return &FParserState::SentenceState;

		// Set previous node and zero the current one
		Context.PrevNode = Context.CurrentNode;
		Context.CurrentNode = nullptr;

		FName ID = GenerateID();
		UDialogueSentence* Sentence = Context.AddNode<UDialogueSentence>(ID, FString("SentenceNode"));
		Sentence->ID = ID;
		Sentence->Speaker = Speaker.TrimStartAndEnd();
		Sentence->Text = Text.TrimStartAndEnd().Replace(TEXT("\""), TEXT(""));

		// check if there's a previous node is a chain node and set its NextID to this one
		if (Context.PrevNode && Context.PrevNode->IsA(UDialogueNodeChained::StaticClass()))
		{
			UDialogueNodeChained* PrevSentence = Cast<UDialogueNodeChained>(Context.PrevNode);
			PrevSentence->NextID = ID;
		}

		Context.CurrentNode = Sentence;
		return &FParserState::Dispatcher;
	}

	// If we can't parse the line, return error
	PARSER_ERROR_INDENTATION(Line, Context.IndentationLevel, GetIndentLevel(Line));
	return &FParserState::Error;
}

bool FSentenceState::ParseSentence(const FString& Line, FString& Speaker, FString& Text)
{
	Line.Split(":", &Speaker, &Text);
	const FString TextTrimmed = Text.TrimStartAndEnd();
	if (!TextTrimmed.StartsWith(TEXT("\"")) || !TextTrimmed.EndsWith(TEXT("\"")))
	{
		DLOG(Error, "Invalid format for line: %s", *Line);
		return false;
	}
	Speaker = Speaker.TrimStartAndEnd();
	Text = TextTrimmed.Replace(TEXT("\""), TEXT(""));
	return true;
}

#pragma endregion

#pragma region FChoiceState
FParserState* FChoiceState::ProcessLine(const FString& Line, FDialogueParserContext& Context)
{
	DLOG(Log, "Parsing a choice...");

	// If we are not in the choice node, create a new one
	//  => In means it's the first [choice] keyword we encounter
	if ((!Context.CurrentNode || !Context.CurrentNode->IsA(UDialogueChoice::StaticClass()))
		&& GetIndentLevel(Line) == Context.IndentationLevel)
	{
		// Create a new choice node
		FName ID = GenerateID();
		UDialogueChoice* Choice = Context.AddNode<UDialogueChoice>(ID, FString("ChoiceNode"));

		// Create a struct for this choice option and add it to the node
		DLOG(Log, "Creating a new choice option...");
		FDialogueChoiceOption NewOption;
		Choice->Options.Add(NewOption);

		// Update Prev and Current in the context
		Context.PrevNode = Context.CurrentNode;
		Context.CurrentNode = Choice;

		// Increase the indentation level <- we are now in the choice option block
		Context.IndentationLevel++;

		return &FParserState::ChoiceTextState;
	}

	// If we are already in a choice node, just add a new choice option

	// reduce the indentation level since we are out of the prev choice option block
	Context.IndentationLevel--;

	if (GetIndentLevel(Line) == Context.IndentationLevel)
	{
		FDialogueChoiceOption NewOption;
		UDialogueChoice* Choice = Cast<UDialogueChoice>(Context.CurrentNode);
		if (!Choice)
		{
			PARSER_ERROR(Line);
			return &FParserState::Error;
		}
		DLOG(Log, "Creating a new choice option...");
		Choice->Options.Add(NewOption);

		// Increase the indentation level <- we are now in the choice option block
		Context.IndentationLevel++;

		return &FParserState::ChoiceTextState;
	}


	PARSER_ERROR_INDENTATION(Line, Context.IndentationLevel, GetIndentLevel(Line));
	return &FParserState::Error;
}


FParserState* FChoiceTextState::ProcessLine(const FString& Line, FDialogueParserContext& Context)
{
	DLOG(Log, "Parsing choice option text...");

	if (GetIndentLevel(Line) == Context.IndentationLevel)
	{
		UDialogueChoice* Choice = Cast<UDialogueChoice>(Context.CurrentNode);
		if (!Choice)
		{
			PARSER_ERROR(Line);
			return &FParserState::Error;
		}

		Choice->Options.Last().Text = Line.TrimStartAndEnd();
		DLOG(Log, "Choice option text: %s", *Line.TrimStartAndEnd());
		return &FParserState::Dispatcher;
	}

	PARSER_ERROR_INDENTATION(Line, Context.IndentationLevel, GetIndentLevel(Line));
	return &FParserState::Error;
}


#pragma endregion

#pragma region FBranchState
FParserState* FBranchState::ProcessLine(const FString& Line, FDialogueParserContext& Context)
{
	DLOG(Log, "Parsing a branch...");

	DLOG(Warning, "BranchParsing State is not implemented.");
	return &FParserState::Error;
}
#pragma endregion

FParserState* FMetaState::ProcessLine(const FString& Line, FDialogueParserContext& Context)
{
	DLOG(Log, "Parsing meta...");

	DLOG(Warning, "MetaParsing State is not implemented.");

	return &FParserState::Error;
}

FParserState* FErrorState::ProcessLine(const FString& Line, FDialogueParserContext& Context)
{
	DLOG(Error, "Parser has failed to parse the file!");
	return nullptr;
}

FParserState* FDispatcherState::ProcessLine(const FString& Line, FDialogueParserContext& Context)
{
	// If we can't parse the line, check if it's a branch or choice or fork
	if (Line.Contains("[") && Line.Contains("]") && Line.Contains("choice"))
		return ChoiceState.ProcessLine(Line, Context);
	if (Line.Contains("[") && Line.Contains("]") && Line.Contains("branch"))
		return BranchState.ProcessLine(Line, Context);
	if (Line.Contains("[") && Line.Contains("]")
		|| Line.Contains("condition") || Line.Contains("goto") || Line.Contains("set"))
		return MetaState.ProcessLine(Line, Context);
	if (Line.Contains(":"))
		return SentenceState.ProcessLine(Line, Context);

	return &FParserState::Error;
}
