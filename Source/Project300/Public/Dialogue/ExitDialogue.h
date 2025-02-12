// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Dialogue/BaseDialogueAction.h"
#include "ExitDialogue.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT300_API UExitDialogue : public UBaseDialogueAction
{
	GENERATED_BODY()
	
public:
	virtual void TriggerAction(AActor* triggeringCharacter, AActor* playerCharacter) override;
};
