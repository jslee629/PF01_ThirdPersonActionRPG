#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interfaces/CActorComponentInterface.h"
#include "CCollisionComponent.generated.h"

class ACharacter;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PF01_API UCCollisionComponent : public UActorComponent, public ICActorComponentInterface
{
	GENERATED_BODY()

public:	
	UCCollisionComponent();

protected:
	virtual void BeginPlay() override;
	virtual void InitializeComponent() override;

public:
	UFUNCTION()
	void OnComponentBeginOverlap
	(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);

	//Inherited from ICActorComponentInterface
	virtual void SetOwnerCharacter(ACharacter* InCharacter) override;

private:
	float CalculateProjectileDamage(AActor* OtherActor, UPrimitiveComponent* OtherComp);
	float CalculateMeleeDamage(AActor* OtherActor, UPrimitiveComponent* OtherComp);

private:
	ACharacter* OwnerCharacter;
};