#include "CBTService_RandomLocation.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NavigationSystem.h"

void UCBTService_RandomLocation::OnSearchStart(FBehaviorTreeSearchData& SearchData)
{
	Super::OnSearchStart(SearchData);

	UBlackboardComponent* BB = SearchData.OwnerComp.GetBlackboardComponent();
	AActor* SelfActor = Cast<AActor>(BB->GetValueAsObject("SelfKey"));

	//TODO: GetRandomPointInNavigableRadius �Լ��� ��ü�� �Լ� ã��
	//FVector NewLocation = UNavigationSystemV1::GetRandomPointInNavigableRadius(GetWorld(), SelfActor->GetActorLocation(), 10.f);
	//BB->SetValueAsVector("LocationSelectorKey", NewLocation);
}