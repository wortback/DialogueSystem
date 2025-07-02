// Fill out your copyright notice in the Description page of Project Settings.


#include "Serialization/DialogueParser.h"
#include "Serialization/ParserState.h"
#include "CondParser/CondTreeWrapper.h"

#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

#include "DialoguePlugin/Public/DialogueLogging.h"

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

	TArray<FString> Cycles;
	if (HasShallowCycles(OutAsset, Cycles))
	{
		DLOG(Warning, "Has found shallow cycles in the dialogue!");
		for (const auto& Cycle : Cycles)
		{
			DLOG(Log, "%s", *Cycle);
		}
	}
	else
	{
		DLOG(Warning, "No shallow cycles found in the dialogue!");
	}

	Context->AssetBeingBuilt->Modify();
	Context->AssetBeingBuilt->MarkPackageDirty();
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
		bSuccess &= ValidateForks(Pair.Value);
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
		//VLOG(Log, "Checking goto name %s", *GotoNode->NextID.ToString());

		if (!Asset.DialogueMap.Contains(GotoNode->NextID))
		{
			VLOG(Error, "Branch %s is referenced in %s but does not exist!",
				*GotoNode->NextID.ToString(), *GotoNode->ID.ToString());
			bSuccess = false;
		}
		else
		{
			ReferencedBranches.Add(GotoNode->NextID);
		}
	}

	// if the curr node is a branch, we descend into it and collect all referenced branches
	if (const UDialogueBranch* Branch = Cast<UDialogueBranch>(Node))
	{
		for (const auto& NodeInBranch : Branch->Content)
		{
			bSuccess &= CollectReferenced(NodeInBranch.Value, ReferencedBranches, Asset);
		}
	}
	// if the curr node is a choice, we check all options and collect referenced branches
	else if (const UDialogueChoice* Choice = Cast<UDialogueChoice>(Node))
	{
		for (const auto& Option : Choice->Options)
		{
			if (!Option.GotoID.IsNone())
			{
				if (!Asset.DialogueMap.Contains(Option.GotoID))
				{
					VLOG(Error, "Branch %s is referenced in %s but does not exist!",
						*Option.GotoID.ToString(), *Choice->ID.ToString());
					bSuccess = false;
				}
				else
				{
					ReferencedBranches.Add(Option.GotoID);
				}
			}
		}
	}
	// if the curr node is a fork, we descend into it and look for referenced branches
	else if (const UDialogueFork* Fork = Cast<UDialogueFork>(Node))
	{
		for (const auto& ForkBranch : Fork->Branches)
		{
			if (ForkBranch.Branch)
			{
				for (const auto& NodeInBranch : ForkBranch.Branch->Content)
				{
					bSuccess &= CollectReferenced(NodeInBranch.Value, ReferencedBranches, Asset);
				}
			}
		}
	}
	return bSuccess;
}

bool FDialogueParser::ValidateForks(const TObjectPtr<UDialogueNodeBase>& Node)
{
	bool bSuccess = true;
	if (const UDialogueFork* Fork = Cast<UDialogueFork>(Node))
	{
		VLOG(Log, "Checking fork %s", *Fork->ID.ToString());
		int32 NumEmpty = 0;
		for (const auto& Branch : Fork->Branches)
		{
			if (Branch.Branch->Content.IsEmpty())
			{
				NumEmpty++;
				if (Branch.TreeWrapper)
				{
					VLOG(Warning, "%s has no body before [else]-that branch will be a no-op.",
						*Branch.TreeWrapper->CondString);
				}
				else
					VLOG(Warning, "[else] has no body.");
			}
			// Descend into the branch and check if there are any nested forks
			else
			{
				for (const auto& NodeInBranch : Branch.Branch->Content)
				{
					bSuccess &= ValidateForks(NodeInBranch.Value);
				}
			}
		}
		if (NumEmpty == Fork->Branches.Num())
		{
			VLOG(Error, "Found an if-else block where all branches are empty!");
			bSuccess = false;
		}
	}
	return bSuccess;
}

bool FDialogueParser::HasShallowCycles(const UDialogueDataAsset& Asset, TArray<FString>& Cycles)
{
	// {Branch: {bIsVisited, GotoID}}
	TMap<FName, TTuple<bool, FName>> BranchesGotos;
	TArray<FName> Path;

	for (const auto& Pair : Asset.DialogueMap)
	{
		if (UDialogueBranch* Branch = Cast<UDialogueBranch>(Pair.Value); Branch)
		{
			FName GotoID;
			for (const auto& BranchPair : Branch->Content)
			{
				if (UDialogueGotoNode* Goto = Cast<UDialogueGotoNode>(BranchPair.Value); Goto)
				{
					GotoID = Goto->NextID;
					break;
				}
			}
			BranchesGotos.Add({ Branch->ID, TTuple<bool, FName>(false, GotoID) });
		}
	}

	for (const auto& Node : BranchesGotos)
	{
		if (!Node.Value.Key)
		{
			BranchGotoDFS({Node.Key, Node.Value.Value}, BranchesGotos, Cycles, Path);
		}
	}

	return !Cycles.IsEmpty();
}

