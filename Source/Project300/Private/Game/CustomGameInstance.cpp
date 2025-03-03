// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/CustomGameInstance.h"
#include "Blueprint/UserWidget.h"

void UCustomGameInstance::ShowDialogueScreen(UDialogue* dialogueToShow)
{
	dialogueWidgetInstance = Cast<UBaseDialogueWidget>(CreateWidget(GetFirstLocalPlayerController(), DialogueWidgetClass));

	if (dialogueWidgetInstance)
	{
		dialogueWidgetInstance->SetDialogue(dialogueToShow);
		dialogueWidgetInstance->AddToViewport();
	}
}

void UCustomGameInstance::HideDialogueScreen()
{
	if (dialogueWidgetInstance)
	{
		dialogueWidgetInstance->RemoveFromParent();
		dialogueWidgetInstance = nullptr;
	}
}