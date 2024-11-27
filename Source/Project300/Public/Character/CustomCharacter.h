// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Data/AbilityCollection.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CustomCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterAttackDelegate, UAbility*, AttackType);

UCLASS()
class PROJECT300_API ACustomCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACustomCharacter();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UAbilityCollection* Abilities;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnCharacterAttackDelegate OnCharacterAttack;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//functions
	UFUNCTION(BlueprintCallable)
	void ToggleLockOn();

	UFUNCTION(BlueprintCallable)
	void ChangeLockOnTarget();




public:

	//variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lock-On")
	bool isLockedOn;

	float targetHeightOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lock-On")
	TArray<AActor*> lockOnCandidates;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lock-On")
	AActor* lockedOnActor;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



};

