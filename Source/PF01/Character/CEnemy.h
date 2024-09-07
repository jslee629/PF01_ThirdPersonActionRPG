#pragma once

#include "CoreMinimal.h"
#include "Character/CCharacter.h"
#include "GenericTeamAgentInterface.h"
#include "Interfaces/CCharacterInterface.h"
#include "CEnemy.generated.h"

class UCCharacterAsset;
class UCActionComponent;
class UCStateComponent;
class UCAttributeComponent;
class UMaterialInstanceDynamic;
class UBehaviorTree;
class UCCollisionComponent;

UCLASS()
class PF01_API ACEnemy : public ACCharacter, public ICCharacterInterface
{
	GENERATED_BODY()

public:
	ACEnemy();

protected:
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;

public:
	FORCEINLINE UBehaviorTree* GetBehaviorTree() { return BehaviorTree; }
	FORCEINLINE uint8 GetTeamId() { return TeamId; }
	FORCEINLINE float GetActionRange() { return ActionRange; }
	FORCEINLINE float GetEscapeRange() { return EscapeRange; }
	FORCEINLINE float GetDetectRange() { return DetectRange; }
	FORCEINLINE float GetInvisibleRange() { return InvisibleRange; }

	//Inherited from ICCharacterInterface
	virtual void ChangeColor() override;
	virtual void Damaged(AActor* CausedActor, float Damage, const FHitResult& HitResult) override;
	virtual void SendDataToProjectile(AActor* OutProjectile) override;

protected:
	UMaterialInstanceDynamic* BodyMaterial;
	UMaterialInstanceDynamic* LogoMaterial;

	UPROPERTY(EditAnywhere, Category = "Color")
	FLinearColor Color;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UBehaviorTree* BehaviorTree;

private:
	UPROPERTY(EditDefaultsOnly, Category = "TeamId")
	uint8 TeamId;
	UPROPERTY(EditAnywhere, Category = "BehaviorRange")
	float ActionRange;
	UPROPERTY(EditAnywhere, Category = "BehaviorRange")
	float EscapeRange;
	UPROPERTY(EditAnywhere, Category = "BehaviorRange")
	float DetectRange;
	UPROPERTY(EditAnywhere, Category = "BehaviorRange")
	float InvisibleRange;
};
