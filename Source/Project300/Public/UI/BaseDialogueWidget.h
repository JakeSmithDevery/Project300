// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Dialogue/Dialogue.h>
#include <Components/TextBlock.h>
#include <Components/ListView.h>
#include <Components/Button.h>
#include "BaseDialogueWidget.generated.h"

UCLASS()
class PROJECT300_API UBaseDialogueWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void SetDialogue(UDialogue* dialogue);

	UFUNCTION()
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	virtual void ProgressDialogue();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UDialogue* CurrentDialogue;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* txtSpeakerName;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* txtCurrentLine;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* txtLinesCount;

	UPROPERTY(meta = (BindWidget))
	UListView* lstResponse;

	UPROPERTY(meta = (BindWidget))
	UButton* btnNextLine;

private:
	UPROPERTY()
	int32 currentLineIndex = 0;

	UPROPERTY()
	int32 currentLineTextIndex = 0;

	UFUNCTION()
	void OnDialogueClicked();

	UFUNCTION()
	void OnResponseSelected(UObject* selectedResponse);
};
