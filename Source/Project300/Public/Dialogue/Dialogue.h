// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BaseDialogueAction.h"
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Dialogue.generated.h"


USTRUCT(BlueprintType)
struct FDialogueResponse
{
	GENERATED_BODY()

	FDialogueResponse()
	{
		ResponseText = FText::FromString("Default Text");
		NextLineIndex = -1;
		TriggersAction = false;
	};

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText ResponseText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 NextLineIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool TriggersAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<TSubclassOf<UBaseDialogueAction>> ActionClasses;
};

USTRUCT(BlueprintType)
struct FDialogueLine
{
	GENERATED_BODY()

	FDialogueLine()
	{

	};

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FText> DialogueText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FDialogueResponse> Responses;
};

UCLASS(BlueprintType)
class PROJECT300_API UDialogue : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FString SpeakerName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FDialogueLine> DialogueLines;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override;
};
