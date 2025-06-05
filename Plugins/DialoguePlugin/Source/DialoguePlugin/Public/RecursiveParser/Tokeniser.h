// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


enum class ECondTokenType
{
	Identifier,     // Flag name
	NumberLiteral,  // Integers e.g. 1, 2, etc
	BoolLiteral,    // "true" or "false"
	CompSymbol,     // "==", "!=", ">", ">=", "<", "<="
	AndOp,          // &&
	OrOp,           // ||
	LParen,         // (
	RParen,         // )
	EndOfInput,
	Invalid
};

struct FCondToken
{
	ECondTokenType Type;
	FString        Text;   // the raw text of the token
};

/**
 * This method parses 'if' and 'condition' expressions in
 *		1. [if expr]
 *		2. [condition expr]
 *  and turns the string into tokens that are later assembled in conditional nodes in a tree
 * 
 */
static void TokeniseCondition(const FString& Input, TArray<FCondToken>& OutTokens)
{
	int32 i = 0;
	while (i < Input.Len())
	{
		// we skip whitespaces
		if (FChar::IsWhitespace(Input[i]))
		{
			i++;
			continue;
		}

		// check brackets
		if (Input[i] == TEXT('(') || Input[i] == TEXT(')'))
		{
			OutTokens.Add({ ECondTokenType::LParen, Input.Mid(i, 1) });
			i++;
			continue;
		}

		// check two-character operators: &&, ||, ==, !=, >=, <=
		if (i + 1 < Input.Len())
		{
			FString Two = Input.Mid(i, 2);
			if (Two.Equals(TEXT("&&")))
			{
				OutTokens.Add({ ECondTokenType::AndOp, TEXT("&&") });
				i += 2;
				continue;
			}
			if (Two.Equals(TEXT("||")))
			{
				OutTokens.Add({ ECondTokenType::OrOp, TEXT("||") });
				i += 2;
				continue;
			}
			if (Two.Equals(TEXT("==")) || Two.Equals(TEXT("!=")) ||
				Two.Equals(TEXT(">=")) || Two.Equals(TEXT("<=")))
			{
				OutTokens.Add({ ECondTokenType::CompSymbol, Two });
				i += 2;
				continue;
			}
		}

		// check one-char operators
		if (Input[i] == TEXT('>') || Input[i] == TEXT('<'))
		{
			OutTokens.Add({ ECondTokenType::CompSymbol, Input.Mid(i, i)});
			i++;
			continue;
		}

		// Identifier or literal: [A-Za-z_][A-Za-z0-9_]* or digits
		if (FChar::IsAlpha(Input[i]) || Input[i] == TEXT('_'))
		{
			int32 Start = i;
			while (i < Input.Len() && (FChar::IsAlnum(Input[i]) || Input[i] == TEXT('_')))
			{
				i++;
			}
			FString Word = Input.Mid(Start, i - Start);

			// Check if this is a bool literal first
			if (Word.Equals(TEXT("true"), ESearchCase::IgnoreCase) ||
				Word.Equals(TEXT("false"), ESearchCase::IgnoreCase))
			{
				OutTokens.Add({ ECondTokenType::BoolLiteral, Word.ToLower() });
			}
			else
			{
				OutTokens.Add({ ECondTokenType::Identifier, Word });
			}
			continue;
		}

		// check integer literals
		if (FChar::IsDigit(Input[i]))
		{
			int32 Start = i;
			while (i < Input.Len() && FChar::IsDigit(Input[i]))
			{
				i++;
			}
			FString Num = Input.Mid(Start, i - Start);
			OutTokens.Add({ ECondTokenType::NumberLiteral, Num });
			continue;
		}

		// if no match,  mark invalid
		OutTokens.Add({ ECondTokenType::Invalid, FString(Input.Mid(i, 1)) });
		i++;
	}

	OutTokens.Add({ ECondTokenType::EndOfInput, TEXT("") });
}