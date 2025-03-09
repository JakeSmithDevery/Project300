// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CustomCharacter.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ACustomCharacter::ACustomCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	isLockedOn = false;
	targetHeightOffset = 20.0f;
	lockedOnActor = nullptr;

}

// Called when the game starts or when spawned
void ACustomCharacter::BeginPlay()
{
	Super::BeginPlay();

}

void ACustomCharacter::ToggleLockOn()
{
	if (isLockedOn)
	{
		isLockedOn = false;
		lockedOnActor = nullptr;

	}
	else
	{
		if (lockOnCandidates.Num() > 0)
		{
			lockedOnActor = lockOnCandidates[0];

			if (lockedOnActor)
			{
				isLockedOn = true;
			}
		}
	}
}

void ACustomCharacter::ChangeLockOnTarget()
{
	if (lockOnCandidates.Num() == 0) return; // Early return if there are no candidates

	// Find the current index of the locked on actor
	int32 currentIndex = lockOnCandidates.IndexOfByKey(lockedOnActor);
	if (currentIndex == INDEX_NONE) currentIndex = -1; // If not found, set to -1

	// Calculate the next index
	int32 nextIndex = (currentIndex + 1) % lockOnCandidates.Num();

	// Set the next locked on actor
	lockedOnActor = lockOnCandidates[nextIndex];
}


// Called every frame
void ACustomCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (isLockedOn && lockedOnActor)
	{
		FVector playerLocation = GetActorLocation();
		FVector targetLocation = lockedOnActor->GetActorLocation();
		FVector toTarget = (targetLocation - playerLocation).GetSafeNormal();
		FVector velocity = GetVelocity();
		FVector movementDirection = velocity.GetSafeNormal();

		bool bIsMovingAway = FVector::DotProduct(movementDirection, toTarget) < 0;

		if (!bIsMovingAway)
		{
			// disable camera control while locked on
			if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
			{
				PlayerController->SetIgnoreLookInput(true);
			}

			FRotator targetRotation = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), lockedOnActor->GetActorLocation());

			targetRotation.Pitch -= targetHeightOffset;
			FRotator currentRotation = GetController()->GetControlRotation();
			FRotator smoothRotation = FMath::RInterpTo(currentRotation, targetRotation, DeltaTime, 5.0f);
			GetController()->SetControlRotation(smoothRotation);

			FRotator currentActorRotation = GetActorRotation();
			FRotator smoothActorRotation = FMath::RInterpTo(currentActorRotation, FRotator(0.0f, targetRotation.Yaw, 0.0f), DeltaTime, 8.0f);
			SetActorRotation(smoothActorRotation);
		}
		/**
		else
		{
			// allow normal camera control when moving away
			if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
			{
				PlayerController->SetIgnoreLookInput(false);
			}
		}
		*/
	}
	else
	{
		// enable camera control when not locked on
		if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
		{
			PlayerController->SetIgnoreLookInput(false); // Enable camera movement input
		}
	}

}

// Called to bind functionality to input
void ACustomCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

