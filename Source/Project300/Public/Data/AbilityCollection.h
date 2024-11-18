// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Data/Ability.h"
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AbilityCollection.generated.h"


/**
 * 
 */
UCLASS()
class PROJECT300_API UAbilityCollection : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<UAbility*> LightAttackAbilites;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<UAbility*> HeavyAttackAbilites;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<UAbility*> SpecialAttackAbilites;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<UAbility*> DodgeMove;

	UFUNCTION(BlueprintCallable)
	UAbility* PickRandomAbility(EAbilityType abilityType);

private:
	UAbility* GetRandomItemInArray(TArray<UAbility*> array);
};
