// Fill out your copyright notice in the Description page of Project Settings.


#include "Serialization/ParserState.h"

#include <DialogueLogging.h>

#include "DialogueDataAsset.h"
#include "Serialization/DialogueParserContext.h"


FSentenceState FParserState::SentenceState;
FChoiceState FParserState::ChoiceState;
FBranchState FParserState::BranchState;
FBranchDispatcherState FParserState::BranchDispatcher;
FChoiceTextState FParserState::ChoiceTextState;
FChoiceMetaState FParserState::ChoiceMetaState;
FMetaState FParserState::MetaState;
FErrorState FParserState::Error;
FDispatcherState FParserState::Dispatcher;
FExtractFlagsState FParserState::ExtractFlagsState;



#pragma region FSentenceState
FParserState* FSentenceState::ProcessLine(const FString& Line, FDialogueParserContext& Context)
{
	DLOG(Log, "Parsing a sentence...");

	// Parse the line into speaker and text and create a sentence node
	FString Speaker, Text;
	if (!ParseSentence(Line, Speaker, Text)) return &FParserState::SentenceState;

	// Set previous node and zero the current one
	Context.PrevNode = Context.CurrentNode;
	Context.CurrentNode = nullptr;

	FName ID = GenerateID(Context);
	UDialogueSentence* Sentence;
	if (Context.BranchNode)
		Sentence = Context.AddNodeBranch<UDialogueSentence>(ID, FString("SentenceNode"));
	else
		Sentence = Context.AddNode<UDialogueSentence>(ID, FString("SentenceNode"));

	Sentence->ID = ID;
	Sentence->Speaker = Speaker.TrimStartAndEnd();
	Sentence->Text = Text.TrimStartAndEnd().Replace(TEXT("\""), TEXT(""));

	// check if there's a previous node is a chain node and set its NextID to this one
	Context.TryLinkNodes(ID);

	Context.CurrentNode = Sentence;
	return &FParserState::Dispatcher;
}

bool FSentenceState::ParseSentence(const FString& Line, FString& Speaker, FString& Text)
{
	if (!Line.Split(":", &Speaker, &Text, ESearchCase::IgnoreCase))
	{
		DLOG(Error, "Missing ':' in sentence line: %s", *Line);
		return false;
	}

	const FString TextTrimmed = Text.TrimStartAndEnd();
	if (!TextTrimmed.StartsWith(TEXT("\"")) || !TextTrimmed.EndsWith(TEXT("\"")))
	{
		DLOG(Error, "Invalid format for line: %s", *Line);
		return false;
	}
	Speaker = Speaker.TrimStartAndEnd();
	Text = TextTrimmed.Replace(TEXT("\""), TEXT(""));
	return true;
}

#pragma endregion

#pragma region FChoiceState
FParserState* FChoiceState::ProcessLine(const FString& Line, FDialogueParserContext& Context)
{
	DLOG(Log, "Parsing a choice...");

	// If we are not in the choice node, create a new one
	//  => In means it's the first [choice] keyword we encounter
	if (!Context.CurrentNode || !Context.CurrentNode->IsA(UDialogueChoice::StaticClass()))
	{
		// Create a new choice node
		FName ID = GenerateID(Context);

		// Add the choice node to the branch if we are in one
		UDialogueChoice* Choice;
		if (Context.BranchNode)
			Choice = Context.AddNodeBranch<UDialogueChoice>(ID, FString("ChoiceNode"));

		else
			Choice = Context.AddNode<UDialogueChoice>(ID, FString("ChoiceNode"));
		Choice->ID = ID;

		// Create a struct for this choice option and add it to the node
		DLOG(Log, "Creating a new choice option...");
		FDialogueChoiceOption NewOption;
		Choice->Options.Add(NewOption);

		// Update Prev and Current in the context
		Context.PrevNode = Context.CurrentNode;
		Context.CurrentNode = Choice;

		Context.TryLinkNodes(ID);

		// Increase the indentation level <- we are now in the choice option block
		Context.IndentationLevel++;

		return &FParserState::ChoiceTextState;
	}

	// If we are already in a choice node, just add a new choice option
	FDialogueChoiceOption NewOption;
	UDialogueChoice* Choice = Cast<UDialogueChoice>(Context.CurrentNode);
	if (!Choice)
	{
		PARSER_ERROR(Line);
		return &FParserState::Error;
	}
	DLOG(Log, "Creating a new choice option...");
	Choice->Options.Add(NewOption);

	// Increase the indentation level <- we are now in the choice option block
	Context.IndentationLevel++;

	return &FParserState::ChoiceTextState;
}

