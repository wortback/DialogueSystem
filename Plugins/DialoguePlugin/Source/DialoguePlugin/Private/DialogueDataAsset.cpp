// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueDataAsset.h"
#include "RecursiveParser/CondSyntaxTree.h"

void UDialogueFork::LogNode(int32 Indent) const
{
	const FString Pad = FString::ChrN(Indent, ' ');
	// Now display each branch in order
	for (int32 i = 0; i < Branches.Num(); ++i)
	{
		const auto& B = Branches[i];
		const FString BranchPad = FString::ChrN(Indent + 2, ' ');

		// Recurse into that branch's content
		if (B.Branch)
		{
			if (B.TreeWrapper)
			{
				DLOG(Log, "%s %s", *Pad, *B.TreeWrapper->CondString);
			}
			else
			{
				DLOG(Log, "%s [else]", *Pad);
			}
			B.Branch->LogNodeFromFork(Indent + 4, i);
		}
		else
		{
			DLOG(Log, "%s  (empty)", *BranchPad);
		}
	}
}

void UDialogueChoice::LogNode(int32 Indent) const
{
	const FString Pad = FString::ChrN(Indent, ' ');
	for (const auto& Opt : Options)
	{
		// Log the choice text + optional goto on one line:
		if (!Opt.GotoID.IsNone())
		{
			DLOG(Log, "%s[Choice] \"%s\" (goto %s)", *Pad, *Opt.Text, *Opt.GotoID.ToString());
		}
		else
		{
			DLOG(Log, "%s[Choice] \"%s\"", *Pad, *Opt.Text);
		}

		for (const auto& Eff : Opt.AffectedFlags)
		{
			Eff.LogEffect(Indent + 2);
		}

		if (Opt.TreeWrapper)
		{
			DLOG(Log, "%s %s", *Pad, *Opt.TreeWrapper->CondString);
		}
	}
}
