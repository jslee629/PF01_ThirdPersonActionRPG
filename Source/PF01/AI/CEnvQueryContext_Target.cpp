#include "CEnvQueryContext_Target.h"
#include "Global.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Actor.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "GameFramework/Character.h"

#include "Components/CBehaviorComponent.h"
#include "Character/CEnemy.h"

void UCEnvQueryContext_Target::ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const
{
	Super::ProvideContext(QueryInstance, ContextData);

	ACEnemy* Querior = Cast<ACEnemy>(QueryInstance.Owner.Get());
	if (Querior)
	{
		UCBehaviorComponent* BehaviorComp = CHelpers::GetComponent<UCBehaviorComponent>(Querior->GetController());
		if (BehaviorComp)
		{
			ACharacter* Target = BehaviorComp->GetTargetKey();
			if (Target)
			{
				UEnvQueryItemType_Actor::SetContextHelper(ContextData, Target);
				return;
			}
		}
	}

	UEnvQueryItemType_Actor::SetContextHelper(ContextData, Querior);
}