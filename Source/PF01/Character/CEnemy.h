#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CEnemy.generated.h"

class UCCharacterAsset;
class UCActionComponent;
class UCStateComponent;
class UCAttributeComponent;
class UMaterialInstanceDynamic;

UCLASS()
class PF01_API ACEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	ACEnemy();

protected:
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public:
	FORCEINLINE UCCharacterAsset* GetPlayerAsset() { return PlayerAsset; }
	FORCEINLINE UCActionComponent* GetActionComp() { return ActionComp; }
	FORCEINLINE UCStateComponent* GetStateComp() { return StateComp; }
	FORCEINLINE UCAttributeComponent* GetAttributeComp() { return AttributeComp; }

private:
	UPROPERTY(EditDefaultsOnly, Category = "CharacterAsset")
	UCCharacterAsset* PlayerAsset;

	UPROPERTY(VisibleDefaultsOnly)
	UCActionComponent* ActionComp;
	UPROPERTY(VisibleDefaultsOnly)
	UCStateComponent* StateComp;
	UPROPERTY(VisibleDefaultsOnly)
	UCAttributeComponent* AttributeComp;

	UMaterialInstanceDynamic* BodyMaterial;
	UMaterialInstanceDynamic* LogoMaterial;

private:
	UPROPERTY(EditAnywhere, Category = "Color")
	FLinearColor Color;

};
