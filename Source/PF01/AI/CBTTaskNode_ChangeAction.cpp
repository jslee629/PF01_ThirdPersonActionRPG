#include "CBTTaskNode_ChangeAction.h"
#include "Global.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "Components/CActionComponent.h"
#include "Components/CStateComponent.h"
#include "Character/CPlayer.h"

EBTNodeResult::Type UCBTTaskNode_ChangeAction::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
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

	int32 Number = FMath::RandHelper(4);
	ActionComp->ChangeSkill(Number);

	return EBTNodeResult::Succeeded;
}