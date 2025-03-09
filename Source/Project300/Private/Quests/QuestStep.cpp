// Fill out your copyright notice in the Description page of Project Settings.


#include "Quests/QuestStep.h"

bool UQuestStep::AreAllConditionsMet()
{
    for (UQuestCondition* Condition : ConditionInstances)
    {
        if (Condition && !Condition->IsConditionMet())
        {
            return false;
        }
    }
    return true;
}

void UQuestStep::Initialize(UObject* WorldContext)
{
    ConditionInstances.Empty();

    for (int32 i = 0; i < Conditions.Num(); i++)
    {
        if (Conditions[i])
        {
            UQuestCondition* conditionInstance = DuplicateObject<UQuestCondition>(Conditions[i], WorldContext);

            if (conditionInstance)
            {
                conditionInstance->Initialize(WorldContext);
                ConditionInstances.Add(conditionInstance);
            }
        }
    }
}
