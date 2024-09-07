#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CCharacter.generated.h"

class UCCharacterAsset;
class UCActionComponent;
class UCStateComponent;
class UCAttributeComponent;
class UCCollisionComponent;

UCLASS()
class PF01_API ACCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ACCharacter();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE UCCharacterAsset* GetCharacterAsset() const { return CharacterAsset; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE UCActionComponent* GetActionComp() const { return ActionComp; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE UCStateComponent* GetStateComp() const { return StateComp; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE UCAttributeComponent* GetAttributeComp() const { return AttributeComp; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE UCCollisionComponent* GetCollisionComp() const { return CollisionComp; }

protected:
	//Character Asset
	UPROPERTY(EditDefaultsOnly, Category = "CharacterAsset")
	UCCharacterAsset* CharacterAsset;

	//Actor Components
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "Components")
	UCActionComponent* ActionComp;
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "Components")
	UCStateComponent* StateComp;
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "Components")
	UCAttributeComponent* AttributeComp;
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "Components")
	UCCollisionComponent* CollisionComp;
};