FParserState* FChoiceTextState::ProcessLine(const FString& Line, FDialogueParserContext& Context)
{
	DLOG(Log, "Parsing choice option text...");

	if (GetIndentLevel(Line) != Context.IndentationLevel)
	{
		PARSER_ERROR_INDENTATION(Line, Context.IndentationLevel, GetIndentLevel(Line));
		return &FParserState::Error;
	}

	UDialogueChoice* Choice = Cast<UDialogueChoice>(Context.CurrentNode);
	if (!Choice)
	{
		PARSER_ERROR(Line);
		return &FParserState::Error;
	}

	FString ChoiceText = Line.TrimStartAndEnd();
	if (!ChoiceText.StartsWith("\"") || !ChoiceText.EndsWith("\""))
	{
		DLOG(Error, "Choice option text should be surrounded by double quotation marks.");
		return &FParserState::Error;
	}

	Choice->Options.Last().Text = ChoiceText.TrimStartAndEnd().Replace(TEXT("\""), TEXT(""));
	Choice->Options.Last().Text = Line.TrimStartAndEnd();
	DLOG(Log, "Choice option text: %s", *Line.TrimStartAndEnd());
	return &FParserState::ChoiceMetaState;
}

FParserState* FChoiceMetaState::ProcessLine(const FString& Line, FDialogueParserContext& Context)
{
	DLOG(Log, "Checking if there's any meta available for the choice option...");
	if (CanParseMeta(Line))
	{
		DLOG(Log, "Parsing meta data for the choice option...");
		// TODO: Implement meta parsing for choice options

		if (Line.Contains("goto"))
		{
			// Check if GotoID is not empty and warn of goto redefinition
			UDialogueChoice* Choice = Cast<UDialogueChoice>(Context.CurrentNode);
			if (Choice->Options.Last().GotoID != FName(""))
			{
				DLOG(Warning, "GotoID [%s] is already set for this choice option [%s]! It will be overridden.",
					*Choice->Options.Last().GotoID.ToString(), *Choice->Options.Last().Text);
			}

			FString BranchName;
			if (!MetaState.ParseGotoName(Line, BranchName)) return &FParserState::Error;

			DLOG(Log, "Adding goto to a choice option: %s", *BranchName);

			Choice->Options.Last().GotoID = FName(BranchName);
		}

		// We return this state to check if there's any more metadata on the next line
		return &FParserState::ChoiceMetaState;
	}

	DLOG(Log, "No meta data found for the choice option...");
	// Means we are out of the choice option block
	Context.IndentationLevel--;
	return Dispatcher.ProcessLine(Line, Context);
}

#pragma endregion

#pragma region FBranchState
FParserState* FBranchState::ProcessLine(const FString& Line, FDialogueParserContext& Context)
{
	DLOG(Log, "Parsing a branch...");

	// Prohibit branch inside a branch
	if (Context.BranchNode)
	{
		DLOG(Error, "Nested branches are not supported! Please split it into two separate branches.")
			return &FParserState::Error;
	}

	// Create a new branch node
	// Branches' IDs are uniques and are set to the branch name
	FString BranchName;
	if (!ParseBranchName(Line, BranchName)) return &FParserState::Error;
	FName ID = FName(BranchName);

	// Check if the branch with this name has been defined already
	if (Context.AssetBeingBuilt->DialogueMap.Contains(ID))
	{
		DLOG(Error, "Branch '%s' is multiply defined!", *ID.ToString());
		return &FParserState::Error;
	}

	UDialogueBranch* Branch = Context.AddNode<UDialogueBranch>(ID, FString("BranchNode"));
	Branch->ID = ID;

	Context.PrevNode = Context.CurrentNode;
	// check if there's a previous node is a chain node and set its NextID to this one
	Context.TryLinkNodes(ID);

	// Update Prev and Current in the context
	Context.CurrentNode = nullptr;
	Context.BranchNode = Branch;

	// Increase the indentation level <- we are now in the choice option block
	Context.IndentationLevel++;

	return &FParserState::BranchDispatcher;
}

bool FBranchState::ParseBranchName(const FString& Line, FString& BranchName)
{
	return ParseNameFromLine(Line, BranchName, TEXT("branch keyword"));
}

