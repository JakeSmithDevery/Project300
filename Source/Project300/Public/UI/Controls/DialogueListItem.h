// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include <Components/TextBlock.h>
#include "DialogueListItem.generated.h"

UCLASS()
class PROJECT300_API UDialogueListItem : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* txtResponseText;

	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
};
