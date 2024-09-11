#include "CActionComponent.h"
#include "Global.h"

#include "Character/CCharacter.h"
#include "CAttributeComponent.h"

UCActionComponent::UCActionComponent()
{
	//initialize variables
	bCanCombo = false;
	ComboCount = -1;
}

void UCActionComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UCActionComponent::InitializeComponent()
{
	Super::InitializeComponent();

}

void UCActionComponent::Roll()
{
	if (Roll_Montage.Montage)
	{
		OwnerCharacter->PlayAnimMontage(Roll_Montage.Montage, Roll_Montage.PlayRate, Roll_Montage.StartSection);
	}

	OwnerCharacter->GetAttributeComp()->ChangeCurHP(-Roll_Montage.HealthCost);
	OwnerCharacter->GetAttributeComp()->ChangeCurMP(-Roll_Montage.ManaCost);
	OwnerCharacter->GetAttributeComp()->ChangeCurSP(-Roll_Montage.SteminaCost);

	OwnerCharacter->GetAttributeComp()->OnHealthChanged.Broadcast(OwnerCharacter, -Roll_Montage.HealthCost);
	OwnerCharacter->GetAttributeComp()->OnManaChanged.Broadcast(OwnerCharacter, -Roll_Montage.ManaCost);
	OwnerCharacter->GetAttributeComp()->OnSteminaChanged.Broadcast(OwnerCharacter, -Roll_Montage.SteminaCost);
}

void UCActionComponent::Hitted()
{
	if (Hitted_Montage.Montage)
	{
		OwnerCharacter->PlayAnimMontage(Hitted_Montage.Montage, Hitted_Montage.PlayRate, Hitted_Montage.StartSection);
	}

	OwnerCharacter->GetAttributeComp()->ChangeCurHP(-Hitted_Montage.HealthCost);
	OwnerCharacter->GetAttributeComp()->ChangeCurMP(-Hitted_Montage.ManaCost);
	OwnerCharacter->GetAttributeComp()->ChangeCurSP(-Hitted_Montage.SteminaCost);

	OwnerCharacter->GetAttributeComp()->OnHealthChanged.Broadcast(OwnerCharacter, -Roll_Montage.HealthCost);
	OwnerCharacter->GetAttributeComp()->OnManaChanged.Broadcast(OwnerCharacter, -Roll_Montage.ManaCost);
	OwnerCharacter->GetAttributeComp()->OnSteminaChanged.Broadcast(OwnerCharacter, -Roll_Montage.SteminaCost);
}

void UCActionComponent::Attack()
{
	if (ComboCount == -1 && Attack_Montages.Num() > 0)
	{
		OwnerCharacter->PlayAnimMontage(Attack_Montages[0].Montage, Attack_Montages[0].PlayRate, Attack_Montages[0].StartSection);

	}
	else if(Attack_Montages[ComboCount].Montage)
	{
		if (bCanCombo)
		{
			OwnerCharacter->PlayAnimMontage(Attack_Montages[ComboCount].Montage, Attack_Montages[ComboCount].PlayRate, Attack_Montages[ComboCount].StartSection);
		}
	}

	OwnerCharacter->GetAttributeComp()->ChangeCurHP(-GetAttackHealthCost());
	OwnerCharacter->GetAttributeComp()->ChangeCurMP(-GetAttackManaCost());
	OwnerCharacter->GetAttributeComp()->ChangeCurSP(-GetAttackSteminaCost());

	OwnerCharacter->GetAttributeComp()->OnHealthChanged.Broadcast(OwnerCharacter, -Roll_Montage.HealthCost);
	OwnerCharacter->GetAttributeComp()->OnManaChanged.Broadcast(OwnerCharacter, -Roll_Montage.ManaCost);
	OwnerCharacter->GetAttributeComp()->OnSteminaChanged.Broadcast(OwnerCharacter, -Roll_Montage.SteminaCost);
}

ACCharacter* UCActionComponent::GetOwnerCharacter()
{
	return OwnerCharacter;
}

void UCActionComponent::SetOwnerCharacter(ACCharacter* InCharacter)
{
	OwnerCharacter = InCharacter;
}

float UCActionComponent::GetAttackDamageRate()
{
	return ComboCount > -1 ? Attack_Montages[ComboCount].DamageRate : Attack_Montages[0].DamageRate;
}

