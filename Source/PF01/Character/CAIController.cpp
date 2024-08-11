#include "CAIController.h"
#include "Global.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "GameFramework/Character.h"

#include "Components/CStateComponent.h"
#include "Components/CBehaviorComponent.h"
#include "CEnemy.h"
#include "CPlayer.h"

ACAIController::ACAIController()
{
	PrimaryActorTick.bCanEverTick = true;

	//initialize vairables
	BehaviorRange = 150.f;
	bDrawRange = true;
	Segment = 32;

	//create components
	CHelpers::CreateActorComponent<UBlackboardComponent>(this, &Blackboard, "BlackboardComp");
	CHelpers::CreateActorComponent<UCBehaviorComponent>(this, &BehaviorComp, "BehaviorComp");
	CHelpers::CreateActorComponent<UAIPerceptionComponent>(this, &PerceptionComp, "PerceptionComp");

	//create sight
	Sight = CreateDefaultSubobject<UAISenseConfig_Sight>("Sight");

	//->detect properties
	Sight->SightRadius = 500.f;
	Sight->LoseSightRadius = 600.f;
	Sight->PeripheralVisionAngleDegrees = 90.f;

	//->what to detect
	Sight->DetectionByAffiliation.bDetectEnemies = true;
	Sight->DetectionByAffiliation.bDetectFriendlies = false;
	Sight->DetectionByAffiliation.bDetectNeutrals = false;

	PerceptionComp->ConfigureSense(*Sight);
	PerceptionComp->SetDominantSense(Sight->GetSenseImplementation());
}

void ACAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	OwnerEnemy = Cast<ACEnemy>(InPawn);

	SetGenericTeamId(OwnerEnemy->GetTeamId());

	//set blackboard and attach to behavior component
	ensure(OwnerEnemy->GetBehaviorTree());
	UseBlackboard(OwnerEnemy->GetBehaviorTree()->BlackboardAsset, Blackboard);
	BehaviorComp->SetBlackboardComp(Blackboard);

	RunBehaviorTree(OwnerEnemy->GetBehaviorTree());

	PerceptionComp->OnPerceptionUpdated.AddDynamic(this, &ACAIController::OnPerceptionUpdated);
}

void ACAIController::OnUnPossess()
{
	Super::OnUnPossess();

	PerceptionComp->OnPerceptionUpdated.Clear();
}

void ACAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ACharacter* Target = Cast<ACharacter>(Blackboard->GetValueAsObject("TargetSelectorKey"));
	if (Target)
	{
		UCStateComponent* StateComp = CHelpers::GetComponent<UCStateComponent>(Target);
		if (StateComp && StateComp->IsDeadMode())
		{
			Blackboard->SetValueAsObject("TargetSelectorKey", nullptr);
		}
	}

	//for Debug or guide
	CheckFalse(bDrawRange);
	FVector Center = OwnerEnemy->GetActorLocation();
	DrawDebugSphere(GetWorld(), Center, Sight->SightRadius, Segment, FColor::Green);
	DrawDebugSphere(GetWorld(), Center, BehaviorRange, Segment, FColor::Red);
}

float ACAIController::GetSightRadius()
{
	return Sight->SightRadius;
}

void ACAIController::OnPerceptionUpdated(const TArray<AActor*>& UpdatedActors)
{
	if (UpdatedActors.Num() == 0)
	{
		return;
	}

	for (const auto& Actor : UpdatedActors)
	{
		ACPlayer* Player = Cast<ACPlayer>(Actor);
		if (Player)
		{
			Blackboard->SetValueAsObject("TargetSelectorKey", Player);
			break;
		}
		else
		{
			ACharacter* Target = Cast<ACharacter>(Actor);
			if (Target)
			{
				Blackboard->SetValueAsObject("TargetSelectorKey", Target);
				break;
			}
		}
	}
}


