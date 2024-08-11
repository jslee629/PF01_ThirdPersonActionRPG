#include "CProjectile.h"
#include "Global.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/ParticleSystem.h"
#include "GameFramework/ProjectileMovementComponent.h"

ACProjectile::ACProjectile()
{
	//Initialize variables
	LifeTime = 1.f;

	//Create Scene Component
	CHelpers::CreateSceneComponent(this, &SphereComp, "SphereComp");
	CHelpers::CreateSceneComponent(this, &ParticleComp, "ParticleComp", SphereComp);
	
	//Create Actor Component
	CHelpers::CreateActorComponent(this, &ProjectileMovementComp, "ProjectileMovementComp");

	ProjectileMovementComp->InitialSpeed = 1000.f;
	ProjectileMovementComp->bRotationFollowsVelocity = true;
	ProjectileMovementComp->bInitialVelocityInLocalSpace = true;
	ProjectileMovementComp->ProjectileGravityScale = 0.f;
}

void ACProjectile::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle TimerHandle;
	FTimerDynamicDelegate Delegate;
	Delegate.BindUFunction(this, "DestroyProjectile");
	GetWorldTimerManager().SetTimer(TimerHandle, Delegate, LifeTime, false);
}

void ACProjectile::DestroyProjectile_Implementation()
{
	Destroy();
}


