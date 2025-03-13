// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BaseNPC.h"
#include "Game/CustomGameInstance.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABaseNPC::ABaseNPC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ABaseNPC::Interact_Implementation(AActor* Interactor)
{
	UCustomGameInstance* gameInstance = Cast<UCustomGameInstance>(UGameplayStatics::GetGameInstance(this));
	gameInstance->ShowDialogueScreen(CharacterDialogue);
}

// Called when the game starts or when spawned
void ABaseNPC::BeginPlay()
{
	Super::BeginPlay();
	
}

