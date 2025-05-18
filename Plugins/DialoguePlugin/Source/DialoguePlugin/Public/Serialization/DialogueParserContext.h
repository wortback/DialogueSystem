// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueDataAsset.h"

#include <DialogueLogging.h>


enum class EContextState : uint8
{
	GlobalScope,     // Top-level dialogue lines
	InChoiceBlock,   // After `[choice]`, until next non-indented line or end
	InBranchBlock,   // Inside a [branch] block
	InMetaBlock,	 // For custom tags to be available like [goto], [set] [condition] etc.
};
/**
 * Working memory: builds and tracks all UDialogueNode objects
 */
class DIALOGUEPLUGIN_API FDialogueParserContext
{
public:
	UDialogueDataAsset* AssetBeingBuilt = nullptr;

	///// PARSER CONTEXT DATA

	/** Previous dialogue node that has been processed */
	TObjectPtr<UDialogueNodeBase> PrevNode = nullptr;

	/** Tracks the current dialogue node (sentence, fork, etc.) */
	TObjectPtr<UDialogueNodeBase> CurrentNode = nullptr;

	/** Tracks the indentation level (i.e. num of tab characters before text) */
	int32 IndentationLevel = 0;

public:
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