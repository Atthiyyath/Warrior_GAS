// Atthiyya Agustian All Rights Reserved


#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"

#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCtoGive,
                                                              int32 ApplyLevel)
{
	check(InASCtoGive);

	GrantAbilities(ActivateOnGivenAbilities, InASCtoGive, ApplyLevel);
	GrantAbilities(ReactivateAbilities, InASCtoGive, ApplyLevel);
}

void UDataAsset_StartUpDataBase::GrantAbilities(TArray<TSubclassOf<UWarriorGameplayAbility>>& InAbilitiesToGive,
	UWarriorAbilitySystemComponent* InASCtoGive, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty())
	{
		return;
	}

	for (const TSubclassOf<UWarriorGameplayAbility>& Ability : InAbilitiesToGive)
	{
		if (!Ability) continue;

		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InASCtoGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;

		InASCtoGive->GiveAbility(AbilitySpec);
	}
}
