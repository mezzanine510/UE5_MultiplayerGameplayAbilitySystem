// Copyright Monkeyman Studios


#include "AuraGameplayTags.h"
#include "GameplayTagsManager.h"


FAuraGameplayTags FAuraGameplayTags::GameplayTags;

void FAuraGameplayTags::InitializeNativeGameplayTags()
{
	UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Armor"), FString("Reduces Damage taken, improves Block chance"));
}
