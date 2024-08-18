#include "CBTTaskNode_Hitted.h"
#include "Global.h"
#include "AIController.h"

#include "Components/CActionComponent.h"

EBTNodeResult::Type UCBTTaskNode_Hitted::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AAIController* AIC = Cast<AAIController>(OwnerComp.GetOwner());
	CheckNullResult(AIC, EBTNodeResult::Failed);

	APawn* Pawn = AIC->GetPawn();
	CheckNullResult(Pawn, EBTNodeResult::Failed);

	UCActionComponent* ActionComp = CHelpers::GetComponent<UCActionComponent>(Pawn);
	CheckNullResult(ActionComp, EBTNodeResult::Failed);

	ActionComp->Hitted();

	return EBTNodeResult::Succeeded;
}
