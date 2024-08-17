#include "CAttributeComponent.h"
#include "Global.h"

#include "Character/CPlayer.h"

UCAttributeComponent::UCAttributeComponent()
{
	//Save Owner
	OwnerCharacter = Cast<ACharacter>(GetOwner());
	CheckNull(OwnerCharacter);
}

void UCAttributeComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UCAttributeComponent::LevelUp()
{
	if (EXP_Point < LV_Point * 100.f) return;
	LV_Point++;
	EXP_Point = 0;
}

void UCAttributeComponent::SetInitialHealthPoint()
{
	ACPlayer* Player = Cast<ACPlayer>(OwnerCharacter);
	if (Player)
	{
		HP = Player->GetCharacterAsset()->GetAttribute().HealthPoint;
	}
}

void UCAttributeComponent::SetInitialManaPoint()
{
	ACPlayer* Player = Cast<ACPlayer>(OwnerCharacter);
	if (Player)
	{
		MP = Player->GetCharacterAsset()->GetAttribute().ManaPoint;
	}
}

void UCAttributeComponent::SetInitialSteminaPoint()
{
	ACPlayer* Player = Cast<ACPlayer>(OwnerCharacter);
	if (Player)
	{
		SP = Player->GetCharacterAsset()->GetAttribute().SteminaPoint;
	}
}

void UCAttributeComponent::SetInitialAttackPoint()
{
	ACPlayer* Player = Cast<ACPlayer>(OwnerCharacter);
	if (Player)
	{
		AP = Player->GetCharacterAsset()->GetAttribute().AttackPoint;
	}
}

void UCAttributeComponent::SetInitialDefensePoint()
{
	ACPlayer* Player = Cast<ACPlayer>(OwnerCharacter);
	if (Player)
	{
		DP = Player->GetCharacterAsset()->GetAttribute().DefensePoint;
	}
}

void UCAttributeComponent::SetMaxHealthPoint()
{
	MaxHealthP = HP + LV_Point * 100.f;
}

void UCAttributeComponent::SetMaxManaPoint()
{
	MaxManaP = MP + LV_Point * 100.f;
}

void UCAttributeComponent::SetMaxSteminaPoint()
{
	MaxSteminaP = SP + LV_Point * 400.f;
}

void UCAttributeComponent::SetMaxAttackPoint()
{
	MaxAttackP = AP + LV_Point * 10.f;
}

void UCAttributeComponent::SetMaxDefensePoint()
{
	MaxHealthP = MP + LV_Point * 10.f;
}

void UCAttributeComponent::InitializeCurHealth()
{
	CurHealthP = MaxHealthP;
}

void UCAttributeComponent::InitializeCurMana()
{
	CurManaP = MaxManaP;
}

void UCAttributeComponent::InitializeCurStemina()
{
	CurSteminaP = MaxSteminaP;
}

void UCAttributeComponent::InitializeCurAttack()
{
	CurAttackP = MaxAttackP;
}

void UCAttributeComponent::InitializeCurDefense()
{
	CurDefenseP = MaxHealthP;
}

