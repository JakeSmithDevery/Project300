// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <Dialogue/Dialogue.h>
#include "BaseNPC.generated.h"

UCLASS()
class PROJECT300_API ABaseNPC : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseNPC();

	void Interact(AActor* Interactor);
	virtual void Interact_Implementation(AActor* Interactor);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UDialogue* CharacterDialogue;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