float UCActionComponent::GetAttackHealthCost()
{
	return ComboCount > -1 ? Attack_Montages[ComboCount].HealthCost : Attack_Montages[0].HealthCost;
}

float UCActionComponent::GetAttackManaCost()
{
	return ComboCount > -1 ? Attack_Montages[ComboCount].ManaCost : Attack_Montages[0].ManaCost;
}

float UCActionComponent::GetAttackSteminaCost()
{
	return ComboCount > -1 ? Attack_Montages[ComboCount].SteminaCost : Attack_Montages[0].SteminaCost;
}

void UCActionComponent::SetSkill1ToAttack()
{
	CheckFalse(Skill1_Montages.Num() > 0);
	if (Skill1_Montages.Num() > 0)
	{
		Attack_Montages = Skill1_Montages;
	}
}

void UCActionComponent::SetSkill2ToAttack()
{
	CheckFalse(Skill2_Montages.Num() > 0);
	if (Skill2_Montages.Num() > 0)
	{
		Attack_Montages = Skill2_Montages;
	}
}

void UCActionComponent::SetSkill3ToAttack()
{
	CheckFalse(Skill3_Montages.Num() > 0);
	if (Skill3_Montages.Num() > 0)
	{
		Attack_Montages = Skill3_Montages;
	}
}

void UCActionComponent::SetSkill4ToAttack()
{
	CheckFalse(Skill4_Montages.Num() > 0);
	if (Skill4_Montages.Num() > 0)
	{
		Attack_Montages = Skill4_Montages;
	}
}

void UCActionComponent::SetRollMontage()
{
	ACCharacter* CCharacter = Cast<ACCharacter>(OwnerCharacter);
	CheckNull(CCharacter);
	Roll_Montage = CCharacter->GetCharacterAsset()->GetRollMontage();
}

void UCActionComponent::SetHittedMontage()
{
	ACCharacter* CCharacter = Cast<ACCharacter>(OwnerCharacter);
	CheckNull(CCharacter);
	Hitted_Montage = CCharacter->GetCharacterAsset()->GetHittedMontage();
}

void UCActionComponent::SetSkill1Montages()
{
	ACCharacter* CCharacter = Cast<ACCharacter>(OwnerCharacter);
	CheckNull(CCharacter);
	Skill1_Montages = CCharacter->GetCharacterAsset()->GetSkill1Montages();
}

void UCActionComponent::SetSkill2Montages()
{
	ACCharacter* CCharacter = Cast<ACCharacter>(OwnerCharacter);
	CheckNull(CCharacter);
	Skill2_Montages = CCharacter->GetCharacterAsset()->GetSkill2Montages();
}

void UCActionComponent::SetSkill3Montages()
{
	ACCharacter* CCharacter = Cast<ACCharacter>(OwnerCharacter);
	CheckNull(CCharacter);
	Skill3_Montages = CCharacter->GetCharacterAsset()->GetSkill3Montages();
}

void UCActionComponent::SetSkill4Montages()
{
	ACCharacter* CCharacter = Cast<ACCharacter>(OwnerCharacter);
	CheckNull(CCharacter);
	Skill4_Montages = CCharacter->GetCharacterAsset()->GetSkill4Montages();
}

void UCActionComponent::Begin_Attack()
{
	IncreaseComboCount();
}

void UCActionComponent::End_Attack()
{
	UCStateComponent* StateComp = CHelpers::GetComponent<UCStateComponent>(OwnerCharacter);
	CheckNull(StateComp);

	StateComp->SetIdleMode();

	InitializeComboCount();
}

void UCActionComponent::SetCanCombo()
{
	bCanCombo = true;
}

void UCActionComponent::SetCanNotCombo()
{
	bCanCombo = false;
}

void UCActionComponent::IncreaseComboCount()
{
	ComboCount++;
	ComboCount = FMath::Clamp(ComboCount, -1, 2);
}

void UCActionComponent::InitializeComboCount()
{
	ComboCount = -1;
}

void UCActionComponent::ChangeSkill(int32 Number)
{
	switch (Number)
	{
	case 0:
		SetSkill1ToAttack();
		break;
	case 1:
		SetSkill2ToAttack();
		break;
	case 2:
		SetSkill3ToAttack();
		break;
	case 3:
		SetSkill4ToAttack();
		break;
	default:
		SetSkill1ToAttack();
		break;
	}
}


