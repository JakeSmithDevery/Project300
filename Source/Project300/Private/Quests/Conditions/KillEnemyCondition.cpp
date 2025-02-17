// Fill out your copyright notice in the Description page of Project Settings.


#include "Quests/Conditions/KillEnemyCondition.h"
#include <Kismet/GameplayStatics.h>

bool UKillEnemyCondition::IsConditionMet()
{
	return CurrentKillCount >= RequiredKills;
}

void UKillEnemyCondition::Initialize(UObject* WorldContext)
{
	GameMode = Cast<ACustomGameMode>(UGameplayStatics::GetGameMode(WorldContext));
	GameMode->OnEnemyKilled.AddUniqueDynamic(this, &UKillEnemyCondition::OnEnemyKilled);
}


void UKillEnemyCondition::OnEnemyKilled(FString EnemyID, FString LocationID)
{
	bool isCorrectLocation = true;
	bool isCorrectEnemy = false;

	if (ShouldCheckLocation)
	{
		isCorrectLocation = RequiredLocationID == LocationID;
	}

	for (int i = 0; i < RequiredEnemyIDs.Num(); i++)
	{
		if (RequiredEnemyIDs[i] == EnemyID)
		{
			isCorrectEnemy = true;
			break;
		}
	}

	if (isCorrectEnemy && isCorrectLocation)
	{
		CurrentKillCount++;
	}
}
