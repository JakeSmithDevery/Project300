// Fill out your copyright notice in the Description page of Project Settings.


#include "Quests/QuestCondition.h"

bool UQuestCondition::IsConditionMet()
{
    return false;
}

void UQuestCondition::Initialize(UObject* WorldContext)
{
    WorldContextObject = WorldContext;
}

void UQuestCondition::TickCondition(float DeltaTime)
{
}