#pragma endregion

FParserState* FMetaState::ProcessLine(const FString& Line, FDialogueParserContext& Context)
{
	DLOG(Log, "Parsing meta...");

	if (Context.ExtractedTag.StartsWith("goto"))
	{
		FString BranchName;
		if (!ParseGotoName(Line, BranchName)) return &FParserState::Error;

		if (Context.BranchNode)
		{
			DLOG(Log, "Adding goto to a branch: %s", *BranchName);
			Context.BranchNode->GotoID = FName(BranchName);
			return &FParserState::BranchDispatcher;
		}
		DLOG(Error, "Goto is not available outside a choice or branch!");
		return &FParserState::Error;
	}

	if (Context.ExtractedTag.StartsWith("set"))
	{
		FParsedFlag Parsed;
		if (!ExtractFlagsState.ParseFlagExpression(Line, Parsed))
			return &FParserState::Error;

		// Set doesn't allow comparison symbols
		if (Parsed.Comp != EFlagCompSymbol::None)
		{
			DLOG(Error, "You cannot use comparison operators with 'set' keyword!");
			return &FParserState::Error;
		}

		// TODO: Update the dialogue asset with the parsed data

		else
		{
			if (Context.BranchNode)
				return &FParserState::BranchDispatcher;
			return &FParserState::Dispatcher;
		}
	}

	if (Context.ExtractedTag.StartsWith("condition"))
	{
		FParsedFlag Parsed;
		if (!ExtractFlagsState.ParseFlagExpression(Line, Parsed))
			return &FParserState::Error;

		// Set doesn't allow comparison symbols
		if (Parsed.Operator != EFlagOperator::None)
		{
			DLOG(Error, "You cannot use assignment operators with 'condition' keyword!");
			return &FParserState::Error;
		}

		// TODO: Update the dialogue asset with the parsed data

		else
		{
			if (Context.BranchNode)
				return &FParserState::BranchDispatcher;
			return &FParserState::Dispatcher;
		}
	}

	return &FParserState::Error;
}

bool FMetaState::ParseGotoName(const FString& Line, FString& BranchName)
{
	return ParseNameFromLine(Line, BranchName, TEXT("goto-keyword"));
}

FParserState* FErrorState::ProcessLine(const FString& Line, FDialogueParserContext& Context)
{
	DLOG(Error, "Parser has failed to parse the file!");
	return nullptr;
}

FParserState* FDispatcherState::ProcessLine(const FString& Line, FDialogueParserContext& Context)
{
	// Check if we are in a branch node and give the control over to the branch dispatcher
	if (Context.BranchNode)
	{
		return BranchDispatcher.ProcessLine(Line, Context);
	}

	return Dispatch(Line, Context);
}

FParserState* FDispatcherState::Dispatch(const FString& Line, FDialogueParserContext& Context)
{
	if (GetIndentLevel(Line) != Context.IndentationLevel)
	{
		PARSER_ERROR_INDENTATION(Line, Context.IndentationLevel, GetIndentLevel(Line));
		return &FParserState::Error;
	}

	FString Tag;
	if (!ExtractTag(Line, Tag)) return &FParserState::Error;
	Tag = Tag.ToLower();

	Context.ExtractedTag = Tag;

	if (Tag.StartsWith("choice"))
		return ChoiceState.ProcessLine(Line, Context);
	if (Tag.StartsWith("branch"))
		return BranchState.ProcessLine(Line, Context);
	if (Tag.StartsWith("goto") || Tag.StartsWith("set") || Tag.StartsWith("condition"))
		return MetaState.ProcessLine(Line, Context);
	if (Tag == "")
		return SentenceState.ProcessLine(Line, Context);

	return &FParserState::Error;
}

FParserState* FBranchDispatcherState::ProcessLine(const FString& Line, FDialogueParserContext& Context)
{
	// It's up do the dispatcher to check when we exit the branch
	// For that we check the indentation level

	// If the curr level is smaller than the context level, we are out of the branch
	if (GetIndentLevel(Line) < Context.IndentationLevel)
	{
		// Is the indentation level is smaller, it means, we are out of the branch
		Context.IndentationLevel--;
		DLOG(Log, "Completed parsing the branch node.");
		Context.CurrentNode = Context.BranchNode;
		Context.BranchNode = nullptr;
	}

	return Dispatcher.Dispatch(Line, Context);
}

