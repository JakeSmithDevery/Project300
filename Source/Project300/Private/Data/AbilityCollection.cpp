// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/AbilityCollection.h"

UAbility* UAbilityCollection::PickRandomAbility(EAbilityType abilityType)
{

    switch (abilityType)
    {
    case Light:
        return GetRandomItemInArray(LightAttackAbilites);
        break;

    case Heavy:
        return GetRandomItemInArray(HeavyAttackAbilites);
        break;

    case Special:
        return GetRandomItemInArray(SpecialAttackAbilites);
        break;

    case Dodge:
        return GetRandomItemInArray(DodgeMove);
        break;
    }

    return nullptr;
}

UAbility* UAbilityCollection::GetRandomItemInArray(TArray<UAbility*> array)
{
    if (array.Num() > 0)
    {
        int index = FMath::RandRange(0, array.Num() - 1);
        if (array.IsValidIndex(index))
            return array[index];
    }

    return nullptr;
}
