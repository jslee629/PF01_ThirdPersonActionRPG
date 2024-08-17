#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryContext.h"
#include "CEnvQueryContext_Target.generated.h"

/**
 * 
 */
UCLASS()
class PF01_API UCEnvQueryContext_Target : public UEnvQueryContext
{
	GENERATED_BODY()

public:
	virtual void ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const override;
};
