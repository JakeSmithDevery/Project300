// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterAttributesComponent.generated.h"

UENUM()
enum EAttributeType
{
	Health,
	//Mana
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAttributeChanged, EAttributeType, AttributeType);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT300_API UCharacterAttributesComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UCharacterAttributesComponent();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void UpdateAttribute(EAttributeType attributeType, float amount);

	UPROPERTY(BlueprintAssignable)
	FAttributeChanged OnAttributeChanged;

	UFUNCTION(BlueprintCallable)
	float GetAttributeAsPercentage(EAttributeType attributeType);

	UFUNCTION(BlueprintCallable)
	float GetAttributeValue(EAttributeType attributeType);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float MaxHealth;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	//float Mana;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	//float MaxMana;
};
