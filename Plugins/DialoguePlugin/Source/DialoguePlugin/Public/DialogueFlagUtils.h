// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueFlagUtils.generated.h"



UENUM(BlueprintType)
enum class EFlagCompSymbol : uint8
{
	GreaterThan UMETA(DisplayName = "GreaterThan"),
	LessThan UMETA(DisplayName = "LessThan"),
	GreaterEquals UMETA(DisplayName = "GreaterEquals"),
	LessEquals UMETA(DisplayName = "LessEquals"),
	Equals UMETA(DisplayName = "Equals"),
	None UMETA(DisplayName = "None")
};

inline EFlagCompSymbol FlagCompFromString(const FString& Input)
{
	const FString Normalized = Input.ToLower();

	if (Normalized == TEXT(">")) return EFlagCompSymbol::GreaterThan;
	if (Normalized == TEXT("<")) return EFlagCompSymbol::LessThan;
	if (Normalized == TEXT(">=")) return EFlagCompSymbol::GreaterEquals;
	if (Normalized == TEXT("<=")) return EFlagCompSymbol::LessEquals;
	if (Normalized == TEXT("==")) return EFlagCompSymbol::Equals;

	return EFlagCompSymbol::None;
}

inline FString FlagCompToString(EFlagCompSymbol Symbol)
{
	switch (Symbol)
	{
	case EFlagCompSymbol::GreaterThan:
		return TEXT(">");
	case EFlagCompSymbol::LessThan:
		return TEXT("<");
	case EFlagCompSymbol::GreaterEquals:
		return TEXT(">=");
	case EFlagCompSymbol::LessEquals:
		return TEXT("<=");
	case EFlagCompSymbol::Equals:
		return TEXT("==");
	case EFlagCompSymbol::None:
		return TEXT("None");
	default:
		return TEXT("Unknown");
	}
}



UENUM(BlueprintType)
enum class EFlagOperator : uint8
{
	Add UMETA(DisplayName = "Add"),
	Subtract UMETA(DisplayName = "Subtract"),
	Set UMETA(DisplayName = "Set"),
	None UMETA(DisplayName = "None")
};

inline EFlagOperator FlagOpFromString(const FString& Input)
{
	const FString Normalized = Input.ToLower();

	if (Normalized == TEXT("+") || Normalized == TEXT("add")) return EFlagOperator::Add;
	if (Normalized == TEXT("-") || Normalized == TEXT("subtract")) return EFlagOperator::Subtract;
	if (Normalized == TEXT("=") || Normalized == TEXT("set")) return EFlagOperator::Set;
	return EFlagOperator::None;
}

inline FString FlagOpToString(EFlagOperator Op)
{
	switch (Op)
	{
	case EFlagOperator::Add:
		return TEXT("Add");
	case EFlagOperator::Subtract:
		return TEXT("Subtract");
	case EFlagOperator::Set:
		return TEXT("Set");
	case EFlagOperator::None:
		return TEXT("None");
	default:
		return TEXT("Unknown");
	}
}
