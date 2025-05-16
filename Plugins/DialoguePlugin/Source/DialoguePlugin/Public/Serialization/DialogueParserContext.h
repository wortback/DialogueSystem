// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueDataAsset.h"


/**
 * Working memory: builds and tracks all UDialogueNode objects
 */
class DIALOGUEPLUGIN_API FDialogueParserContext
{
public:
	UDialogueDataAsset* AssetBeingBuilt = nullptr;

	TObjectPtr<UDialogueNode> PrevNode = nullptr;

	// Tracks the current dialogue node (sentence, fork, etc.)
	TObjectPtr<UDialogueNode> CurrentNode = nullptr;

	// Optional: if you're inside a branch or choice block
	TObjectPtr<UDialogueBranch> CurrentBranch = nullptr;

	// Helper for creating and registering nodes
	template<typename T>
	T* AddNode(FName ID, const FString& NodeType)
	{
		FString NodeName = FString::Printf(TEXT("%s_%s"), *NodeType, *ID.ToString());
		T* Node = NewObject<T>(AssetBeingBuilt, *NodeName);
		Node->SetFlags(RF_Public | RF_Transactional);
		AssetBeingBuilt->DialogueMap.Add(ID, Node);
		return Node;
	}
};