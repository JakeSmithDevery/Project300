// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/BaseHUD.h"

void ABaseHUD::SetLockOnTarget(AActor* target)
{
	if (IsValid(target))
		LockOnTarget = target;
}

void ABaseHUD::ClearLockOnTarget()
{
	LockOnTarget = nullptr;
}

void ABaseHUD::DrawHUD()
{
	Super::DrawHUD();

	if (IsValid(LockOnTexture) && IsValid(LockOnTarget))
	{
		float scale = 0.5f;

		FVector screenPosition = Project(LockOnTarget->GetActorLocation(), true);
		screenPosition.X -= (LockOnTexture->GetSizeX() * scale) / 2;
		screenPosition.Y -= (LockOnTexture->GetSizeY() * scale) / 2;

		DrawTextureSimple(LockOnTexture, screenPosition.X, screenPosition.Y, scale);
	}
}
