#include "CStateComponent.h"
#include "GameFramework/Character.h"

UCStateComponent::UCStateComponent()
{
	Type = EStateType::Idle;
}


void UCStateComponent::BeginPlay()
{
	Super::BeginPlay();

	//initial state : Idle
	SetIdleMode();
}

void UCStateComponent::InitializeComponent()
{
	Super::InitializeComponent();

	SetOwnerCharacter(Cast<ACharacter>(GetOwner()));
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

void UCStateComponent::SetOwnerCharacter(ACharacter* InCharacter)
{
	OwnerCharacter = InCharacter;
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
