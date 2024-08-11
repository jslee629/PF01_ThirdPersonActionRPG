#include "CBehaviorComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"

UCBehaviorComponent::UCBehaviorComponent()
{
	//initialize variables
	BehaviorKey = "BehaviorSelectorKey";
	TargetKey = "TargetSelectorKey";
	LocationKey = "LocationSelectorKey";
}

void UCBehaviorComponent::BeginPlay()
{
	Super::BeginPlay();

	
}

void UCBehaviorComponent::SetBlackboardComp(UBlackboardComponent* InComp)
{
	//initialize BlackboardComp;
	BlackboardComp = InComp;
}

bool UCBehaviorComponent::IsWaitMode()
{
	return GetBehavior() == EAIBehavior::Wait;
}

bool UCBehaviorComponent::IsApproachMode()
{
	return GetBehavior() == EAIBehavior::Approach;
}

bool UCBehaviorComponent::IsActionMode()
{
	return GetBehavior() == EAIBehavior::Action;
}

bool UCBehaviorComponent::IsPatrolMode()
{
	return GetBehavior() == EAIBehavior::Patrol;
}

bool UCBehaviorComponent::IsHittedMode()
{
	return GetBehavior() == EAIBehavior::Hitted;
}

bool UCBehaviorComponent::IsEscapeMode()
{
	return GetBehavior() == EAIBehavior::Escape;
}

void UCBehaviorComponent::SetWaitMode()
{
	ChangeBehavior(EAIBehavior::Wait);
}

void UCBehaviorComponent::SetApproachMode()
{
	ChangeBehavior(EAIBehavior::Approach);
}

void UCBehaviorComponent::SetActionMode()
{
	ChangeBehavior(EAIBehavior::Action);
}

void UCBehaviorComponent::SetPatrolMode()
{
	ChangeBehavior(EAIBehavior::Patrol);
}

void UCBehaviorComponent::SetHittedMode()
{
	ChangeBehavior(EAIBehavior::Hitted);
}

void UCBehaviorComponent::SetEscapeMode()
{
	ChangeBehavior(EAIBehavior::Escape);
}

ACharacter* UCBehaviorComponent::GetTargetKey()
{
	return Cast<ACharacter>(BlackboardComp->GetValueAsObject(TargetKey));
}

FVector UCBehaviorComponent::GetLocationKey()
{
	return BlackboardComp->GetValueAsVector(LocationKey);
}

EAIBehavior UCBehaviorComponent::GetBehavior()
{
	return (EAIBehavior)BlackboardComp->GetValueAsEnum(BehaviorKey);
}

void UCBehaviorComponent::ChangeBehavior(EAIBehavior InNewBehavior)
{
	BlackboardComp->SetValueAsEnum(BehaviorKey, (uint8)InNewBehavior);
}
