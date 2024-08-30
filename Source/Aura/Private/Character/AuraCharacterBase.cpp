// Copyright Monkeyman Studios

#include "Character/AuraCharacterBase.h"

#include "AbilitySystemComponent.h"
#include "Components/SkeletalMeshComponent.h"


AAuraCharacterBase::AAuraCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

		Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
		Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
		Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* AAuraCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAuraCharacterBase::InitAbilityActorInfo()
{
}

// These attributes are replicated and only need to be called on the server, but can optionally be called on clients
void AAuraCharacterBase::InitializePrimaryAttributes() const
{
	check(IsValid(AbilitySystemComponent))
	checkf(DefaultPrimaryAttributes, TEXT("DefaultPrimaryAttributes is not set in Blueprint"));
	
	const FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	const FGameplayEffectSpecHandle EffectSpecHandle = AbilitySystemComponent->MakeOutgoingSpec(DefaultPrimaryAttributes, 1.f, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*EffectSpecHandle.Data.Get(), GetAbilitySystemComponent());
}

