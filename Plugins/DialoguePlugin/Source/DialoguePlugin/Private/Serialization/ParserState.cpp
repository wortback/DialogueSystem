// Fill out your copyright notice in the Description page of Project Settings.


#include "Serialization/ParserState.h"

#include <DialogueLogging.h>

#include "DialogueDataAsset.h"
#include "Serialization/DialogueParserContext.h"

FSentenceState FParserState::SentenceState;
FChoiceState FParserState::ChoiceState;
FBranchState FParserState::BranchState;

int32 FParserState::IDCounter = 0;


#pragma region FSentenceState
FParserState* FSentenceState::ProcessLine(const FString& Line, FDialogueParserContext& Context)
{
	if (Line.Contains(":"))
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

		// check if there's a previous sentence node and set its NextID to this one
		if (Context.PrevNode && Context.PrevNode->IsA(UDialogueSentence::StaticClass()))
		{
			UDialogueSentence* PrevSentence = Cast<UDialogueSentence>(Context.PrevNode);
			PrevSentence->NextID = ID;
		}

		Context.CurrentNode = Sentence;
		return &FParserState::SentenceState;
	}

	DLOG(Error, "Failed to process the line: %s", *Line);

	// If we can't parse the line, check if it's a branch or choice or fork
	if (Line.Contains("["))
		return &FParserState::ChoiceState;

	return &FParserState::SentenceState;
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
	return &FParserState::ChoiceState;
}
#pragma endregion

#pragma region FBranchState
FParserState* FBranchState::ProcessLine(const FString& Line, FDialogueParserContext& Context)
{
	return &FParserState::BranchState;
}
#pragma endregion
