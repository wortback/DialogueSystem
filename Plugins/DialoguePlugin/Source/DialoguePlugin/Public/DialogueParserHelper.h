// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueDataAsset.h"
#include "UObject/NoExportTypes.h"
#include "DialogueParserHelper.generated.h"

/**
 *
 */
UCLASS()
class DIALOGUEPLUGIN_API UDialogueParserHelper : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, CallInEditor)
	static void RunParser(UDialogueDataAsset* Asset);
};
