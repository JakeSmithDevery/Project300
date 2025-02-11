// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Character/CharacterAttributesComponent.h"
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerAttributesWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT300_API UPlayerAttributesWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(meta = (BindWidget))
	UProgressBar* prgHealth;

	//UPROPERTY(meta = (BindWidget))
	//UProgressBar* prgMana;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* txtHealth;

	//UPROPERTY(meta = (BindWidget))
	//UTextBlock* txtMana;

	virtual void NativeConstruct() override;

	UPROPERTY()
	UCharacterAttributesComponent* CharacterAttributes;

	UFUNCTION()
	void OnAttributeChanged(EAttributeType attributeType);
};
