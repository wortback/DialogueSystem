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
		const FString Pad = FString::ChrN(Indent, ' ');
		if (ComparisonSymbol == EFlagCompSymbol::None)
		{
			// nothing to log
			return;
		}
		if (IntValue != INT_MAX)
		{
			DLOG(Log, "%s[Condition] %s %s %d", *Pad, *FlagName,
				*FlagCompToString(ComparisonSymbol), IntValue);
		}
		else
		{
			DLOG(Log, "%s[Condition] %s %s %s", *Pad, *FlagName,
				*FlagCompToString(ComparisonSymbol), *LexToString(BoolValue));
		}
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
class DIALOGUEPLUGIN_API UDialogueNodeBase : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	FName ID;

	virtual void LogNode(int32 Indent) const {};
};

UCLASS(Abstract)
class DIALOGUEPLUGIN_API UDialogueNodeLinkable : public UDialogueNodeBase
{
	GENERATED_BODY()

public:
	/** ID of the next node to jump to */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	FName NextID;
};

UCLASS(Blueprintable)
class DIALOGUEPLUGIN_API UDialogueFlagSet : public UDialogueNodeLinkable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	FFlagEffect FlagEffect;

	virtual void LogNode(int32 Indent) const override
	{
		const FString Pad = FString::ChrN(Indent, ' ');
		if (FlagEffect.IntValue != INT_MAX)
		{
			DLOG(Log, "%s[Set] %s %s %d", *Pad, *FlagEffect.FlagName,
				*FlagOpToString(FlagEffect.Operator), FlagEffect.IntValue);
		}
		else
		{
			DLOG(Log, "%s[Set] %s %s %s", *Pad, *FlagEffect.FlagName,
				*FlagOpToString(FlagEffect.Operator), *LexToString(FlagEffect.BoolValue));
		}
	}
};

UCLASS(Blueprintable)
class DIALOGUEPLUGIN_API UDialogueGotoNode : public UDialogueNodeLinkable
{
	GENERATED_BODY()

public:
	virtual void LogNode(int32 Indent) const override
	{
		const FString Pad = FString::ChrN(Indent, ' ');
		DLOG(Log, "%s[Goto] %s -> %s", *Pad, *ID.ToString(), *NextID.ToString());
	}
};

UCLASS(Blueprintable)
class DIALOGUEPLUGIN_API UDialogueSentence : public UDialogueNodeLinkable
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
		const FString Pad = FString::ChrN(Indent, ' ');
		DLOG(Log, "%s[Sentence] %s: \"%s\"", *Pad, *Speaker, *Text);
	}
};

/**
 * A single conditional path evaluated during a fork.
 * If RequiredFlagState is satisfied, this branch is chosen and FirstID is used to enter its Content map.
 */
UCLASS(Blueprintable)
class DIALOGUEPLUGIN_API UDialogueBranch : public UDialogueNodeLinkable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadOnly, Category = "Dialogue")
	TMap<FName, TObjectPtr<UDialogueNodeBase>> Content;

	/** ID of the first node in the content map to jump to */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	FName FirstID;

	virtual void LogNode(int32 Indent) const override
	{
		const FString Pad = FString::ChrN(Indent, ' ');
		DLOG(Log, "%s[Branch] ID=%s", *Pad, *ID.ToString());
		// Recurse into each Content entry:
		for (const auto& Pair : Content)
		{
			if (Pair.Value)
			{
				Pair.Value->LogNode(Indent + 2);
			}
		}
	}

	void LogNodeFromFork(int32 Indent, int32 BranchIndex) const
	{
		// We assume the caller already logged [Branch %d] Condition: ... (with Indent - 2 spaces).
		// Here, we just dump each child node at this indent level.
		const FString Pad = FString::ChrN(Indent, ' ');

		if (Content.Num() == 0)
		{
			// If the branch has no content, show (empty)
			DLOG(Log, "%s  (empty)", *Pad);
			return;
		}

		for (const auto& Pair : Content)
		{
			if (Pair.Value)
			{
				// Each child node logs itself with its own indent
				Pair.Value->LogNode(Indent);
			}
		}
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

	/** Tree object for complex conditions */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
    class UCondTreeWrapper* TreeWrapper = nullptr;

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

		for (const auto& Effect : AffectedFlags)
		{
			Effect.LogEffect(Indent+1);
		}
	}
};

UCLASS(Blueprintable)
class DIALOGUEPLUGIN_API UDialogueChoice : public UDialogueNodeLinkable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	TArray<FDialogueChoiceOption> Options;

	virtual void LogNode(int32 Indent) const override;
};

USTRUCT(BlueprintType)
struct FBranchWithCondition
{
	GENERATED_BODY()

	/** Tree object for complex conditions */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UCondTreeWrapper* TreeWrapper = nullptr;

	UPROPERTY(EditAnywhere, Instanced, BlueprintReadOnly, Category = "Dialogue")
	UDialogueBranch* Branch = nullptr;
};

/** * A node that contains multiple if/else-branches, each with its own condition.
 * The conditions are evaluated in order, and the first one that matches is executed.
 * If no conditions match, the last branch (if any) is executed as an "else" case.
 */
UCLASS(Blueprintable)
class DIALOGUEPLUGIN_API UDialogueFork : public UDialogueNodeLinkable
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nesting")
	int32 NestingLevel = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	TArray<FBranchWithCondition> Branches;

	virtual void LogNode(int32 Indent) const override;
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
