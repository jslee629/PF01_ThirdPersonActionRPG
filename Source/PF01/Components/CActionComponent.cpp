#include "CActionComponent.h"
#include "Global.h"
#include "GameFramework/Character.h"

#include "Character/CPlayer.h"
#include "Character/CEnemy.h"

UCActionComponent::UCActionComponent()
{
	//initialize variables
	bCanCombo = false;
	ComboCount = 0;
}

void UCActionComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UCActionComponent::InitializeComponent()
{
	Super::InitializeComponent();

	SetOwnerCharacter(Cast<ACharacter>(GetOwner()));

	SetRollMontage();
	SetHittedMontage();
	SetSkill1Montages();
	SetSkill2Montages();
	SetSkill3Montages();
	SetSkill4Montages();
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
	if (ComboCount == 0 && Attack_Montages.Num() > 0)
	{
		OwnerCharacter->PlayAnimMontage(Attack_Montages[0].Montage, Attack_Montages[0].PlayRate, Attack_Montages[0].StartSection);
	}
	else
	{
		if (bCanCombo && Attack_Montages[ComboCount].Montage)
		{
			if (bCanCombo)
			{
				OwnerCharacter->PlayAnimMontage(Attack_Montages[ComboCount].Montage, Attack_Montages[ComboCount].PlayRate, Attack_Montages[ComboCount].StartSection);
			}
		}
	}
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
}

void UCActionComponent::InitializeComboCount()
{
	ComboCount = 0;
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

void UCActionComponent::SetOwnerCharacter(ACharacter* InCharacter)
{
	OwnerCharacter = InCharacter;
}


