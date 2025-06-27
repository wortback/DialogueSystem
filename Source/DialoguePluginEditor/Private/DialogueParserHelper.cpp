// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueParserHelper.h"

#include "Serialization/DialogueParser.h"

void UDialogueParserHelper::RunParser(UDialogueDataAsset* Asset)
{
    FString Path = FPaths::ProjectDir() / TEXT("DialogueChoices.dgl");

    //UDialogueDataAsset* NewAsset = NewObject<UDialogueDataAsset>(GetTransientPackage(), NAME_None, RF_Standalone);

    FDialogueParser Parser;
    if (Parser.ParseFile(Path, *Asset))
    {
        UE_LOG(LogTemp, Warning, TEXT("Parser finished successfully"));
    }
}
