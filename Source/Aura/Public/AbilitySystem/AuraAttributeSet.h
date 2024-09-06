// Copyright Monkeyman Studios

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AuraAttributeSet.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()
	
	FEffectProperties(){}

	FGameplayEffectContextHandle EffectContextHandle;
	
	UPROPERTY()
	UAbilitySystemComponent* SourceASC = nullptr;
	
	UPROPERTY()
	AActor* SourceAvatarActor = nullptr;
	
	UPROPERTY()
	AController* SourceController = nullptr;
	
	UPROPERTY()
	ACharacter* SourceCharacter = nullptr;

	UPROPERTY()
	UAbilitySystemComponent* TargetASC = nullptr;
	
	UPROPERTY()
	AActor* TargetAvatarActor = nullptr;
	
	UPROPERTY()
	AController* TargetController = nullptr;
	
	UPROPERTY()
	ACharacter* TargetCharacter = nullptr;
};


// typedef is specific to the FGameplayAttribute() signature, so we can't use it for other types
// typedef TBaseStaticDelegateInstance<FGameplayAttribute(), FDefaultDelegateUserPolicy>::FFuncPtr FAttributeFunctionPtr;

// We're defining a template for static function pointers (instead of a typedef), which is a generic signature
template<class T>
using TStaticFunctionPtr = typename TBaseStaticDelegateInstance<T, FDefaultDelegateUserPolicy>::FFuncPtr;


/**
 * 
 */
UCLASS()
class AURA_API UAuraAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UAuraAttributeSet();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	TMap<FGameplayTag, TStaticFunctionPtr<FGameplayAttribute()>> TagsToAttributes;

	
	/*
	 * Primary Attributes
	 */
	
	// Strength
	UPROPERTY(ReplicatedUsing = OnRep_Strength, BlueprintReadOnly, Category = "Primary Attributes")
	FGameplayAttributeData Strength;

	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Strength);

	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;

	// Intelligence
	UPROPERTY(ReplicatedUsing = OnRep_Intelligence, BlueprintReadOnly, Category = "Primary Attributes")
	FGameplayAttributeData Intelligence;

	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Intelligence);

	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const;
	
	// Resilience
	UPROPERTY(ReplicatedUsing = OnRep_Resilience, BlueprintReadOnly, Category = "Primary Attributes")
	FGameplayAttributeData Resilience;

	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Resilience);

	UFUNCTION()
	void OnRep_Resilience(const FGameplayAttributeData& OldResilience) const;
	
	// Vigor
	UPROPERTY(ReplicatedUsing = OnRep_Vigor, BlueprintReadOnly, Category = "Primary Attributes")
	FGameplayAttributeData Vigor;

	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Vigor);

	UFUNCTION()
	void OnRep_Vigor(const FGameplayAttributeData& OldVigor) const;
	

	/*
	 * Secondary Attributes
	 */
	
	// Armor
	UPROPERTY(ReplicatedUsing = OnRep_Armor, BlueprintReadOnly, Category = "Vital Attributes")
	FGameplayAttributeData Armor;
	
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Armor);

	UFUNCTION()
	void OnRep_Armor(const FGameplayAttributeData& OldArmor) const;
	
	// Armor Penetration
	UPROPERTY(ReplicatedUsing = OnRep_ArmorPenetration, BlueprintReadOnly, Category = "Vital Attributes")
	FGameplayAttributeData ArmorPenetration;
	
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, ArmorPenetration);

	UFUNCTION()
	void OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration) const;
	
	// Block Chance
	UPROPERTY(ReplicatedUsing = OnRep_BlockChance, BlueprintReadOnly, Category = "Vital Attributes")
	FGameplayAttributeData BlockChance;
	
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, BlockChance);

	UFUNCTION()
	void OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance) const;
	
	// Critical Hit Chance
	UPROPERTY(ReplicatedUsing = OnRep_CriticalHitChance, BlueprintReadOnly, Category = "Vital Attributes")
	FGameplayAttributeData CriticalHitChance;
	
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CriticalHitChance);

	UFUNCTION()
	void OnRep_CriticalHitChance(const FGameplayAttributeData& OldCriticalHitChance) const;
	
	// Critical Hit Damage
	UPROPERTY(ReplicatedUsing = OnRep_CriticalHitDamage, BlueprintReadOnly, Category = "Vital Attributes")
	FGameplayAttributeData CriticalHitDamage;
	
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CriticalHitDamage);

	UFUNCTION()
	void OnRep_CriticalHitDamage(const FGameplayAttributeData& OldCriticalHitDamage) const;
	
	// Critical Hit Resistance
	UPROPERTY(ReplicatedUsing = OnRep_CriticalHitResistance, BlueprintReadOnly, Category = "Vital Attributes")
	FGameplayAttributeData CriticalHitResistance;
	
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CriticalHitResistance);

	UFUNCTION()
	void OnRep_CriticalHitResistance(const FGameplayAttributeData& OldCriticalHitResistance) const;
	
	// Health Regeneration
	UPROPERTY(ReplicatedUsing = OnRep_HealthRegeneration, BlueprintReadOnly, Category = "Vital Attributes")
	FGameplayAttributeData HealthRegeneration;
	
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, HealthRegeneration);

	UFUNCTION()
	void OnRep_HealthRegeneration(const FGameplayAttributeData& OldHealthRegeneration) const;
	
	// Mana Regeneration
	UPROPERTY(ReplicatedUsing = OnRep_ManaRegeneration, BlueprintReadOnly, Category = "Vital Attributes")
	FGameplayAttributeData ManaRegeneration;
	
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, ManaRegeneration);

	UFUNCTION()
	void OnRep_ManaRegeneration(const FGameplayAttributeData& OldManaRegeneration) const;

	// Max Health
	UPROPERTY(ReplicatedUsing = OnRep_MaxHealth, BlueprintReadOnly, Category = "Vital Attributes")
	FGameplayAttributeData MaxHealth;
	
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxHealth);
	
	// Max Mana
	UPROPERTY(ReplicatedUsing = OnRep_MaxMana, BlueprintReadOnly, Category = "Vital Attributes")
	FGameplayAttributeData MaxMana;
	
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;

	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxMana);

	
	/*
	 * Vital Attributes
	 */
	
	// Health
	UPROPERTY(ReplicatedUsing = OnRep_Health, BlueprintReadOnly, Category = "Vital Attributes")
	FGameplayAttributeData Health;
	
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;
	
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Health);
	
	// Mana
	UPROPERTY(ReplicatedUsing = OnRep_Mana, BlueprintReadOnly, Category = "Vital Attributes")
	FGameplayAttributeData Mana;
	
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Mana);
	
	
private:
	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props);
};


