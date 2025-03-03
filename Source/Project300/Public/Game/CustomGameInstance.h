// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Dialogue/Dialogue.h"
#include "Engine/GameInstance.h"
#include <UI/BaseDialogueWidget.h>
#include "CustomGameInstance.generated.h"

UCLASS()
class PROJECT300_API UCustomGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UBaseDialogueWidget> DialogueWidgetClass;

	UFUNCTION(BlueprintCallable)
	void ShowDialogueScreen(UDialogue* dialogueToShow);

	UFUNCTION(BlueprintCallable)
	void HideDialogueScreen();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBaseDialogueWidget* dialogueWidgetInstance;
};
