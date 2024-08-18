#include "CBTService_AnalyzeDistance.h"
#include "Global.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AISenseConfig_Sight.h"

#include "Character/CAIController.h"
#include "Character/CEnemy.h"
#include "Components/CStateComponent.h"
#include "Components/CBehaviorComponent.h"

void UCBTService_AnalyzeDistance::OnSearchStart(FBehaviorTreeSearchData& SearchData)
{
	Super::OnSearchStart(SearchData);

	UBlackboardComponent* Blackboard = SearchData.OwnerComp.GetBlackboardComponent();
	CheckNull(Blackboard);

	ACEnemy* SelfEnemy = Cast<ACEnemy>(Blackboard->GetValueAsObject("SelfActor"));
	CheckNull(SelfEnemy);

	ACAIController* AIC = SelfEnemy->GetController<ACAIController>();
	CheckNull(AIC);

	//calculate distance from target to me
	AActor* Target = Cast<AActor>(Blackboard->GetValueAsObject("TargetSelectorKey"));
	if (Target)
	{
		UCStateComponent* StateComp = CHelpers::GetComponent<UCStateComponent>(Target);

		//if target die
		if (StateComp && StateComp->IsDeadMode())
		{
			Blackboard->SetValueAsObject("TargetSelectorKey", nullptr);
		}
		else
		{
			UCBehaviorComponent* BehaviorComp = Cast<UCBehaviorComponent>(AIC);
			CheckNull(BehaviorComp);

			float Distance = FVector::Distance(Target->GetActorLocation(), SelfEnemy->GetActorLocation());
			if (Distance <= SelfEnemy->GetActionRange())
			{
				BehaviorComp->SetActionMode();
			}
			else if (Distance <= SelfEnemy->GetEscapeRange())
			{
				Blackboard->SetValueAsVector("LocationSelectorKey", AIC->GetInitialLocation());
				BehaviorComp->SetEscapeMode();
			}
			else if (Distance <= SelfEnemy->GetDetectRange())
			{
				BehaviorComp->SetApproachMode();
			}
			else if (Distance <= SelfEnemy->GetInvisibleRange())
			{
				BehaviorComp->SetPatrolMode();
			}
			else
			{
				BehaviorComp->SetWaitMode();
			}
		}
	}
}