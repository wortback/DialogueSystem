// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "DialogueFlag.h"
#include "DialogueFlagUtils.h"
#include "DialogueLogging.h"
#include "DialogueDataAsset.generated.h"


USTRUCT(BlueprintType)
struct FFlagCondition
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString FlagName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EFlagCompSymbol ComparisonSymbol;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 IntValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool BoolValue;

	void LogCondition() const
	{
		if (IntValue != INT_MAX)
		{
			DLOG(Log, "		[Condition] %s %s %d", *FlagName,
				*FlagCompToString(ComparisonSymbol), IntValue);
		}
		else
			DLOG(Log, "		[Condition] %s %s %s", *FlagName,
				*FlagCompToString(ComparisonSymbol), *LexToString(BoolValue));
	}
};

USTRUCT(BlueprintType)
struct FFlagEffect
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString FlagName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EFlagOperator Operator;

	/** Value to be added/subtracted/set (depending on the operator) from the value in the flag */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 IntValue;

	/** Value the bool flag is gonna be set to */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool BoolValue;

	void LogEffect() const
	{
		if (IntValue != INT_MAX)
		{
			DLOG(Log, "		[Set] %s %s %d", *FlagName,
				*FlagOpToString(Operator), IntValue);
		}
		else
			DLOG(Log, "		[Set] %s %s %s", *FlagName,
				*FlagOpToString(Operator), *LexToString(BoolValue));
	}
};


#pragma region DialogueNodes
UCLASS(Abstract)
class UDialogueNodeBase : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	FName ID;

	virtual void LogNode() const {};
};

UCLASS(Abstract)
class UDialogueNodeLinkable : public UDialogueNodeBase
{
	GENERATED_BODY()

public:
	/** ID of the next node to jump to */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	FName NextID;
};

UCLASS(Blueprintable)
class UDialogueFlagSet : public UDialogueNodeLinkable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	FFlagEffect FlagEffect;

	virtual void LogNode() const override
	{
		FlagEffect.LogEffect();
	}
};

UCLASS(Blueprintable)
class UDialogueGotoNode : public UDialogueNodeLinkable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	FName GotoID;

	virtual void LogNode() const override
	{
		DLOG(Log, "		[Goto %s] Goto Node jumps to: %s", *ID.ToString(), *GotoID.ToString());
	}
};

UCLASS(Blueprintable)
class UDialogueSentence : public UDialogueNodeLinkable
{
	GENERATED_BODY()

public:
	/** Speaker name to be displayed */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	FString Speaker;

	/** What the speaker is currently saying */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	FString Text;

	virtual void LogNode() const override
	{
		DLOG(Log, "[Sentence %s] (%s): (%s)", *ID.ToString(), *Speaker, *Text);
	}
};

/**
 * A single conditional path evaluated during a fork.
 * If RequiredFlagState is satisfied, this branch is chosen and FirstID is used to enter its Content map.
 */
UCLASS(Blueprintable)
class UDialogueBranch : public UDialogueNodeLinkable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadOnly, Category = "Dialogue")
	TMap<FName, UDialogueNodeBase*> Content;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	TArray<FFlagCondition> RequiredFlagState;

	/** ID of the first node in the content map to jump to */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	FName FirstID;

	virtual void LogNode() const override
	{
		DLOG(Log, "[Branch %s] Contains %d nodes.", *ID.ToString(), Content.Num());
		DLOG(Log, "-------------------- START BRANCH -----------------------");
		for (const auto& Node : Content)
		{
			Node.Value->LogNode();
		}
		DLOG(Log, "-------------------- END BRANCH -----------------------");
	}
};

USTRUCT(BlueprintType)
struct FDialogueChoiceOption
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Choice Option")
	FString Text;

	/** Flags that will change state after this response is selected */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Choice Option")
	TArray<FFlagEffect> AffectedFlags;

	/** Required conditions for this response to be available */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Choice Option")
	TArray<FFlagCondition> Conditions;

	/** opt. Jumps to the ID is this choice is selected */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Choice Option")
	FName GotoID;

	void LogOption() const
	{
		if (!GotoID.IsNone())
		{
			DLOG(Log, "   [Option] %s (goto %s)", *Text, *GotoID.ToString());
		}
		else
			DLOG(Log, "   [Option] %s", *Text);

		for (const auto& Cond : Conditions)
		{
			Cond.LogCondition();
		}

		for (const auto& Effect : AffectedFlags)
		{
			Effect.LogEffect();
		}
	}
};

UCLASS(Blueprintable)
class UDialogueChoice : public UDialogueNodeLinkable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	TArray<FDialogueChoiceOption> Options;

	virtual void LogNode() const override
	{
		DLOG(Log, "[Choice %s] Contains %d options.", *ID.ToString(), Options.Num());
		DLOG(Log, "Listing the contents:");
		for (const auto& Opt : Options)
		{
			Opt.LogOption();
		}
	}
};

UCLASS(Blueprintable)
class UDialogueFork : public UDialogueNodeLinkable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	TArray<UDialogueBranch*> Branches;
};
#pragma endregion DialogueNodes

/**
 *
 */
UCLASS(Blueprintable)
class DIALOGUEPLUGIN_API UDialogueDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName DialogueName;

	UPROPERTY(EditAnywhere, Instanced, BlueprintReadOnly)
	TMap<FName, TObjectPtr<UDialogueNodeBase>> DialogueMap;
};
