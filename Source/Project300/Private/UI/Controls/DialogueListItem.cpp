// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Controls/DialogueListItem.h"
#include "Dialogue/DialogueDTO.h"


void UDialogueListItem::NativeOnListItemObjectSet(UObject* ListItemObject)
{
    if (ListItemObject->IsA(UDialogueDTO::StaticClass()))
    {
        UDialogueDTO* dto = (UDialogueDTO*)ListItemObject;
        txtResponseText->SetText(dto->Response.ResponseText);
    }
}