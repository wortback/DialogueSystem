// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DialogueFlag.generated.h"


#define UNDEFINT -1000000

UENUM(BlueprintType)
enum class EFlagType : uint8
{
	Boolean,
	Numeric
};

/**
 * 
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
	int32 IntValue = UNDEFINT;

public:
	bool Validate() const
	{
		return (FlagType == EFlagType::Numeric && IntValue != UNDEFINT)
		|| (FlagType == EFlagType::Boolean && IntValue == UNDEFINT);
	}
};