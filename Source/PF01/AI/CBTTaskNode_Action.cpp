#include "CBTTaskNode_Action.h"
#include "Global.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "Components/CActionComponent.h"
#include "Components/CStateComponent.h"
#include "Character/CPlayer.h"

EBTNodeResult::Type UCBTTaskNode_Action::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AAIController* AIC = Cast<AAIController>(OwnerComp.GetOwner());
	CheckNullResult(AIC, EBTNodeResult::Failed);

	APawn* Pawn = AIC->GetPawn();
	CheckNullResult(Pawn, EBTNodeResult::Failed);

	UBlackboardComponent* BB = AIC->GetBlackboardComponent();

	AIC->SetFocus(Cast<AActor>(BB->GetValueAsObject("TargetSelectorKey")));

	UCActionComponent* ActionComp = CHelpers::GetComponent<UCActionComponent>(Pawn);
	CheckNullResult(ActionComp, EBTNodeResult::Failed);

	ActionComp->Attack();

	return EBTNodeResult::Succeeded;
}