void FDialogueParser::BranchGotoDFS(TTuple<FName, FName> Current, TMap<FName, TTuple<bool, FName>>& Branches,
	TArray<FString>& Cycles, TArray<FName>& Path)
{
	const FName& CurrentID = Current.Key;
	const FName& NextID = Current.Value;

	if (NextID.IsNone())
		return;

	if (Path.Contains(CurrentID))
	{
		Cycles.Add(CycleToString(Path));
		return;
	}

	TTuple<bool, FName>* CurrentBGPair = Branches.Find(CurrentID);
	TTuple<bool, FName>* NextBGPair = Branches.Find(NextID);

	if (!NextBGPair)
	{
		VLOG(Error, "Branch %s doesn't exist!", *NextID.ToString());
		return;
	}

	Path.Add(CurrentID);
	if (CurrentBGPair)
		CurrentBGPair->Key = true;

	BranchGotoDFS({ NextID, NextBGPair->Value }, Branches, Cycles, Path);
	Path.Pop();
}

FString FDialogueParser::CycleToString(const TArray<FName>& Path)
{
	FString Res = FString::JoinBy(Path, TEXT(" -> "), [](const FName& Node)
		{
			return Node.ToString();
		});
	Res += TEXT(" -> ");
	Res += Path[0].ToString();
	return Res;
}

// Infinite loop check
// Decided to postpone it because the language may change.
// For now only a shallow check is implemented (e.g. goto branch A -> goto branch B -> goto branch A)
/*
bool FDialogueParser::HasUnmarkedCycles(const UDialogueDataAsset& Asset, TArray<FString>& Cycles)
{
	TSet<FName> Visited, RecStack;
	// Will hold nodes that are part of the cycle (Node1 -> Node2 -> ... -> Node1)
	FString CycleStr;

	for (const auto& Pair : Asset.DialogueMap)
	{
		if (Pair.Value->IsA(UDialogueSentence::StaticClass()))
			continue; // Skip sentence nodes, they are not part of the cycle

		FName Start = Pair.Key;
		if (!Visited.Contains(Start) && DFS(Start, Asset, Visited, RecStack, Cycles, CycleStr))
			return true;
	}
	return false;
}

bool FDialogueParser::DFS(FName Current, const UDialogueDataAsset& Asset, TSet<FName>& Visited,
	TSet<FName>& RecStack, TArray<FString>& Cycles, FString& CycleStr)
{
	Visited.Add(Current);
	RecStack.Add(Current);
	CycleStr += Current.ToString() + " -> ";

	for (FName NextID : GetOutgoingNodes(Current, Asset))
	{
		if (RecStack.Contains(NextID))
		{
			Cycles.Add(CycleStr);
			return true;
		}

		if (!Visited.Contains(NextID) && DFS(NextID, Asset, Visited, RecStack, Cycles, CycleStr))
			return true;
	}

	RecStack.Remove(Current);
	return false;
}

TArray<FName> FDialogueParser::GetOutgoingNodes(FName Current, const UDialogueDataAsset& Asset)
{
	TArray<FName> Res;
	// Check if the node is a choice node and choice options have gotos
	if (Current.IsNone()) return Res;

	if (const UDialogueChoice* Node = Cast<UDialogueChoice>(Asset.DialogueMap[Current]); Node)
	{
		for (const auto& Option: Node->Options)
		{
			if (!Option.GotoID.IsNone())
			{
				Res.Add(Option.GotoID);
			}
		}
		return Res;
	}

	// Check if the node is a branch and recurse into it
	if (const UDialogueBranch* Node = Cast<UDialogueBranch>(Asset.DialogueMap[Current]); Node)
	{
		for (const auto& Pair : Node->Content)
		{
			if (Pair.Value->IsA(UDialogueGotoNode::StaticClass()))
			{
				Res.Add(Pair.Key);
			}
		}
		return Res;
	}

	// Check if the node is a fork and recurse into its branches
	if (const UDialogueFork* Node = Cast<UDialogueFork>(Asset.DialogueMap[Current]); Node)
	{
		for (const auto& Branch : Node->Branches)
		{
			for (const auto& Pair : Branch.Branch->Content)
			{
				if (Pair.Value->IsA(UDialogueGotoNode::StaticClass()))
				{
					Res.Add(Pair.Key);
				}
			}
		}
		return Res;
	}

	// Check if the node is linkable and has NextID
	if (const UDialogueNodeLinkable* Node = Cast<UDialogueNodeLinkable>(Asset.DialogueMap[Current]); Node)
	{
		Res.Add(Node->NextID);
		return Res;
	}
	return Res;
}
*/
