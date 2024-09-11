#include "CAttributeComponent.h"
#include "Global.h"

#include "Character/CCharacter.h"

UCAttributeComponent::UCAttributeComponent()
{
	//Initialize variables
	LV = 1.f;
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
	InitialHP = CCharacter->GetCharacterAsset()->GetAttribute().ManaPoint;
}

void UCAttributeComponent::SetInitialSteminaPoint()
{
	ACCharacter* CCharacter = Cast<ACCharacter>(OwnerCharacter);
	CheckNull(CCharacter);
	InitialHP = CCharacter->GetCharacterAsset()->GetAttribute().SteminaPoint;
}

void UCAttributeComponent::SetInitialAttackPoint()
{
	ACCharacter* CCharacter = Cast<ACCharacter>(OwnerCharacter);
	CheckNull(CCharacter);
	InitialHP = CCharacter->GetCharacterAsset()->GetAttribute().AttackPoint;
}

void UCAttributeComponent::SetInitialDefensePoint()
{
	ACCharacter* CCharacter = Cast<ACCharacter>(OwnerCharacter);
	CheckNull(CCharacter);
	InitialHP = CCharacter->GetCharacterAsset()->GetAttribute().DefensePoint;
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

void UCAttributeComponent::ChangeCurHP(float Change)
{
	CurHP += Change;

	CurHP = FMath::Clamp(CurHP, 0.f, MaxHP);
}

void UCAttributeComponent::ChangeCurMP(float Change)
{
	CurMP += Change;

	CurMP = FMath::Clamp(CurMP, 0.f, MaxMP);
}

void UCAttributeComponent::ChangeCurSP(float Change)
{
	CurSP += Change;

	CurSP = FMath::Clamp(CurSP, 0.f, MaxSP);
}

void UCAttributeComponent::ChangeCurAP(float Change)
{
	CurAP += Change;

	CurAP = FMath::Clamp(CurAP, 0.f, MaxAP);
}

void UCAttributeComponent::ChangeCurDP(float Change)
{
	CurDP += Change;

	CurDP = FMath::Clamp(CurDP, 0.f, MaxDP);
}

