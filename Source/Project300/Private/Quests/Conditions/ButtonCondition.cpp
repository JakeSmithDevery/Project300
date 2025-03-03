// Fill out your copyright notice in the Description page of Project Settings.


#include "Quests/Conditions/ButtonCondition.h"
#include <Kismet/GameplayStatics.h>

bool UButtonCondition::IsConditionMet()
{
	return CurrentPresses >= RequiredPresses;
}

void UButtonCondition::Initialize(UObject* WorldContext)
{
	Super::Initialize(WorldContext);
	CharacterController = Cast<APlayerController>(UGameplayStatics::GetPlayerController(WorldContext, 0));
}

void UButtonCondition::TickCondition(float DeltaTime)
{
	if (CharacterController->WasInputKeyJustPressed(RequiredKey))
	{
		CurrentPresses++;
	}
}
