// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Quests/QuestCondition.h"
#include "LocationCondition.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT300_API ULocationCondition : public UQuestCondition
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Quest")
	FVector TargetLocation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Quest")
	float AcceptanceRadius = 100.00f;

	virtual bool IsConditionMet() override;
	virtual void Initialize(UObject* WorldContext) override;
	virtual void TickCondition(float DeltaTime) override;

private:
	APlayerController* PlayerController;
};
