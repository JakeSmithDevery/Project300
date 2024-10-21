// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CustomCharacter.generated.h"

UCLASS()
class PROJECT300_API ACustomCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACustomCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//functions
	UFUNCTION(BlueprintCallable)
	void ToggleLockOn();


	//variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lock-On")
	bool isLockedOn;

	float targetHeightOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lock-On")
	TArray<AActor*> lockOnCandidates;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lock-On")
	AActor* lockedOnActor;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



};
