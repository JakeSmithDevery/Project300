// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CustomGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FEnemyKilledEvent, FString, EnemyID, FString, LocationID);

UCLASS()
class PROJECT300_API ACustomGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintAssignable)
	FEnemyKilledEvent OnEnemyKilled;

	UFUNCTION(BlueprintCallable)
	void RecordEnemyDeath(FString EnemyID);

	UFUNCTION(BlueprintCallable)
	void SetPlayerLocation(FString LocationID);

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FString CurrentPlayerLocation;
};
