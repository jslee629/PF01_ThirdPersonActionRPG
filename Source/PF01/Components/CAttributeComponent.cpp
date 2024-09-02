#include "CAttributeComponent.h"
#include "Global.h"

#include "Character/CPlayer.h"
#include "Character/CEnemy.h"

UCAttributeComponent::UCAttributeComponent()
{
	//Initialize variables
	LV = 0.f;
	EXP = 0.f;
	InitialHP = 0.f;
	InitialMP = 0.f;
	InitialSP = 0.f;
	InitialAP = 0.f;
	InitialDP = 0.f;
}

void UCAttributeComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UCAttributeComponent::InitializeComponent()
{
	Super::InitializeComponent();

}

ACharacter* UCAttributeComponent::GetOwnerCharacter()
{
	return OwnerCharacter;
}

void UCAttributeComponent::SetOwnerCharacter(ACharacter* InCharacter)
{
	OwnerCharacter = InCharacter;
}

void UCAttributeComponent::LevelUp()
{
	if (EXP < LV * 100.f) return;

	LV++;
	EXP = 0.f;
}

void UCAttributeComponent::SetInitialHealthPoint()
{
	ACPlayer* Player = Cast<ACPlayer>(GetOwner());
	if (Player)
	{
		InitialHP = Player->GetCharacterAsset()->GetAttribute().HealthPoint;
		return;
	}

	ACEnemy* Enemy = Cast<ACEnemy>(GetOwner());
	if (Enemy)
	{
		InitialHP = Enemy->GetCharacterAsset()->GetAttribute().HealthPoint;
		return;
	}
}

void UCAttributeComponent::SetInitialManaPoint()
{
	ACPlayer* Player = Cast<ACPlayer>(GetOwner());
	if (Player)
	{
		InitialMP = Player->GetCharacterAsset()->GetAttribute().ManaPoint;
	}

	ACEnemy* Enemy = Cast<ACEnemy>(GetOwner());
	if (Enemy)
	{
		InitialHP = Enemy->GetCharacterAsset()->GetAttribute().HealthPoint;
		return;
	}
}

void UCAttributeComponent::SetInitialSteminaPoint()
{
	ACPlayer* Player = Cast<ACPlayer>(GetOwner());
	if (Player)
	{
		InitialSP = Player->GetCharacterAsset()->GetAttribute().SteminaPoint;
	}

	ACEnemy* Enemy = Cast<ACEnemy>(GetOwner());
	if (Enemy)
	{
		InitialHP = Enemy->GetCharacterAsset()->GetAttribute().HealthPoint;
		return;
	}
}

void UCAttributeComponent::SetInitialAttackPoint()
{
	ACPlayer* Player = Cast<ACPlayer>(GetOwner());
	if (Player)
	{
		InitialAP = Player->GetCharacterAsset()->GetAttribute().AttackPoint;
	}

	ACEnemy* Enemy = Cast<ACEnemy>(GetOwner());
	if (Enemy)
	{
		InitialHP = Enemy->GetCharacterAsset()->GetAttribute().HealthPoint;
		return;
	}
}

void UCAttributeComponent::SetInitialDefensePoint()
{
	ACPlayer* Player = Cast<ACPlayer>(GetOwner());
	if (Player)
	{
		InitialDP = Player->GetCharacterAsset()->GetAttribute().DefensePoint;
	}

	ACEnemy* Enemy = Cast<ACEnemy>(GetOwner());
	if (Enemy)
	{
		InitialHP = Enemy->GetCharacterAsset()->GetAttribute().HealthPoint;
		return;
	}
}

void UCAttributeComponent::SetMaxHealthPoint()
{
	MaxHP = InitialHP + LV * 10.f;
}

void UCAttributeComponent::SetMaxManaPoint()
{
	MaxMP = InitialMP + LV * 10.f;
}

void UCAttributeComponent::SetMaxSteminaPoint()
{
	MaxSP = InitialSP + LV * 40.f;
}

void UCAttributeComponent::SetMaxAttackPoint()
{
	MaxAP = InitialAP + LV * 4.f;
}

void UCAttributeComponent::SetMaxDefensePoint()
{
	MaxDP = InitialDP + LV * 4.f;
}

void UCAttributeComponent::InitializeCurHealth()
{
	CurHP = MaxHP;
}

void UCAttributeComponent::InitializeCurMana()
{
	CurMP = MaxMP;
}

void UCAttributeComponent::InitializeCurStemina()
{
	CurSP = MaxSP;
}

void UCAttributeComponent::InitializeCurAttack()
{
	CurAP = MaxAP;
}

void UCAttributeComponent::InitializeCurDefense()
{
	CurDP = MaxDP;
}

void UCAttributeComponent::ChangeCurHP(float Change)
{
	CurHP += Change;

	CurHP = FMath::Clamp(CurHP, 0.f, MaxHP);
}

void UCAttributeComponent::ChangeCurMP(float Change)
{
	CurMP += Change;

	CurMP = FMath::Clamp(CurMP, 0.f, MaxHP);
}

void UCAttributeComponent::ChangeCurSP(float Change)
{
	CurSP += Change;
}

void UCAttributeComponent::ChangeCurAP(float Change)
{
	CurAP += Change;
}

void UCAttributeComponent::ChangeCurDP(float Change)
{
	CurDP += Change;
}

