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
	bDrawRange = true;
	Segment = 32;

	//create components
	CHelpers::CreateActorComponent<UBlackboardComponent>(this, &Blackboard, "BlackboardComp");
	CHelpers::CreateActorComponent<UCBehaviorComponent>(this, &BehaviorComp, "BehaviorComp");
	CHelpers::CreateActorComponent<UAIPerceptionComponent>(this, &PerceptionComp, "PerceptionComp");

	//create sight
	Sight = CreateDefaultSubobject<UAISenseConfig_Sight>("Sight");
	Sight->PeripheralVisionAngleDegrees = 90.f;
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
	InitialLocation = OwnerEnemy->GetActorLocation();
	ActionRange = OwnerEnemy->GetActionRange();
	EscapeRange = OwnerEnemy->GetEscapeRange();
	DetectRange = OwnerEnemy->GetDetectRange();
	InvisibleRange = OwnerEnemy->GetInvisibleRange();

	Sight->SightRadius = DetectRange;
	Sight->LoseSightRadius = InvisibleRange;

	//set TeamId
	SetGenericTeamId(FGenericTeamId(OwnerEnemy->GetTeamId()));

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

	AnalyzeDistance();

	//for Debug or guide
	CheckFalse(bDrawRange);
	FVector Center = OwnerEnemy->GetActorLocation();
	DrawDebugSphere(GetWorld(), Center, EscapeRange, Segment, FColor::Red);
	DrawDebugSphere(GetWorld(), Center, ActionRange, Segment, FColor::Blue);
	DrawDebugSphere(GetWorld(), Center, Sight->SightRadius, Segment, FColor::Cyan);
	DrawDebugSphere(GetWorld(), Center, Sight->LoseSightRadius, Segment, FColor::Green);
}

void ACAIController::OnPerceptionUpdated(const TArray<AActor*>& UpdatedActors)
{
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

void ACAIController::AnalyzeDistance()
{
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
			float Distance = FVector::Distance(Target->GetActorLocation(), OwnerEnemy->GetActorLocation());
			if (Distance <= GetActionRange())
			{
				BehaviorComp->SetActionMode();
			}
			else if (Distance <= GetEscapeRange())
			{
				BehaviorComp->SetEscapeMode();
			}
			else if (Distance <= GetDetectRange())
			{
				BehaviorComp->SetApproachMode();
			}
			else if (Distance <= GetInvisibleRange())
			{
				BehaviorComp->SetPatrolMode();
			}
			else
			{
				Blackboard->SetValueAsVector("LocationSelectorKey", GetInitialLocation());
				BehaviorComp->SetWaitMode();
			}
		}
	}
}

