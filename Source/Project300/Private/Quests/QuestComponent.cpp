// Fill out your copyright notice in the Description page of Project Settings.


#include "Quests/QuestComponent.h"

// Sets default values for this component's properties
UQuestComponent::UQuestComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UQuestComponent::StartQuest(UQuest* Quest)
{
	if (!Quest) return;

	UQuest* questInstance = DuplicateObject<UQuest>(Quest, GetOwner());
	questInstance->Initialize(GetOwner());

	ActiveQuests.Add(Quest->GetPrimaryAssetId(), questInstance);
}

// Called when the game starts
void UQuestComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UQuestComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	for (TPair<FPrimaryAssetId, UQuest*> QuestPair : ActiveQuests)
	{
		UQuest* quest = QuestPair.Value;

		if (quest->StepInstances.IsValidIndex(quest->GetCurrentStepIndex()))
		{
			UQuestStep* step = quest->StepInstances[quest->GetCurrentStepIndex()];

			GEngine->AddOnScreenDebugMessage(1, 1.0f, FColor::Red, step->Description.ToString());

			for (UQuestCondition* condition : step->ConditionInstances)
			{
				if (condition)
				{
					if (!condition->ConditionCompleted)
					{
						GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Green, condition->Description.ToString());

						condition->TickCondition(DeltaTime);
					}
				}
			}
		}
		CheckQuestProgress(quest);
	}
}

void UQuestComponent::CheckQuestProgress(UQuest* Quest)
{
	if (!Quest) return;

	if (Quest->StepInstances.IsValidIndex(Quest->GetCurrentStepIndex()))
	{
		UQuestStep* CurrentStep = Quest->StepInstances[Quest->GetCurrentStepIndex()];

		if (CurrentStep && CurrentStep->AreAllConditionsMet())
		{
			Quest->AdvanceToNextStep();

			if (Quest->GetCurrentStepIndex() >= Quest->Steps.Num())
			{
				UE_LOG(LogTemp, Log, TEXT("Quest '%s' completed!"), *Quest->QuestName.ToString());
			}
		}
	}
}

