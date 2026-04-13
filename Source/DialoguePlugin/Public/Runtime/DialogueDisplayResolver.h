// Copyright © 2026 created and maintained by wortback, Ellufin Soft. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Runtime/DialogueRuntimeTypes.h"
#include "DialogueDisplayResolver.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UDialogueDisplayResolver : public UInterface {
	GENERATED_BODY()
};

/**
 * 
 */
class DIALOGUEPLUGIN_API IDialogueDisplayResolver {
	GENERATED_BODY()

public:
	/** Display a dialogue sentence (NPC speaking) */
	virtual void DisplaySentence(const FDisplayObject& Obj) = 0;
    
	/** Display dialogue choices for player selection */
	virtual void DisplayChoice(const FDisplayObject& Obj) = 0;
    
	/** Get whether this resolver is active/enabled */
	virtual bool IsActiveResolver() const = 0;
	
	/** Run at the beginning of dialogue */
	virtual void StartDialogue() {};
	
	/** Run at the end of dialogue */
	virtual void EndDialogue() {};
};
