// Copyright Monkeyman Studios


#include "UI/WidgetController/AttributeMenuWidgetController.h"

#include "AuraGameplayTags.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/Data/AttributeInfo.h"


void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
	
}

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);

	check(AttributeInfo);
	FAuraAttributeInfo Info = AttributeInfo->FindAttributeInfoByTag(FAuraGameplayTags::Get().Attributes_Primary_Strength);
	Info.AttributeValue = AuraAttributeSet->GetStrength();
	AttributeInfoDelegate.Broadcast(Info);
}

