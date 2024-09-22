#include "CAttributeComponent.h"
#include "Global.h"

#include "Character/CCharacter.h"
#include "Components/CStateComponent.h"

UCAttributeComponent::UCAttributeComponent()
{
	//Initialize variables
	LV = 1.f;
	EXP = 0.f;
}

void UCAttributeComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UCAttributeComponent::InitializeComponent()
{
	Super::InitializeComponent();

}

ACCharacter* UCAttributeComponent::GetOwnerCharacter()
{
	return OwnerCharacter;
}

void UCAttributeComponent::SetOwnerCharacter(ACCharacter* InCharacter)
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
	ACCharacter* CCharacter = Cast<ACCharacter>(OwnerCharacter);
	CheckNull(CCharacter);
	InitialHP = CCharacter->GetCharacterAsset()->GetAttribute().HealthPoint;
}

void UCAttributeComponent::SetInitialManaPoint()
{
	ACCharacter* CCharacter = Cast<ACCharacter>(OwnerCharacter);
	CheckNull(CCharacter);
	InitialMP = CCharacter->GetCharacterAsset()->GetAttribute().ManaPoint;
}

void UCAttributeComponent::SetInitialSteminaPoint()
{
	ACCharacter* CCharacter = Cast<ACCharacter>(OwnerCharacter);
	CheckNull(CCharacter);
	InitialSP = CCharacter->GetCharacterAsset()->GetAttribute().SteminaPoint;
}

void UCAttributeComponent::SetInitialAttackPoint()
{
	ACCharacter* CCharacter = Cast<ACCharacter>(OwnerCharacter);
	CheckNull(CCharacter);
	InitialAP = CCharacter->GetCharacterAsset()->GetAttribute().AttackPoint;
}

void UCAttributeComponent::SetInitialDefensePoint()
{
	ACCharacter* CCharacter = Cast<ACCharacter>(OwnerCharacter);
	CheckNull(CCharacter);
	InitialDP = CCharacter->GetCharacterAsset()->GetAttribute().DefensePoint;
}

void UCAttributeComponent::SetMaxHealthPoint()
{
	MaxHP = InitialHP + (LV-1.f) * 10.f;
}

void UCAttributeComponent::SetMaxManaPoint()
{
	MaxMP = InitialMP + (LV-1.f) * 10.f;
}

void UCAttributeComponent::SetMaxSteminaPoint()
{
	MaxSP = InitialSP + (LV-1.f) * 40.f;
}

void UCAttributeComponent::SetMaxAttackPoint()
{
	MaxAP = InitialAP + (LV-1.f) * 4.f;
}

void UCAttributeComponent::SetMaxDefensePoint()
{
	MaxDP = InitialDP + (LV-1.f) * 4.f;
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

bool UCAttributeComponent::ChangeCurHP(float Change)
{
	CurHP += Change;

	CurHP = FMath::Clamp(CurHP, 0.f, MaxHP);

	if (CurHP == 0.f)
	{
		UCStateComponent* StateComp = OwnerCharacter->GetStateComp();
		StateComp->SetDeadMode();
	}

	return true;
}

bool UCAttributeComponent::ChangeCurMP(float Change)
{
	if (Change < 0 && CurMP < FMath::Abs(Change))
	{
		CLog::Print(TEXT("Can not Use Skill"));
		return false;
	}

	CurMP += Change;

	CurMP = FMath::Clamp(CurMP, 0.f, MaxMP);

	return true;
}

bool UCAttributeComponent::ChangeCurSP(float Change)
{
	if (Change < 0 && CurSP < FMath::Abs(Change))
	{
		CLog::Print(TEXT("Can not Use Skill"));
		return false;
	}

	CurSP += Change;

	CurSP = FMath::Clamp(CurSP, 0.f, MaxSP);

	return true;
}

bool UCAttributeComponent::ChangeCurAP(float Change)
{
	CurAP += Change;

	CurAP = FMath::Clamp(CurAP, 0.f, MaxAP);

	return true;
}

bool UCAttributeComponent::ChangeCurDP(float Change)
{
	CurDP += Change;

	CurDP = FMath::Clamp(CurDP, 0.f, MaxDP);

	return true;
}

