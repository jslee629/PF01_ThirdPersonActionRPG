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

private:
	UFUNCTION()
	void OnPerceptionUpdated(const TArray<AActor*>& UpdatedActors);

	void AnalyzeDistance(AActor* Target);

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
	ACEnemy* OwnerEnemy;
	FVector InitialLocation;
	UAISenseConfig_Sight* Sight;
};
