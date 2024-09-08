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
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void DestroyProjectile();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void ProjectileHitted(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void ProjectileBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

public:
	FORCEINLINE float GetBaseDamage() { return BaseDamage; }
	FORCEINLINE float GetOwnerDamage() { return OwnerDamage; }
	FORCEINLINE float GetDamageRate() { return DamageRate; }

	void SetOwnerDamage(float InAttackPoint);
	void SetDamageRate(float InDamageRate);

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
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ABaseDamage")
	float BaseDamage;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "AfterDestroy")
	UParticleSystem* DestroyParticle;

	float OwnerDamage;
	float DamageRate;
};
