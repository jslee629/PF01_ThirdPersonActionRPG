#include "CActionComponent.h"
#include "Global.h"
#include "GameFramework/Character.h"

#include "Character/CPlayer.h"
#include "Character/CEnemy.h"

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
}

void UCActionComponent::Hitted()
{
	if (Hitted_Montage.Montage)
	{
		OwnerCharacter->PlayAnimMontage(Hitted_Montage.Montage, Hitted_Montage.PlayRate, Hitted_Montage.StartSection);
	}
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
			//CLog::Print(ComboCount, -1, 10.f, FColor::Red);
		}
	}
}

ACharacter* UCActionComponent::GetOwnerCharacter()
{
	return OwnerCharacter;
}

void UCActionComponent::SetOwnerCharacter(ACharacter* InCharacter)
{
	OwnerCharacter = InCharacter;
}

float UCActionComponent::GetAttackDamageRate()
{
	return ComboCount > -1 ? Attack_Montages[ComboCount].DamageRate : 0.f;
}

float UCActionComponent::GetAttackHealthCost()
{
	return ComboCount > -1 ? Attack_Montages[ComboCount].HealthCost : 0.f;
}

float UCActionComponent::GetAttackManaCost()
{
	return ComboCount > -1 ? Attack_Montages[ComboCount].ManaCost : 0.f;
}

float UCActionComponent::GetAttackSteminaCost()
{
	return ComboCount > -1 ? Attack_Montages[ComboCount].SteminaCost : 0.f;
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
	if (Cast<ACPlayer>(OwnerCharacter))
	{
		ACPlayer* Player = Cast<ACPlayer>(OwnerCharacter);
		Roll_Montage = Player->GetCharacterAsset()->GetRollMontage();
	}
	else if (Cast<ACEnemy>(OwnerCharacter))
	{
		ACEnemy* Enemy = Cast<ACEnemy>(OwnerCharacter);
		Roll_Montage = Enemy->GetCharacterAsset()->GetRollMontage();
	}
}

void UCActionComponent::SetHittedMontage()
{
	if (Cast<ACPlayer>(OwnerCharacter))
	{
		ACPlayer* Player = Cast<ACPlayer>(OwnerCharacter);
		Hitted_Montage = Player->GetCharacterAsset()->GetHittedMontage();
	}
	else if (Cast<ACEnemy>(OwnerCharacter))
	{
		ACEnemy* Enemy = Cast<ACEnemy>(OwnerCharacter);
		Hitted_Montage = Enemy->GetCharacterAsset()->GetHittedMontage();
	}
}

void UCActionComponent::SetSkill1Montages()
{
	if (Cast<ACPlayer>(OwnerCharacter))
	{
		ACPlayer* Player = Cast<ACPlayer>(OwnerCharacter);
		Skill1_Montages = Player->GetCharacterAsset()->GetSkill1Montages();
	}
	else if (Cast<ACEnemy>(OwnerCharacter))
	{
		ACEnemy* Enemy = Cast<ACEnemy>(OwnerCharacter);
		Skill1_Montages = Enemy->GetCharacterAsset()->GetSkill1Montages();
	}
}

void UCActionComponent::SetSkill2Montages()
{
	if (Cast<ACPlayer>(OwnerCharacter))
	{
		ACPlayer* Player = Cast<ACPlayer>(OwnerCharacter);
		Skill2_Montages = Player->GetCharacterAsset()->GetSkill2Montages();
	}
	else if (Cast<ACEnemy>(OwnerCharacter))
	{
		ACEnemy* Enemy = Cast<ACEnemy>(OwnerCharacter);
		Skill2_Montages = Enemy->GetCharacterAsset()->GetSkill2Montages();
	}
}

void UCActionComponent::SetSkill3Montages()
{
	if (Cast<ACPlayer>(OwnerCharacter))
	{
		ACPlayer* Player = Cast<ACPlayer>(OwnerCharacter);
		Skill3_Montages = Player->GetCharacterAsset()->GetSkill3Montages();
	}
	else if (Cast<ACEnemy>(OwnerCharacter))
	{
		ACEnemy* Enemy = Cast<ACEnemy>(OwnerCharacter);
		Skill3_Montages = Enemy->GetCharacterAsset()->GetSkill3Montages();
	}
}

void UCActionComponent::SetSkill4Montages()
{
	if (Cast<ACPlayer>(OwnerCharacter))
	{
		ACPlayer* Player = Cast<ACPlayer>(OwnerCharacter);
		Skill4_Montages = Player->GetCharacterAsset()->GetSkill4Montages();
	}
	else if (Cast<ACEnemy>(OwnerCharacter))
	{
		ACEnemy* Enemy = Cast<ACEnemy>(OwnerCharacter);
		Skill4_Montages = Enemy->GetCharacterAsset()->GetSkill4Montages();
	}
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


