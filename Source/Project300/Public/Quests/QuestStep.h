// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "QuestCondition.h"
#include "QuestStep.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class PROJECT300_API UQuestStep : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	TArray<UQuestCondition*> Conditions;

	UPROPERTY()
	TArray<UQuestCondition*> ConditionInstances;

	UFUNCTION(BlueprintCallable, Category = "Quest")
	bool AreAllConditionsMet();

	virtual void Initialize(UObject* WorldContext);
};
