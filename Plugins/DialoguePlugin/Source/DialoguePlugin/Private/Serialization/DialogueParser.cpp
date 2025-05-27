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

	ValidateFlags(FilePath);

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
		State = &FParserState::Dispatcher;
		int32 Counter = 0;
		for (const FString& Line : FileLines)
		{
			// Skip empty lines or comments
			FString Trimmed = Line.TrimStart();
			if (Trimmed.IsEmpty() || Trimmed.StartsWith(TEXT("#"))) continue;

			DLOG(Log, "Parsing line: %s", *Line);
			State = State->ProcessLine(Line, *Context);
			if (!State || State == &FParserState::Error)
			{
				DLOG(Error, "Parsing was aborted due to an error.");
				DLOG(Error, "Line number: %d", Counter);
				DLOG(Error, "Line content: %s", *Line);
				return false;
			}

			Counter++;
		}
		// Check if there's a branch node hanging in the memory and not added to the asset
		// It means that the file has ended wih the branch node
		if (Context->BranchNode)
		{
			DLOG(Warning, "The file ended with a branch node. Adding it to the asset.");
			Context->AssetBeingBuilt->DialogueMap.Add(Context->BranchNode->ID, Context->BranchNode);
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
			DLOG(Log, "[%s] %s: %s", *Pair.Key.ToString(), *Sentence->Speaker, *Sentence->Text);
		}
	}
}

bool FDialogueParser::ValidateFlags(const FString& FilePath)
{
	if (FFileHelper::LoadFileToStringArray(FileLines, *FilePath))
	{
		State = &FParserState::ExtractFlagsState;
		int32 Counter = 0;
		for (const FString& Line : FileLines)
		{
			// Skip empty lines or comments
			FString Trimmed = Line.TrimStart();
			if (Trimmed.IsEmpty() || Trimmed.StartsWith(TEXT("#"))) continue;

			State = State->ProcessLine(Line, *Context);
			if (!State || State == &FParserState::Error)
			{
				DLOG(Error, "Parsing was aborted due to an error.");
				DLOG(Error, "Line number: %d", Counter);
				DLOG(Error, "Line content: %s", *Line);
				return false;
			}
			Counter++;
		}

		// Check the missing flags in the context
		if (Context->MissingFlags.Num() > 0)
		{
			DLOG(Error, "The following flags were found in the file but not defined in the asset:");
			for (const FString& Flag : Context->MissingFlags)
			{
				DLOG(Error, "- %s", *Flag);
			}
			return false;
		}
		DLOG(Log, "All flags were found in the asset.");
		return true;
	}

	DLOG(Error, "Failed to read file: %s", *FilePath);
	return false;
}

