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

	if (isLockedOn)
	{
		FRotator lookAtRotation = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), lockedOnActor->GetActorLocation());
		lookAtRotation.Pitch -= targetHeightOffset;
		GetController()->SetControlRotation(lookAtRotation);
	}

}

// Called to bind functionality to input
void ACustomCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

