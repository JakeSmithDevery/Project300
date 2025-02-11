// Fill out your copyright notice in the Description page of Project Settings.


#include "Quests/Quest.h"

void UQuest::Initialize(UObject* WorldContext)
{
    StepInstances.Empty();

    for (int32 i = 0; i < Steps.Num(); i++)
    {
        if (Steps[i])
        {
            UQuestStep* step = DuplicateObject<UQuestStep>(Steps[i], WorldContext);
            if (step)
            {
                step->Initialize(WorldContext);
                StepInstances.Add(step);
            }
        }
    }
}

bool UQuest::IsQuestCompleted()
{
    return CurrentStepIndex >= StepInstances.Num();
}

int32 UQuest::GetCurrentStepIndex()
{
    return CurrentStepIndex;
}

void UQuest::AdvanceToNextStep()
{
    if (CurrentStepIndex < StepInstances.Num() &&
        StepInstances[CurrentStepIndex]->AreAllConditionsMet())
    {
        CurrentStepIndex++;
    }
}

FPrimaryAssetId UQuest::GetPrimaryAssetId() const
{
    return FPrimaryAssetId(TEXT("Quest"), GetFName());
}
