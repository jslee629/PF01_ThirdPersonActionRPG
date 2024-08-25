#include "CProjectile.h"
#include "Global.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/ParticleSystem.h"
#include "GameFramework/ProjectileMovementComponent.h"

#include "Interfaces/CCharacterInterface.h"
#include "Components/CActionComponent.h"
#include "Components/CAttributeComponent.h"

ACProjectile::ACProjectile()
{
	//Initialize variables
	LifeTime = 1.f;

	//Create Scene Component
	CHelpers::CreateSceneComponent(this, &SphereComp, "SphereComp");
	CHelpers::CreateSceneComponent(this, &ParticleComp, "ParticleComp", SphereComp);
	
	//Create Actor Component
	CHelpers::CreateActorComponent(this, &ProjectileMovementComp, "ProjectileMovementComp");

	SphereComp->ComponentTags.Add(TEXT("Projectile"));

	ProjectileMovementComp->InitialSpeed = 1000.f;
	ProjectileMovementComp->bRotationFollowsVelocity = true;
	ProjectileMovementComp->bInitialVelocityInLocalSpace = true;
	ProjectileMovementComp->ProjectileGravityScale = 0.f;
}

void ACProjectile::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

}

void ACProjectile::BeginPlay()
{
	Super::BeginPlay();

	ICCharacterInterface* ICharacter = Cast<ICCharacterInterface>(GetInstigator());
	ICharacter->SendDataToProjectile(this);

	FTimerHandle TimerHandle;
	FTimerDynamicDelegate Delegate;
	Delegate.BindUFunction(this, "DestroyProjectile");
	GetWorldTimerManager().SetTimer(TimerHandle, Delegate, LifeTime, false);
}

void ACProjectile::SetOwnerDamage(float InAttackPoint)
{
	OwnerDamage = InAttackPoint;
}

void ACProjectile::SetDamageRate(float InDamageRate)
{
	DamageRate = InDamageRate;
}

void ACProjectile::DestroyProjectile_Implementation()
{
	Destroy();
}


