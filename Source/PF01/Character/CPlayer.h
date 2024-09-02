#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/CCharacterInterface.h"
#include "Components/CStateComponent.h"
#include "GenericTeamAgentInterface.h"
#include "CPlayer.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UCCharacterAsset;
class UCActionComponent;
class UCStateComponent;
class UCAttributeComponent;
class UCCollisionComponent;

UCLASS()
class PF01_API ACPlayer : public ACharacter, public ICCharacterInterface, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	ACPlayer();

protected:
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;

public:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Inherited from IGenericTeamAgentInterface
	virtual FGenericTeamId GetGenericTeamId() const override;

	//Inherited from ICharacterInterface
	virtual void Damaged(AActor* CausedActor, float Damage, const FHitResult& HitResult) override;
	virtual void SendDataToProjectile(AActor* OutProjectile) override;

protected:
	void OnMoveForward(float AxisValue);
	void OnMoveRight(float AxisValue);
	void OnTurn(float AxisValue);
	void OnLookUp(float AxisValue);
	void OnJump();
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
	FORCEINLINE UCCharacterAsset* GetCharacterAsset() const { return CharacterAsset; }
	FORCEINLINE UCActionComponent* GetActionComp() const { return ActionComp; }
	FORCEINLINE UCStateComponent* GetStateComp() const { return StateComp; }
	FORCEINLINE UCAttributeComponent* GetAttributeComp() const { return AttributeComp; }

private:
	UFUNCTION()
	void OnStateTypeChanged(EStateType InPrevType, EStateType InNewType);

private:
	//Character Asset
	UPROPERTY(EditDefaultsOnly, Category = "CharacterAsset")
	UCCharacterAsset* CharacterAsset;

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
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "Components")
	UCCollisionComponent* CollisionComp;

private:
	UPROPERTY(EditDefaultsOnly, Category = "TeamId")
	uint8 TeamId;
};
