// Fill out your copyright notice in the Description page of Project Settings.


#include "Serialization/DialogueParser.h"
#include "Serialization/ParserState.h"

#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

#include "DialogueLogging.h"

bool FDialogueParser::ParseFile(const FString& FilePath, UDialogueDataAsset& OutAsset)
{
	if (Context) delete Context;
	Context = new FDialogueParserContext();
	Context->AssetBeingBuilt = &OutAsset;

	// Check if the asset is populated with data and clean it
	if (OutAsset.DialogueMap.Num() > 0)
	{
		OutAsset.DialogueMap.Empty();
		DLOG(Warning, "Clearing existing data in the asset...");
	}

	bool bSuccess = ReadFile(FilePath);
	if (bSuccess)
	{
		LogParseResult(OutAsset);
	}
	return bSuccess;
}

bool FDialogueParser::ReadFile(const FString& FilePath)
{
	if (FFileHelper::LoadFileToStringArray(FileLines, *FilePath))
	{
		for (const FString& Line : FileLines)
		{
			// Skip empty lines or comments
			if (Line.IsEmpty() || Line.StartsWith(TEXT("#"))) continue;

			DLOG(Log, "Parsing line: %s", *Line);
			DLOG(Warning, "Indentation level: %d", Context->IndentationLevel);
			State = State->ProcessLine(Line, *Context);
			if (!State || State == &FParserState::Error)
			{
				DLOG(Error, "Parsing was aborted due to an error.");
				return false;
			}
		}
		Context->AssetBeingBuilt->DialogueName = FName(*FPaths::GetBaseFilename(FilePath));
		return true;
	}

	DLOG(Error, "Failed to read file: %s", *FilePath);
	return false;
}

void FDialogueParser::LogParseResult(const UDialogueDataAsset& OutAsset)
{
	UE_LOG(LogTemp, Warning, TEXT("Parsed %d nodes"), OutAsset.DialogueMap.Num());

	for (const auto& Pair : OutAsset.DialogueMap)
	{
		if (const auto* Sentence = Cast<UDialogueSentence>(Pair.Value))
		{
			DLOG(Log, "[%s] %s: %s",*Pair.Key.ToString(), *Sentence->Speaker, *Sentence->Text);
		}
	}
}

