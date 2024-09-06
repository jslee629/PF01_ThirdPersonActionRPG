#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CCollisionComponent.generated.h"

class ACharacter;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PF01_API UCCollisionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCCollisionComponent();

protected:
	virtual void BeginPlay() override;
	virtual void InitializeComponent() override;

public:
	UFUNCTION()
	void OnColliderBeginOverlap
	(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);

	ACharacter* GetOwnerCharacter();
	void SetOwnerCharacter(ACharacter* InCharacter);

private:
	UFUNCTION()
	float CalculateProjectileDamage(AActor* OtherActor, UPrimitiveComponent* OtherComp);
	UFUNCTION()
	float CalculateMeleeDamage(AActor* OtherActor, UPrimitiveComponent* OtherComp);

private:
	ACharacter* OwnerCharacter;
};
