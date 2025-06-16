// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueDataAsset.h"

#include <DialogueLogging.h>


class FParserState;

/**
 * An object of this class should be passed into the parser so that it can track the indentation level
 * and whether the parser is in nested blocks.
 */
class DIALOGUEPLUGIN_API FDialogueParserContext
{
public:
	friend class FDialogueParser;

	UDialogueDataAsset* AssetBeingBuilt = nullptr;

	///// PARSER CONTEXT DATA

	/** ID counter for node IDs within the same dialogue data asset */
	int32 IDCounter = 0;

	/** Caches the tag such as [set], [condition], [goto], etc. */
	FString ExtractedTag;

	/** Previous dialogue node that has been processed */
	TObjectPtr<UDialogueNodeBase> PrevNode = nullptr;

	/** Tracks the current dialogue node (sentence, fork, etc.) */
	TObjectPtr<UDialogueNodeBase> CurrentNode = nullptr;

	/** If the parser is in a branch, this node it set to it
	 *	CurrentNode is then used for the dialogue nodes inside the branch
	 */
	TObjectPtr<UDialogueBranch> BranchNode = nullptr;

	/** Tracks the indentation level (i.e. num of tab characters before text) */
	int32 IndentationLevel = 0;

	/** Holds the names of all flags that were found in the file but not defined in the asset */
	TArray<FString> MissingFlags;

	/** Keeps track of the current nested level in if-else constructions */
	TArray<UDialogueFork*> NestStack;

private:
	FDialogueParserContext() {}

public:
	/** Adds the node to the data asset */
	template<typename T>
	T* AddNode(FName ID, const FString& NodeType)
	{
		DLOG(Log, "Adding node %s with ID %s", *NodeType, *ID.ToString());

		FString NodeName = FString::Printf(TEXT("%s_%s"), *NodeType, *ID.ToString());
		T* Node = NewObject<T>(AssetBeingBuilt, *NodeName);
		Node->SetFlags(RF_Public | RF_Transactional);
		AssetBeingBuilt->DialogueMap.Add(ID, Node);
		return Node;
	}

	/** Adds the node to the current branch. */
	template<typename T>
	T* AddNodeBranch(FName ID, const FString& NodeType)
	{
		if (!BranchNode)
		{
			DLOG(Error, "No branch node set. Cannot add node %s with ID %s", *NodeType, *ID.ToString());
			return nullptr;
		}

		DLOG(Log, "Adding node %s with ID %s to the branch %s", *NodeType, *ID.ToString(), *BranchNode->GetName());

		FString NodeName = FString::Printf(TEXT("%s_%s"), *NodeType, *ID.ToString());
		T* Node = NewObject<T>(AssetBeingBuilt, *NodeName);
		Node->SetFlags(RF_Public | RF_Transactional);

		// Is it's the first node we add to the branch, set the FirstID to this one
		if (BranchNode->Content.IsEmpty())
			BranchNode->FirstID = ID;

		BranchNode->Content.Add(ID, Node);
		return Node;
	}

	/** Adds a node to the current fork on the nest stack */
	template<typename T>
	T* AddNodeFork(FName ID, const FString& NodeType, const FFlagCondition& Condition, UCondTreeWrapper& Tree)
	{
		if (NestStack.IsEmpty())
		{
			DLOG(Error, "Nest stack for forks is empty. Cannot add node %s with ID %s", *NodeType, *ID.ToString());
			return nullptr;
		}

		DLOG(Log, "Adding node %s with ID %s to the fork %s", *NodeType, *ID.ToString(), *NestStack.Last()->GetName());

		FString NodeName = FString::Printf(TEXT("%s_%s"), *NodeType, *ID.ToString());
		T* Node = NewObject<T>(AssetBeingBuilt, *NodeName);
		Node->SetFlags(RF_Public | RF_Transactional);

		FBranchWithCondition Cond;
		Cond.Condition = Condition;
		Cond.TreeWrapper = &Tree;
		Cond.Branch = Node;

		NestStack.Last()->Branches.Add(Cond);
		return Node;
	}

	/** Check if the previous node is a chain node and set its NextID to the ID provided */
	bool TryLinkNodes(FName ID)
	{
		if (PrevNode && PrevNode->IsA(UDialogueNodeLinkable::StaticClass()))
		{
			UDialogueNodeLinkable* Prev = Cast<UDialogueNodeLinkable>(PrevNode);
			Prev->NextID = ID;
			DLOG(Log, "Successfully linked nodes!");
			return true;
		}
		DLOG(Log, "Failed to link nodes!");
		return false;
	}
};

inline int32 GetIndentLevel(const FString& Line)
{
	int32 Count = 0;
	for (TCHAR C : Line)
	{
		if (C == '\t') Count++;
		else break;
	}
	return Count;
}