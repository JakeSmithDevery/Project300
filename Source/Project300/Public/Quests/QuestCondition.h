// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "QuestCondition.generated.h"

/**
 * 
 */
UCLASS(Abstract, BlueprintType)
class PROJECT300_API UQuestCondition : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Quest")
	FText Description;

	UFUNCTION(BlueprintCallable)
	virtual bool IsConditionMet();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, SaveGame, Category = "Quest")
	bool ConditionCompleted;

	virtual void Initialize(UObject* WorldContext);
	virtual void TickCondition(float DeltaTime);

protected:
	UPROPERTY()
	UObject* WorldContextObject;
};
