// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <Game/CustomGameMode.h>
#include "CoreMinimal.h"
#include "Quests/QuestCondition.h"
#include "KillEnemyCondition.generated.h"


/**
 * 
 */
UCLASS()
class PROJECT300_API UKillEnemyCondition : public UQuestCondition
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int RequiredKills;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TArray<FString> RequiredEnemyIDs;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString RequiredLocationID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool ShouldCheckLocation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int CurrentKillCount;

	virtual bool IsConditionMet() override;
	virtual void Initialize(UObject* WorldContext) override;

protected:
	void OnEnemyKilled(FString EnemyID, FString LocationID);

private:
	ACustomGameMode* GameMode;
};
