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

	void LogCondition(int32 Indent) const
	{
		FString Padding;
		if (Indent > 0)
		{
			Padding = FString::ChrN(Indent, ' ');
		}
		if (IntValue != INT_MAX)
		{
			DLOG(Log, "%s[Condition] %s %s %d", *Padding, *FlagName,
				*FlagCompToString(ComparisonSymbol), IntValue);
		}
		else
			DLOG(Log, "%s[Condition] %s %s %s", *Padding, *FlagName,
				*FlagCompToString(ComparisonSymbol), *LexToString(BoolValue));
	}

	FString ToString() const
	{
		if (ComparisonSymbol == EFlagCompSymbol::None)
		{
			return "";
		}

		if (IntValue != INT_MAX)
		{
			return FString::Printf(TEXT("%s %s %d"), 
				*FlagName, *FlagCompToString(ComparisonSymbol), IntValue);
		}
		return FString::Printf(TEXT("%s %s %s"), 
			*FlagName, *FlagCompToString(ComparisonSymbol), *LexToString(BoolValue));
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

	void LogEffect(int32 Indent) const
	{
		FString Padding;
		if (Indent > 0)
		{
			Padding = FString::ChrN(Indent, ' ');
		}

		if (IntValue != INT_MAX)
		{
			DLOG(Log, "%s[Set] %s %s %d", *Padding, *FlagName,
				*FlagOpToString(Operator), IntValue);
		}
		else
			DLOG(Log, "%s[Set] %s %s %s", *Padding, *FlagName,
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

	virtual void LogNode(int32 Indent) const {};
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

	virtual void LogNode(int32 Indent) const override
	{
		FlagEffect.LogEffect(Indent);
	}
};

UCLASS(Blueprintable)
class UDialogueGotoNode : public UDialogueNodeLinkable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	FName GotoID;

	virtual void LogNode(int32 Indent) const override
	{
		FString Padding;
		if (Indent > 0)
		{
			Padding = FString::ChrN(Indent, ' ');
		}
		DLOG(Log, "%s[Goto %s] Goto Node jumps to: %s", *Padding, *ID.ToString(), *GotoID.ToString());
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

	virtual void LogNode(int32 Indent) const override
	{
		FString Padding;
		if (Indent > 0)
		{
			Padding = FString::ChrN(Indent, ' ');
		}
		DLOG(Log, "%s[Sentence %s] (%s): (%s)", *Padding, *ID.ToString(), *Speaker, *Text);
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

	/** ID of the first node in the content map to jump to */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	FName FirstID;

	virtual void LogNode(int32 Indent) const override
	{
		FString Padding;
		if (Indent > 0)
		{
			Padding = FString::ChrN(Indent, ' ');
		}

		DLOG(Log, "%s-------------------- START BRANCH -----------------------", *Padding);
		for (const auto& Node : Content)
		{
			Node.Value->LogNode(Indent + 1);
		}
		DLOG(Log, "%s-------------------- END BRANCH -----------------------", *Padding);
	}

	void LogNodeFromFork(int32 Indent, int32 BranchIndex)
	{
		FString Padding;
		if (Indent > 0)
		{
			Padding = FString::ChrN(Indent, ' ');
		}

		DLOG(Log, "%s-------------------- START BRANCH %d -----------------------", *Padding, BranchIndex);
		for (const auto& Node : Content)
		{
			Node.Value->LogNode(Indent + 1);
		}
		DLOG(Log, "%s-------------------- END BRANCH %d -----------------------", *Padding, BranchIndex);
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

	void LogOption(int32 Indent) const
	{
		FString Padding;
		if (Indent > 0)
		{
			Padding = FString::ChrN(Indent, ' ');
		}

		if (!GotoID.IsNone())
		{
			DLOG(Log, "%s[Option] %s (goto %s)", *Padding, *Text, *GotoID.ToString());
		}
		else
			DLOG(Log, "%s[Option] %s", *Padding, *Text);

		for (const auto& Cond : Conditions)
		{
			Cond.LogCondition(Indent);
		}

		for (const auto& Effect : AffectedFlags)
		{
			Effect.LogEffect(Indent);
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

	virtual void LogNode(int32 Indent) const override
	{
		FString Padding;
		if (Indent > 0)
		{
			Padding = FString::ChrN(Indent, ' ');
		}

		for (const auto& Opt : Options)
		{
			Opt.LogOption(Indent + 1);
		}
	}
};

USTRUCT(BlueprintType)
struct FBranchWithCondition
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	FFlagCondition Condition;

	UPROPERTY(EditAnywhere, Instanced, BlueprintReadOnly, Category = "Dialogue")
	UDialogueBranch* Branch = nullptr;
};

UCLASS(Blueprintable)
class UDialogueFork : public UDialogueNodeLinkable
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nesting")
	int32 NestingLevel = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	TArray<FBranchWithCondition> Branches;

	virtual void LogNode(int32 Indent) const override
	{
		FString Padding;
		if (Indent > 0)
		{
			Padding = FString::ChrN(Indent, ' ');
		}
		DLOG(Log, "%s-------------------- START FORK -----------------------", *Padding);
		int32 Counter = 0;
		for (const auto& Pair : Branches)
		{
			Pair.Condition.LogCondition(Indent + 1);
			Pair.Branch->LogNodeFromFork(Indent + 1, Counter);
			Counter++;
		}
		DLOG(Log, "%s-------------------- END FORK -----------------------", *Padding);
	}
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
