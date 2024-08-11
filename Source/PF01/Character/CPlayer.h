#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPlayer.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UCCharacterAsset;
class UCActionComponent;
class UCStateComponent;
class UCAttributeComponent;

UCLASS()
class PF01_API ACPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	ACPlayer();

protected:
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;

public:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	void OnMoveForward(float AxisValue);
	void OnMoveRight(float AxisValue);
	void OnTurn(float AxisValue);
	void OnLookUp(float AxisValue);
	void OnRoll();

	UFUNCTION(BlueprintNativeEvent, Category = "Attack")
	void OnAttack();
	UFUNCTION(BlueprintNativeEvent, Category = "Attack")
	void OnSkill1();
	UFUNCTION(BlueprintNativeEvent, Category = "Attack")
	void OnSkill2();
	UFUNCTION(BlueprintNativeEvent, Category = "Attack")
	void OnSkill3();
	UFUNCTION(BlueprintNativeEvent, Category = "Attack")
	void OnSkill4();

public:
	FORCEINLINE UCCharacterAsset* GetPlayerAsset() { return PlayerAsset; }
	FORCEINLINE UCActionComponent* GetActionComp() { return ActionComp; }
	FORCEINLINE UCStateComponent* GetStateComp() { return StateComp; }
	FORCEINLINE UCAttributeComponent* GetAttributeComp() { return AttributeComp; }

private:
	//Character Asset
	UPROPERTY(EditDefaultsOnly, Category = "CharacterAsset")
	UCCharacterAsset* PlayerAsset;

	//Scene Components
	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	UCameraComponent* CameraComp;

protected:
	//Actor Components
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "Components")
	UCActionComponent* ActionComp;
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "Components")
	UCStateComponent* StateComp;
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "Components")
	UCAttributeComponent* AttributeComp;
	
private:
	uint8 TeamId;
};
