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

	// Validation for the dialogue flow: check unreachable nodes and infinite loops
	ValidateDialogueFlow(OutAsset);

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

void FDialogueParser::LogParseResult(const UDialogueDataAsset& Asset) const
{
	UE_LOG(DialogueParsing, Warning, TEXT("Parsed %d nodes"), Asset.DialogueMap.Num());
	UE_LOG(DialogueParsing, Log,
		TEXT("----------------------------------------------------------------"));

	for (const auto& Pair : Asset.DialogueMap)
	{
		Pair.Value->LogNode(0);
	}

	UE_LOG(DialogueParsing, Log,
		TEXT("----------------------------------------------------------------"));
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
				VLOG(Error, "Parsing was aborted due to an error.");
				VLOG(Error, "Line number: %d", Counter);
				VLOG(Error, "Line content: %s", *Line);
				return false;
			}
			Counter++;
		}

		// Check the missing flags in the context
		if (Context->MissingFlags.Num() > 0)
		{
			VLOG(Error, "The following flags were found in the file but not defined in the asset:");
			for (const FString& Flag : Context->MissingFlags)
			{
				VLOG(Error, "- %s", *Flag);
			}
			return false;
		}
		VLOG(Log, "All flags were found in the asset.");
		return true;
	}

	VLOG(Error, "Failed to read file: %s", *FilePath);
	return false;
}

bool FDialogueParser::ValidateDialogueFlow(const UDialogueDataAsset& Asset)
{
	VLOG(Log, "Validating dialogue flow: checking for missing and unused branch references...");

	bool bSuccess = true;
	TSet<FName> ReferencedBranches;

	// First pass: collect all references
	for (const auto& Pair : Asset.DialogueMap)
	{
		bSuccess &= CollectReferenced(Pair.Value, ReferencedBranches, Asset);
	}

	// Second pass: detect defined but never referenced branches
	for (const auto& Pair : Asset.DialogueMap)
	{
		if (const UDialogueBranch* Branch = Cast<UDialogueBranch>(Pair.Value))
		{
			if (!ReferencedBranches.Contains(Branch->ID))
			{
				VLOG(Warning, "Branch %s is defined but never referenced!", *Branch->ID.ToString());
				// bSuccess is not affected – we treat this as a warning
			}
		}
	}
	if (bSuccess)
		VLOG(Log, "No missing branch references found");

	return bSuccess;
}

bool FDialogueParser::CollectReferenced(const TObjectPtr<UDialogueNodeBase>& Node, TSet<FName>& ReferencedBranches,
	const UDialogueDataAsset& Asset)
{
	bool bSuccess = true;
	if (const UDialogueGotoNode* GotoNode = Cast<UDialogueGotoNode>(Node))
	{
		VLOG(Log, "Checking goto name %s", *GotoNode->GotoID.ToString());

		if (!Asset.DialogueMap.Contains(GotoNode->GotoID))
		{
			VLOG(Error, "Branch %s is referenced in %s but does not exist!",
				*GotoNode->GotoID.ToString(), *GotoNode->ID.ToString());
			bSuccess = false;
		}
		else
		{
			ReferencedBranches.Add(GotoNode->GotoID);
		}

	}
	if (const UDialogueBranch* Branch = Cast<UDialogueBranch>(Node))
	{
		for (const auto& NodeInBranch : Branch->Content)
		{
			bSuccess &= CollectReferenced(NodeInBranch.Value, ReferencedBranches, Asset);
		}
	}
	else if (const UDialogueChoice* Choice = Cast<UDialogueChoice>(Node))
	{
		for (const auto& Option : Choice->Options)
		{
			if (!Option.GotoID.IsNone())
			{
				if (!Asset.DialogueMap.Contains(Option.GotoID))
				{
					VLOG(Error, "Choice option references missing branch %s!",
						*Option.GotoID.ToString());
					bSuccess = false;
				}
				else
				{
					ReferencedBranches.Add(Option.GotoID);
				}
			}
		}
	}
	return bSuccess;
}