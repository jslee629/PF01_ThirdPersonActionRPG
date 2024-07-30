#pragma once

#include "CoreMinimal.h"
#include "Character/CEnemy.h"
#include "CMob.generated.h"

class UBehaviorTree;

UCLASS()
class PF01_API ACMob : public ACEnemy
{
	GENERATED_BODY()
	
public:
	ACMob();

	FORCEINLINE UBehaviorTree* GetBehaviorTree() { return BehaviorTree; }
	FORCEINLINE uint8 GetTeamId() { return TeamId; }

private:
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UBehaviorTree* BehaviorTree;
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	uint8 TeamId;
};
