// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueDataAsset.h"
#include "DialogueLogging.h"
#include "CondParser/CondSyntaxTree.h"
#include "CondParser/CondParser.h"
#include "CondTreeWrapper.generated.h"


UCLASS(BlueprintType)
class DIALOGUEPLUGIN_API UCondTreeWrapper : public UObject
{
    GENERATED_BODY()

public:
    /** Pointer to the root of the C++ tree (not exposed to BP). This is a transient property. We will build the tree for every */
    TUniquePtr<ICondNode> InternalNode;

	/** String representation of the condition as written in .dgl file. Used for debugging. */
	UPROPERTY()
	FString CondString;

    void Init(TUniquePtr<ICondNode> InNode)
    {
        InternalNode = MoveTemp(InNode);
    }

    bool Evaluate(const TMap<FName, int32>& IntFlags, const TMap<FName, bool>& BoolFlags)
    {
		if (!InternalNode)
		{
			InternalNode = FCondParser::Parse(CondString);
		}
		if (!InternalNode)
		{
			UE_LOG(DialogueRuntime, Error, TEXT("[Evaluate] Failed to parse the cond tree."));
			return false;
		}
        return InternalNode->Evaluate(IntFlags, BoolFlags);
    }
};