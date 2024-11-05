// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BaseHUD.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT300_API ABaseHUD : public AHUD
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UTexture2D* LockOnTexture;

	UFUNCTION(BlueprintCallable)
	void SetLockOnTarget(AActor* target);

	UFUNCTION(BlueprintCallable)
	void ClearLockOnTarget();

	virtual void DrawHUD() override;

protected:
	
	
};
