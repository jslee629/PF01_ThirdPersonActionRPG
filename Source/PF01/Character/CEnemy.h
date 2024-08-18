#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GenericTeamAgentInterface.h"
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
	FORCEINLINE UCCharacterAsset* GetCharacterAsset() { return CharacterAsset; }
	FORCEINLINE UCActionComponent* GetActionComp() { return ActionComp; }
	FORCEINLINE UCStateComponent* GetStateComp() { return StateComp; }
	FORCEINLINE UCAttributeComponent* GetAttributeComp() { return AttributeComp; }
	FORCEINLINE UBehaviorTree* GetBehaviorTree() { return BehaviorTree; }
	FORCEINLINE uint8 GetTeamId() { return TeamId; }
	FORCEINLINE float GetActionRange() { return ActionRange; }
	FORCEINLINE float GetEscapeRange() { return EscapeRange; }
	FORCEINLINE float GetDetectRange() { return DetectRange; }
	FORCEINLINE float GetInvisibleRange() { return InvisibleRange; }

	//Inherited from ICCharacterInterface
	virtual void ChangeColor() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "CharacterAsset")
	UCCharacterAsset* CharacterAsset;

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
