// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueDataAsset.h"
#include "DialogueLogging.h"
#include "CondSyntaxTree.generated.h"


/** Represents the logical operators && and || in the syntax tree */
enum class ELogicalOp 
{ 
	And, 
	Or 
};

/** Abstract base class for the syntax tree nodes */
struct ICondNode
{
	virtual ~ICondNode() = default;


	/**
	 * This method is used for the condition evaluation at runtime
	 */
	virtual bool Evaluate(const TMap<FName, int32>& IntFlags,
		const TMap<FName, bool>& BoolFlags) const = 0;
};

/**
 * Wrapper class around the flag condition struct used in the syntax tree
 */
struct FFlagConditionNode : public ICondNode
{
	FFlagCondition Condition;

	FFlagConditionNode(const FFlagCondition& InCond)
		: Condition(InCond)
	{
	}

	/**
	 * TODO: Implement
	 */
	virtual bool Evaluate(const TMap<FName, int32>& IntFlags,
		const TMap<FName, bool>& BoolFlags) const override
	{
		TO_IMPLEMENT(DialogueCondST, FString("Evaluate"));
		return true;
	}
};

/** Syntax Tree structure */
struct FBinaryCondNode : public ICondNode
{
	ELogicalOp Op;
	TUniquePtr<ICondNode> Left;
	TUniquePtr<ICondNode> Right;

	FBinaryCondNode(ELogicalOp InOp, TUniquePtr<ICondNode> InLeft, TUniquePtr<ICondNode> InRight)
		: Op(InOp), Left(MoveTemp(InLeft)), Right(MoveTemp(InRight))
	{
	}

	/** Recursively evaluates the tree based on the flag states */
	virtual bool Evaluate(const TMap<FName, int32>& IntFlags,
		const TMap<FName, bool>& BoolFlags) const override
	{
		if (Op == ELogicalOp::And)
		{
			return Left->Evaluate(IntFlags, BoolFlags)
				&& Right->Evaluate(IntFlags, BoolFlags);
		}
		if (Op == ELogicalOp::Or)
		{
			return Left->Evaluate(IntFlags, BoolFlags)
				|| Right->Evaluate(IntFlags, BoolFlags);
		}
		return false;
	}
};

UCLASS(BlueprintType)
class DIALOGUEPLUGIN_API UCondTreeWrapper : public UObject
{
    GENERATED_BODY()

public:
    /** Pointer to the root of the C++ tree (not exposed to BP) */
    TUniquePtr<ICondNode> InternalNode;

	/** String representation of the condition as written in .dgl file. Used for debugging. */
	FString CondString;

    void Init(TUniquePtr<ICondNode> InNode)
    {
        InternalNode = MoveTemp(InNode);
    }

    bool Evaluate(const TMap<FName, int32>& IntFlags, const TMap<FName, bool>& BoolFlags) const
    {
        return InternalNode ? InternalNode->Evaluate(IntFlags, BoolFlags) : false;
    }
};