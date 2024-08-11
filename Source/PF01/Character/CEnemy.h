#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/CCharacterInterface.h"
#include "CEnemy.generated.h"

class UCCharacterAsset;
class UCActionComponent;
class UCStateComponent;
class UCAttributeComponent;
class UMaterialInstanceDynamic;
class UBehaviorTree;

UCLASS()
class PF01_API ACEnemy : public ACharacter, public ICCharacterInterface
{
	GENERATED_BODY()

public:
	ACEnemy();

protected:
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;

public:
	FORCEINLINE UCCharacterAsset* GetPlayerAsset() { return PlayerAsset; }
	FORCEINLINE UCActionComponent* GetActionComp() { return ActionComp; }
	FORCEINLINE UCStateComponent* GetStateComp() { return StateComp; }
	FORCEINLINE UCAttributeComponent* GetAttributeComp() { return AttributeComp; }
	FORCEINLINE UBehaviorTree* GetBehaviorTree() { return BehaviorTree; }
	FORCEINLINE uint8 GetTeamId() { return TeamId; }

	//Inherited from ICCharacterInterface
	virtual void ChangeColor() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "CharacterAsset")
	UCCharacterAsset* PlayerAsset;

	UPROPERTY(VisibleDefaultsOnly, Category = "Compnents")
	UCActionComponent* ActionComp;
	UPROPERTY(VisibleDefaultsOnly, Category = "Compnents")
	UCStateComponent* StateComp;
	UPROPERTY(VisibleDefaultsOnly, Category = "Compnents")
	UCAttributeComponent* AttributeComp;

	UMaterialInstanceDynamic* BodyMaterial;
	UMaterialInstanceDynamic* LogoMaterial;

private:
	UPROPERTY(EditAnywhere, Category = "Color")
	FLinearColor Color;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UBehaviorTree* BehaviorTree;

	UPROPERTY(EditDefaultsOnly, Category = "TeamId")
	uint8 TeamId;
};
