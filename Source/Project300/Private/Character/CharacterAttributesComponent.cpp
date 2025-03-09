// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CharacterAttributesComponent.h"

UCharacterAttributesComponent::UCharacterAttributesComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	MaxHealth = 100;
	Health = MaxHealth;

	//MaxMana = 100;
	//Mana = MaxMana;
}

void UCharacterAttributesComponent::UpdateAttribute(EAttributeType attributeType, float amount)
{
	switch (attributeType)
	{
	case EAttributeType::Health:
		Health += amount;
		if (Health > MaxHealth)
			Health = MaxHealth;
		else if (Health <= 0)
			Health = 0;
		break;
	
		/*
	case EAttributeType::Mana:
		Mana += amount;
		if (Mana > MaxMana)
			Mana = MaxMana;
		else if (Mana <= 0)
			Mana = 0;
		break;
		*/
	}

	if (OnAttributeChanged.IsBound())
		OnAttributeChanged.Broadcast(attributeType);
}

float UCharacterAttributesComponent::GetAttributeAsPercentage(EAttributeType attributeType)
{
	switch (attributeType)
	{
	case EAttributeType::Health:
		return Health / MaxHealth;
		break;
		/*
	case EAttributeType::Mana:
		return Mana / MaxMana;
		break;
		*/
	}

	return 0;
}

float UCharacterAttributesComponent::GetAttributeValue(EAttributeType attributeType)
{
	switch (attributeType)
	{
	case EAttributeType::Health:
		return Health;
		break;

		/*
	case EAttributeType::Mana:
		return Mana;
		break;
		*/
	}

	return 0;
}

void UCharacterAttributesComponent::BeginPlay()
{
	Super::BeginPlay();

}

