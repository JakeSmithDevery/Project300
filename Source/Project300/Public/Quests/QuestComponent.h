// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Quest.h"
#include "QuestComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT300_API UQuestComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UQuestComponent();

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Quests")
	TMap<FPrimaryAssetId, UQuest*> ActiveQuests;

	UFUNCTION(BlueprintCallable, Category = "Quests")
	void StartQuest(UQuest* Quest);


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	void CheckQuestProgress(UQuest* Quest);
};
