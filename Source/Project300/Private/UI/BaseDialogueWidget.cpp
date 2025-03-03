// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/BaseDialogueWidget.h"
#include "Dialogue/DialogueDTO.h"


void UBaseDialogueWidget::SetDialogue(UDialogue* dialogue)
{
	if (dialogue)
	{
		CurrentDialogue = dialogue;
	}
}

void UBaseDialogueWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (CurrentDialogue)
	{
		GetOwningPlayer()->SetInputMode(FInputModeUIOnly());
		GetOwningPlayer()->bShowMouseCursor = true;

		txtSpeakerName->SetText(FText::FromString(CurrentDialogue->SpeakerName));
		lstResponse->OnItemClicked().AddUObject(this, &UBaseDialogueWidget::OnResponseSelected);
		ProgressDialogue();
	}

	btnNextLine->OnClicked.AddDynamic(this, &UBaseDialogueWidget::OnDialogueClicked);
}

void UBaseDialogueWidget::ProgressDialogue()
{
	if (CurrentDialogue)
	{
		lstResponse->ClearListItems();

		if (CurrentDialogue->DialogueLines.IsValidIndex(currentLineIndex) && CurrentDialogue->DialogueLines[currentLineIndex].DialogueText.IsValidIndex(currentLineTextIndex))
		{
			txtCurrentLine->SetText(CurrentDialogue->DialogueLines[currentLineIndex].DialogueText[currentLineTextIndex]);
			currentLineTextIndex++;
		}
		else
		{
			if (currentLineIndex != -1)
			{
				for (FDialogueResponse& response : CurrentDialogue->DialogueLines[currentLineIndex].Responses)
				{
					UDialogueDTO* dto = NewObject<UDialogueDTO>(this);
					dto->Response = response;

					lstResponse->AddItem(dto);
				}
			}
		}
	}
}

void UBaseDialogueWidget::OnDialogueClicked()
{
	ProgressDialogue();
}

void UBaseDialogueWidget::OnResponseSelected(UObject* selectedResponse)
{
	int32 index = lstResponse->GetIndexForItem(selectedResponse);
	if (index != -1)
	{
		if (CurrentDialogue->DialogueLines[currentLineIndex].Responses[index].TriggersAction)
		{
			FDialogueResponse& response = CurrentDialogue->DialogueLines[currentLineIndex].Responses[index];
			for (UClass* actionClass : response.ActionClasses)
			{
				UBaseDialogueAction* action = NewObject<UBaseDialogueAction>(this, actionClass);
				action->TriggerAction(nullptr, GetOwningPlayer());
			}
		}
		currentLineIndex = CurrentDialogue->DialogueLines[currentLineIndex].Responses[index].NextLineIndex;
		ProgressDialogue();
	}
}