// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/CustomGameMode.h"

void ACustomGameMode::RecordEnemyDeath(FString EnemyID)
{
	if (OnEnemyKilled.IsBound())
		OnEnemyKilled.Broadcast(EnemyID, CurrentPlayerLocation);
}

void ACustomGameMode::SetPlayerLocation(FString LocationID)
{
	CurrentPlayerLocation = LocationID;
}
