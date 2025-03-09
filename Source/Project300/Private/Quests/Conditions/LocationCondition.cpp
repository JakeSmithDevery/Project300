// Fill out your copyright notice in the Description page of Project Settings.


#include "Quests/Conditions/LocationCondition.h"
#include <Kismet/GameplayStatics.h>

bool ULocationCondition::IsConditionMet()
{
	if (!PlayerController) return false;

	if (!ConditionCompleted)
	{
		FVector PlayerLocation = PlayerController->GetPawn()->GetActorLocation();

		ConditionCompleted = FVector::Dist(PlayerLocation, TargetLocation) <= AcceptanceRadius;

		if (ConditionCompleted)
			UE_LOG(LogTemp, Warning, TEXT("Condition Complete."));
	}

	return ConditionCompleted;
}

void ULocationCondition::Initialize(UObject* WorldContext)
{
	Super::Initialize(WorldContext);

	PlayerController = UGameplayStatics::GetPlayerController(WorldContext, 0);
}

void ULocationCondition::TickCondition(float DeltaTime)
{
	if (GEngine && GEngine->IsEditor())
	{
		DrawDebugSphere(
			GetWorld(),
			TargetLocation,
			AcceptanceRadius,
			16,
			FColor::Red,
			false,
			0
		);
	}
}
