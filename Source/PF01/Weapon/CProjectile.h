#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CProjectile.generated.h"

class USphereComponent;
class UParticleSystemComponent;
class UParticleSystem;
class UProjectileMovementComponent;

UCLASS()
class PF01_API ACProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	ACProjectile();

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void DestroyProjectile();

public:	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Components")
	USphereComponent* SphereComp;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Components")
	UParticleSystemComponent* ParticleComp;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Components")
	UProjectileMovementComponent* ProjectileMovementComp;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ALifeTime")
	float LifeTime;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "AfterDestroy")
	UParticleSystem* DestroyParticle;
};
