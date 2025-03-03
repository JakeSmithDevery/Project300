// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Quests/QuestCondition.h"
#include "ButtonCondition.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT300_API UButtonCondition : public UQuestCondition
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int RequiredPresses;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int CurrentPresses;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FKey RequiredKey;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FName RequiredInputAction;

	virtual bool IsConditionMet() override;

	virtual void Initialize(UObject* WorldContext) override;

	virtual void TickCondition(float DeltaTime) override;

	void InputActionTriggered();

private:
	UPROPERTY()
	APlayerController* CharacterController;
};
