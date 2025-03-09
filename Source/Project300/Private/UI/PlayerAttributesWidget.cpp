// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PlayerAttributesWidget.h"

void UPlayerAttributesWidget::NativeConstruct()
{
	Super::NativeConstruct();

	CharacterAttributes = GetOwningPlayerPawn()->GetComponentByClass<UCharacterAttributesComponent>();

	if (CharacterAttributes)
	{
		CharacterAttributes->OnAttributeChanged.AddDynamic(this, &UPlayerAttributesWidget::OnAttributeChanged);

		OnAttributeChanged(Health);
		//OnAttributeChanged(Mana);
	}
}

void UPlayerAttributesWidget::OnAttributeChanged(EAttributeType attributeType)
{
	float percent = CharacterAttributes->GetAttributeAsPercentage(attributeType);

	switch (attributeType)
	{
	case EAttributeType::Health:
		prgHealth->SetPercent(percent);
		txtHealth->SetText(FText::FromString(FString::FromInt(CharacterAttributes->Health) + "/" + FString::FromInt(CharacterAttributes->MaxHealth)));
		break;

	//case EAttributeType::Mana:
		//prgMana->SetPercent(percent);
		//txtMana->SetText(FText::FromString(FString::FromInt(CharacterAttributes->Mana) + "/" + FString::FromInt(CharacterAttributes->MaxMana)));
		//break;
	}
}
