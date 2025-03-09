// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseDialogueAction.generated.h"

UCLASS(Abstract)
class PROJECT300_API UBaseDialogueAction : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual void TriggerAction(AActor* triggeringCharacter, AActor* playerCharacter);
};