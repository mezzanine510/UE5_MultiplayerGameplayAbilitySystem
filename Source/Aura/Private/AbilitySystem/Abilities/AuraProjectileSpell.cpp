// Copyright Monkeyman Studios


#include "AbilitySystem/Abilities/AuraProjectileSpell.h"

#include "Actor/AuraProjectile.h"
#include "Interaction/CombatInterface.h"


void UAuraProjectileSpell::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                           const FGameplayAbilityActorInfo* ActorInfo,
                                           const FGameplayAbilityActivationInfo ActivationInfo,
                                           const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	UE_LOG(LogTemp, Warning, TEXT("UAuraProjectileSpell::ActivateAbility"));
	const bool bIsServer = HasAuthority(&ActivationInfo);
	if (!bIsServer) return;
	UE_LOG(LogTemp, Warning, TEXT("IsServer"));

	ICombatInterface* CombatInterface = Cast<ICombatInterface>(GetAvatarActorFromActorInfo());
	if (CombatInterface)
	{
		UE_LOG(LogTemp, Warning, TEXT("CombatInterface is valid"));
		const FVector SocketLocation = CombatInterface->GetCombatSocketLocation();
		FTransform SpawnTransform;
		SpawnTransform.SetLocation(SocketLocation);
		// TODO: Set the rotation of the SpawnTransform to face the target
		
		AAuraProjectile* Projectile = GetWorld()->SpawnActorDeferred<AAuraProjectile>(
			ProjectileClass,
			SpawnTransform,
			GetAvatarActorFromActorInfo(),
			Cast<APawn>(GetAvatarActorFromActorInfo()),
			ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

		// TODO: Give the projectile a GameplayEffectSpec for causing Damage

		Projectile->FinishSpawning(SpawnTransform);
	}
}
