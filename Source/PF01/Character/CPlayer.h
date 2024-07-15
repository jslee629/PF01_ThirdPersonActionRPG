#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPlayer.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UCCharacterAsset;
class UCActionComponent;
class UCStateComponent;

UCLASS()
class PF01_API ACPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	ACPlayer();

protected:
	virtual void BeginPlay() override;

public:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	void OnMoveForward(float AxisValue);
	void OnMoveRight(float AxisValue);
	void OnTurn(float AxisValue);
	void OnLookUp(float AxisValue);
	void OnRoll();
	void OnAttack();
	void OnSkill1();
	void OnSkill2();
	void OnSkill3();
	void OnSkill4();

public:
	FORCEINLINE UCCharacterAsset* GetPlayerAsset() { return PlayerAsset; }
	FORCEINLINE UCActionComponent* GetActionComp() { return ActionComp; }
	FORCEINLINE UCStateComponent* GetStateComp() { return StateComp; }

private:
	UPROPERTY(EditDefaultsOnly, Category = "CharacterAsset")
	UCCharacterAsset* PlayerAsset;

protected:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

private:
	UCActionComponent* ActionComp;
	UCStateComponent* StateComp;
};
