// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "DialogueFlag.h"
#include "DialogueDataAsset.generated.h"



UENUM(BlueprintType)
enum class EComparisonSymbol : uint8
{
	ECS_GreaterThan UMETA(DisplayName = "GreaterThan"),
	ECS_LessThan UMETA(DisplayName = "LessThan"),
	ECS_GreaterEquals UMETA(DisplayName = "GreaterEquals"),
	ECS_LessEquals UMETA(DisplayName = "LessEquals"),
	ECS_Equals UMETA(DisplayName = "Equals")
};

UENUM(BlueprintType)
enum class EFlagOperator : uint8
{
	EFO_Add UMETA(DisplayName = "Add"),
	EFO_Subtract UMETA(DisplayName = "Subtract"),
	EFO_Set UMETA(DisplayName = "Set"),
};


USTRUCT(BlueprintType)
struct FFlagCondition
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDialogueFlag* Flag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EFlagType FlagType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EComparisonSymbol ComparisonSymbol;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 IntValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool BoolValue;
};

USTRUCT(BlueprintType)
struct FFlagEffect
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDialogueFlag* Flag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EFlagType FlagType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EFlagOperator Operator;

	/** Value to be added/subtracted/set (depending on the operator) from the value in the flag */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 IntValue;

	/** Value the bool flag is gonna be set to */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool BoolValue;
};


#pragma region DialogueNodes
UCLASS(Abstract)
class UDialogueNode : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	FName ID;

public:
	FName GetID() const { return ID; }
};

UCLASS(Blueprintable)
class UDialogueSentence : public UDialogueNode
{
	GENERATED_BODY()

public:
	/** Speaker name to be displayed */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	FString Speaker;

	/** What the speaker is currently saying */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	FString Text;

	/** ID of the next node to jump to */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	FName NextID;
};

/**
 * A single conditional path evaluated during a fork.
 * If RequiredFlagState is satisfied, this branch is chosen and FirstID is used to enter its Content map.
 */
UCLASS(Blueprintable)
class UDialogueBranch : public UDialogueNode
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	TMap<FName, UDialogueNode*> Content;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	TArray<FFlagCondition> RequiredFlagState;

	/** ID of the first node in the content map to jump to */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	FName FirstID;

	/** Higher priority branch is chosen if more than one branch's RequiredFlagState is satisfied
	 * The higher is the value, the higher is the priority
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	int32 Priority = 0;
};

UCLASS(Blueprintable)
class UDialogueChoice : public UDialogueNode
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	FString Text;

	/** Flags that will change state after this response is selected */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	TArray<FFlagEffect> AffectedFlags;

	/** Required conditions for this response to be available */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	TArray<FFlagCondition> Conditions;

	/** Jumps to the ID is this choice is selected */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	FName GotoID;
};

UCLASS(Blueprintable)
class UDialogueFork : public UDialogueNode
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<FName, TObjectPtr<UDialogueNode>> DialogueMap;
};
