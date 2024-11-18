// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include <Data/AbilityCollection.h>
#include "BaseAnimInstance.generated.h"


/**
 * 
 */
UCLASS()
class PROJECT300_API UBaseAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UAbilityCollection* Abilities;
	
};
