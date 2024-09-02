#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CStateComponent.generated.h"

class ACharacter;

UENUM(BlueprintType)
enum class EStateType : uint8
{
	Idle,
	Roll,
	Attack,
	Hitted,
	Dead,
	Max
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FStateTypeChanged, EStateType, InPrevType, EStateType, InNewType);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PF01_API UCStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCStateComponent();

protected:
	virtual void BeginPlay() override;
	virtual void InitializeComponent() override;

public:
	FORCEINLINE EStateType GetType() { return Type; }

	UFUNCTION(BlueprintPure, Category = "State")
	FORCEINLINE bool IsIdleMode() { return Type == EStateType::Idle; }
	UFUNCTION(BlueprintPure, Category = "State")
	FORCEINLINE bool IsRollMode() { return Type == EStateType::Roll; }
	UFUNCTION(BlueprintPure, Category = "State")
	FORCEINLINE bool IsAttackMode() { return Type == EStateType::Attack; }
	UFUNCTION(BlueprintPure, Category = "State")
	FORCEINLINE bool IsHittedMode() { return Type == EStateType::Hitted; }
	UFUNCTION(BlueprintPure, Category = "State")
	FORCEINLINE bool IsDeadMode() { return Type == EStateType::Dead; }

	void SetIdleMode();
	void SetRollMode();
	void SetAttackMode();
	void SetHittedMode();
	void SetDeadMode();

	ACharacter* GetOwnerCharacter();
	void SetOwnerCharacter(ACharacter* InCharacter);

private:
	void ChangeType(EStateType InNewType);

public:
	UPROPERTY(BlueprintAssignable)
	FStateTypeChanged OnStateTypeChanged;

private:
	ACharacter* OwnerCharacter;
	EStateType Type;
};
