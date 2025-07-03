// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DialogueFlagUtils.h"
#include "DialogueFlag.generated.h"



/**
 * This class represents flags that can be used in the dialogue to track certain states.
 * E.g. they can track player choices or relationships between the player and other characters.
 * Flags can be boolean or numeric. 
 */
UCLASS(NotBlueprintable)
class DIALOGUEPLUGIN_API UDialogueFlag : public UDataAsset
{
	GENERATED_BODY()
	
public:
	/** Must be identical to the flag name used in the text file */
	UPROPERTY(EditAnywhere, Category="Flag Data")
	FName FlagName;

	/** Just for reference. Is not displayed anywhere */
	UPROPERTY(EditAnywhere, Category = "Flag Data")
	FString FlagDescription;

	/** Numeric or boolean */
	UPROPERTY(EditAnywhere, Category = "Flag Data")
	EFlagType FlagType;

	/** If bool, this value will be taken into account when evaluating */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool BoolValue;

	/** If numeric, this value will be taken into account when evaluating */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 IntValue = INT_MAX;

public:
	/** Validates that the flag is either boolean or numeric but never both. */
	bool Validate() const
	{
		return (FlagType == EFlagType::Numeric && IntValue != INT_MAX)
		|| (FlagType == EFlagType::Boolean && IntValue == INT_MAX);
	}
};