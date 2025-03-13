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

	if (RequiredInputAction.GetStringLength() > 0)
		CharacterController->InputComponent->BindAction(RequiredInputAction, IE_Pressed, this, &UButtonCondition::InputActionTriggered);
}

void UButtonCondition::TickCondition(float DeltaTime)
{
	Super::TickCondition(DeltaTime);

	if (CharacterController->WasInputKeyJustPressed(RequiredKey))
	{
		CurrentPresses++;
	}
}

void UButtonCondition::InputActionTriggered()
{
	CurrentPresses++;
}
