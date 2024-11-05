// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/BaseHUD.h"
#include "Character/CustomCharacter.h"





void ABaseHUD::DrawHUD()
{
	Super::DrawHUD();
	
	ACustomCharacter* Player = Cast<ACustomCharacter>(GetOwningPlayerController()->GetPawn());
	if (IsValid(LockOnTexture) && IsValid(Player))
	{
		if (Player->isLockedOn)
		{
			float scale = 0.5f;

			FVector screenPosition = Project(Player->lockedOnActor->GetActorLocation(), true);
			screenPosition.X -= (LockOnTexture->GetSizeX() * scale) / 2;
			screenPosition.Y -= (LockOnTexture->GetSizeY() * scale) / 2;

			DrawTextureSimple(LockOnTexture, screenPosition.X, screenPosition.Y, scale);
		}
	}
}
