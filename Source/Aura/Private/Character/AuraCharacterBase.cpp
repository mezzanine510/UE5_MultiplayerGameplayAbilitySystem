// Copyright Monkeyman Studios

#include "Character/AuraCharacterBase.h"
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

