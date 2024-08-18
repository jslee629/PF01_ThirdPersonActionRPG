#include "CBTService_RandomLocation.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NavigationSystem.h"
#include "Kismet/KismetMathLibrary.h"

void UCBTService_RandomLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	UBlackboardComponent* BB = OwnerComp.GetBlackboardComponent();
	AActor* SelfActor = Cast<AActor>(BB->GetValueAsObject("SelfActor"));

	//TODO: GetRandomPointInNavigableRadius 함수를 대체할 함수 찾기
	//FVector NewLocation = UNavigationSystemV1::GetRandomPointInNavigableRadius(GetWorld(), SelfActor->GetActorLocation(), 10.f);

    FVector Origin = SelfActor->GetActorLocation();
    float Radius = 500.f;
    FVector RandomPoint = UKismetMathLibrary::RandomPointInBoundingBox(Origin, FVector(Radius, Radius, 0.f));
	BB->SetValueAsVector("LocationSelectorKey", RandomPoint);

}