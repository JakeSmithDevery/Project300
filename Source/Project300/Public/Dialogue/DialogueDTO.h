// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Dialogue.h"
#include "UObject/NoExportTypes.h"
#include "DialogueDTO.generated.h"

UCLASS()
class PROJECT300_API UDialogueDTO : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	FDialogueResponse Response;
};
