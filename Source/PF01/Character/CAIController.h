#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CAIController.generated.h"

class ACEnemy;
class UAIPerceptionComponent;
class UCBehaviorComponent;
class UAISenseConfig_Sight;

UCLASS()
class PF01_API ACAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	ACAIController();

protected:
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

public:
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE UAISenseConfig_Sight* GetSight() { return Sight; }
	FORCEINLINE float GetActionRange() { return ActionRange; }
	FORCEINLINE float GetEscapeRange() { return EscapeRange; }
	FORCEINLINE float GetDetectRange() { return DetectRange; }
	FORCEINLINE float GetInvisibleRange() { return InvisibleRange; }
	FORCEINLINE FVector GetInitialLocation() { return InitialLocation; }

private:
	UFUNCTION()
	void OnPerceptionUpdated(const TArray<AActor*>& UpdatedActors);

	void AnalyzeDistance();

protected:
	UPROPERTY(VisibleDefaultsOnly)
	UCBehaviorComponent* BehaviorComp;
	UPROPERTY(VisibleDefaultsOnly)
	UAIPerceptionComponent* PerceptionComp;

private:
	UPROPERTY(EditAnywhere, Category = "Debug")
	bool bDrawRange;
	UPROPERTY(EditAnywhere)
	int32 Segment;

private:
	float ActionRange;
	float EscapeRange;
	float DetectRange;
	float InvisibleRange;
	ACEnemy* OwnerEnemy;
	FVector InitialLocation;
	UAISenseConfig_Sight* Sight;
};
