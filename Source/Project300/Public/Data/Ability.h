#pragma once
#include "Animation/AnimSequence.h"
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Ability.generated.h"

UENUM(BlueprintType)
enum EAbilityType
{
	Light,
	Heavy,
	Special,
	Dodge
};

UCLASS()
class PROJECT300_API UAbility : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Damage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UAnimSequence* Animation;

};

