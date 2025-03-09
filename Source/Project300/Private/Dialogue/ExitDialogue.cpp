// Fill out your copyright notice in the Description page of Project Settings.


#include "Dialogue/ExitDialogue.h"

#include "Game/CustomGameInstance.h"
#include "Kismet/GameplayStatics.h"

void UExitDialogue::TriggerAction(AActor* triggeringCharacter, AActor* playerCharacter)
{
	APlayerController* controller = UGameplayStatics::GetPlayerController(playerCharacter, 0);
	controller->SetInputMode(FInputModeGameOnly());
	controller->bShowMouseCursor = false;

	UCustomGameInstance* gameInstance = Cast<UCustomGameInstance>(UGameplayStatics::GetGameInstance(playerCharacter));

	if (gameInstance)
		gameInstance->HideDialogueScreen();
}