FParserState* FExtractFlagsState::ProcessLine(const FString& Line, FDialogueParserContext& Context)
{
	FString Tag;
	if (!ExtractTag(Line, Tag)) return &FParserState::Error;

	Tag = Tag.ToLower();
	if (Tag.StartsWith("set") || Tag.StartsWith("condition"))
	{
		FString FlagName;

		// Try to parse the flag name
		if (!ParseFlagName(Line, FlagName)) return &FParserState::Error;

		if (!FindFlag(FlagName))
		{
			DLOG(Warning, "Couldn't find UDialogueFlag asset.");
			Context.MissingFlags.Add(FlagName);
		}
	}
	return &FParserState::ExtractFlagsState;
}

UDialogueFlag* FExtractFlagsState::FindFlag(const FString& FlagName)
{
	const FString AssetPath = FString::Printf(
		TEXT("/Game/Dialogue/%s.%s"),
		*FlagName,
		*FlagName
	);

	// try to load
	UDialogueFlag* FlagAsset = Cast<UDialogueFlag>(
		StaticLoadObject(UDialogueFlag::StaticClass(), /*Outer=*/nullptr, *AssetPath));

	return FlagAsset;
}

bool FExtractFlagsState::ParseFlagName(const FString& Line, FString& FlagName)
{
	if (!ParseNameFromLine(Line, FlagName, TEXT("keyword and flag name")))
		return false;

	DLOG(Warning, "Flag name is: %s", *FlagName);

	// Additional operator split
	bool bParsed = false;
	for (const FString& Del : TArray<FString>{ ">=", "<=", "=", "<", ">", "-", "+" })
	{
		if (FlagName.Split(Del, &FlagName, nullptr, ESearchCase::IgnoreCase))
		{
			bParsed = true;
			break;
		}
	}
	if (!bParsed) return false;

	FlagName = FlagName.TrimStartAndEnd();

	if (FlagName.IsEmpty())
	{
		DLOG(Error, "Flag name is empty in: %s", *Line);
		return false;
	}
	return true;
}

bool FExtractFlagsState::ParseFlagExpression(const FString& Line, FParsedFlag& OutFlag)
{
	FString Trimmed = TrimSquareBrackets(Line);

	FString Remainder;
	if (!Trimmed.Split(" ", nullptr, &Remainder, ESearchCase::IgnoreCase))
	{
		DLOG(Error, "Missing a space between keyword and flag expression in %s", *Line);
		return false;
	}

	FString Value;
	// Look for known operators
	for (const FString& Del : TArray<FString>{ "==", ">=", "<=", "<", ">", "=", "-", "+" })
	{
		if (Remainder.Split(Del, &OutFlag.Name, &Value, ESearchCase::IgnoreCase))
		{
			OutFlag.Comp = FlagCompFromString(Del);
			OutFlag.Operator = FlagOpFromString(Del);
			break;
		}
	}

	OutFlag.Name = OutFlag.Name.TrimStartAndEnd();
	Value = Value.TrimStartAndEnd();

	// see if it's a numeric or boolean flag
	if (Value.IsNumeric())
		OutFlag.nValue = FCString::Atoi(*Value);
	else
	{
		if (Value.Equals("true"))
		{
			OutFlag.bValue = true;
		}
		else if (Value.Equals("false"))
		{
			OutFlag.bValue = false;
		}
		else
		{
			DLOG(Error, "Invalid boolean: %s", *Value);
			return false;
		}

		// Check that the user didn't use + or - with booleans
		if (OutFlag.Operator != EFlagOperator::None)
		{
			if (OutFlag.Operator == EFlagOperator::Add || OutFlag.Operator == EFlagOperator::Subtract)
			{
				DLOG(Error, "+ or - operators cannot be used for boolean values!");
				return false;
			}
		}
	}

	if (OutFlag.Name.IsEmpty()
		|| (OutFlag.Comp == EFlagCompSymbol::None && OutFlag.Operator == EFlagOperator::None))
	{
		DLOG(Error, "Invalid flag expression in line: %s", *Line);
		return false;
	}

	DLOG(Warning, "Parsed Flag - Name: %s, Operator: %s, ComparisonSymbol: %s, Value (n/b): %d or %s", *OutFlag.Name,
		*FlagOpToString(OutFlag.Operator),
		*FlagCompToString(OutFlag.Comp),
		OutFlag.nValue, *LexToString(OutFlag.bValue));
	return true;
}
