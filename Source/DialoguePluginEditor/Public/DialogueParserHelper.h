// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialoguePlugin/Public/DialogueDataAsset.h"
#include "UObject/NoExportTypes.h"
#include "DialogueParserHelper.generated.h"

class UDialogueDataAsset;
/**
 *
 */
UCLASS(Blueprintable)
class DIALOGUEPLUGINEDITOR_API UDialogueParserHelper : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, CallInEditor)
	static UDialogueDataAsset* RunParser(FFilePath DGLFile);
};
