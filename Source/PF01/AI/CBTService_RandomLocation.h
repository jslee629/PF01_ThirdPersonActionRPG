#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "CBTService_RandomLocation.generated.h"

UCLASS()
class PF01_API UCBTService_RandomLocation : public UBTService
{
	GENERATED_BODY()
	
public:
	virtual void OnSearchStart(FBehaviorTreeSearchData& SearchData) override;
};
