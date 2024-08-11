#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CBehaviorComponent.generated.h"

UENUM(BlueprintType)
enum class EAIBehavior : uint8
{
	Wait,
	Approach,
	Action,
	Patrol,
	Hitted,
	Escape,
	Max
};

class ACharacter;
class UBlackboardComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PF01_API UCBehaviorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCBehaviorComponent();

protected:
	virtual void BeginPlay() override;

public:
	void SetBlackboardComp(UBlackboardComponent* InComp);

	UFUNCTION(BlueprintPure)
	bool IsWaitMode();
	UFUNCTION(BlueprintPure)
	bool IsApproachMode();
	UFUNCTION(BlueprintPure)
	bool IsActionMode();
	UFUNCTION(BlueprintPure)
	bool IsPatrolMode();
	UFUNCTION(BlueprintPure)
	bool IsHittedMode();
	UFUNCTION(BlueprintPure)
	bool IsEscapeMode();

	void SetWaitMode();
	void SetApproachMode();
	void SetActionMode();
	void SetPatrolMode();
	void SetHittedMode();
	void SetEscapeMode();
		
	ACharacter* GetTargetKey();
	FVector GetLocationKey();

private:
	EAIBehavior GetBehavior();
	void ChangeBehavior(EAIBehavior InNewBehavior);

private:
	UBlackboardComponent* BlackboardComp;

	UPROPERTY(EditDefaultsOnly, Category = "Blackboard")
	FName BehaviorKey;
	UPROPERTY(EditDefaultsOnly, Category = "Blackboard")
	FName TargetKey;
	UPROPERTY(EditDefaultsOnly, Category = "Blackboard")
	FName LocationKey;
};
