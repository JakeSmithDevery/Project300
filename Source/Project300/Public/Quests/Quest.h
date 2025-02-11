// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "QuestStep.h"
#include "Quest.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class PROJECT300_API UQuest : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	FText QuestName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Quest")
	TArray<UQuestStep*> Steps;

	UPROPERTY()
	TArray<UQuestStep*> StepInstances;

	virtual void Initialize(UObject* WorldContext);

	UFUNCTION(BlueprintCallable, Category = "Quest")
	bool IsQuestCompleted();

	UFUNCTION(BlueprintCallable, Category = "Quest")
	int32 GetCurrentStepIndex();

	UFUNCTION(BlueprintCallable, Category = "Quest")
	void AdvanceToNextStep();

	virtual FPrimaryAssetId GetPrimaryAssetId() const override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, SaveGame)
	int32 CurrentStepIndex = 0;
};
