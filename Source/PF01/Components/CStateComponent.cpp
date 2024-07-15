#include "CStateComponent.h"

UCStateComponent::UCStateComponent()
{
	//initial state : Idle
	SetIdleMode();
}


void UCStateComponent::BeginPlay()
{
	Super::BeginPlay();

	
}

void UCStateComponent::SetIdleMode()
{
	ChangeType(EStateType::Idle);
}

void UCStateComponent::SetRollMode()
{
	ChangeType(EStateType::Roll);
}

void UCStateComponent::SetAttackMode()
{
	ChangeType(EStateType::Attack);
}

void UCStateComponent::SetHittedMode()
{
	ChangeType(EStateType::Hitted);
}

void UCStateComponent::SetDeadMode()
{
	ChangeType(EStateType::Dead);
}

void UCStateComponent::ChangeType(EStateType InNewType)
{
	EStateType Prev = Type;
	Type = InNewType;

	if (OnStateTypeChanged.IsBound())
	{
		OnStateTypeChanged.Broadcast(Prev, InNewType);
	}
}
