// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueDataAsset.h"
#include "DialogueLogging.h"


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

	virtual bool Evaluate(const TMap<FName, int32>& IntFlags,
		const TMap<FName, bool>& BoolFlags) const override
	{
		FName FlagName = FName(Condition.FlagName);

		// Boolean flag check
		if (Condition.IntValue == INT_MAX)
		{
			const bool* Found = BoolFlags.Find(FlagName);
			bool Value = Found ? *Found : false;

			UE_LOG(LogTemp, Log, TEXT("[Evaluate] Bool Flag: %s, Expected: %s, Actual: %s, Comparison: %s"),
				*FlagName.ToString(),
				Condition.BoolValue ? TEXT("true") : TEXT("false"),
				Value ? TEXT("true") : TEXT("false"),
				*UEnum::GetValueAsString(Condition.ComparisonSymbol));

			if (Condition.ComparisonSymbol == EFlagCompSymbol::Equals)
				return Value == Condition.BoolValue;
			if (Condition.ComparisonSymbol == EFlagCompSymbol::NotEquals)
				return Value != Condition.BoolValue;
		}
		// Integer flag check
		else
		{
			const int32* Found = IntFlags.Find(FlagName);
			int32 Value = Found ? *Found : 0;

			UE_LOG(LogTemp, Log, TEXT("[Evaluate] Int Flag: %s, Expected: %d, Actual: %d, Comparison: %s"),
				*FlagName.ToString(),
				Condition.IntValue,
				Value,
				*UEnum::GetValueAsString(Condition.ComparisonSymbol));

			switch (Condition.ComparisonSymbol)
			{
			case EFlagCompSymbol::Equals:
				return Value == Condition.IntValue;
			case EFlagCompSymbol::NotEquals:
				return Value != Condition.IntValue;
			case EFlagCompSymbol::GreaterThan:
				return Value > Condition.IntValue;
			case EFlagCompSymbol::GreaterEquals:
				return Value >= Condition.IntValue;
			case EFlagCompSymbol::LessThan:
				return Value < Condition.IntValue;
			case EFlagCompSymbol::LessEquals:
				return Value <= Condition.IntValue;
			default:
				UE_LOG(LogTemp, Warning, TEXT("[Evaluate] Unknown comparison symbol."));
				return false;
			}
		}

		UE_LOG(LogTemp, Warning, TEXT("[Evaluate] Invalid flag condition structure for flag %s."), *FlagName.ToString());
		return false;
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