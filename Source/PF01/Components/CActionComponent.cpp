#include "CActionComponent.h"
#include "Global.h"
#include "GameFramework/Character.h"

#include "CStateComponent.h"
#include "Character/CPlayer.h"

UCActionComponent::UCActionComponent()
{
	//initialize variables
	bCanCombo = false;
	ComboCount = 0;

	//Save Owner
	OwnerCharacter = Cast<ACharacter>(GetOwner());
}

void UCActionComponent::BeginPlay()
{
	Super::BeginPlay();
	CheckNull(OwnerCharacter);

	//Set Montages
	SetRollMontage();
	SetSkill1Montages();
	SetSkill2Montages();
	SetSkill3Montages();
	SetSkill4Montages();

	//Default Attack Montage : Skill1
	SetSkill1ToAttack();
}

void UCActionComponent::Roll()
{
	OwnerCharacter->PlayAnimMontage(Roll_Montage.Montage, Roll_Montage.PlayRate, Roll_Montage.StartSection);
}

void UCActionComponent::Attack()
{
	if (ComboCount == 0 && Attack_Montages[0].Montage)
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
	Attack_Montages = Skill1_Montages;
}

void UCActionComponent::SetSkill2ToAttack()
{
	CheckFalse(Skill2_Montages.Num() > 0);
	Attack_Montages = Skill2_Montages;
}

void UCActionComponent::SetSkill3ToAttack()
{
	CheckFalse(Skill3_Montages.Num() > 0);
	Attack_Montages = Skill3_Montages;
}

void UCActionComponent::SetSkill4ToAttack()
{
	CheckFalse(Skill4_Montages.Num() > 0);
	Attack_Montages = Skill4_Montages;
}

void UCActionComponent::SetRollMontage()
{
	ACPlayer* Player = Cast<ACPlayer>(OwnerCharacter);
	if (Player)
	{
		Roll_Montage = Player->GetPlayerAsset()->GetRollMontage();
	}
}

void UCActionComponent::SetSkill1Montages()
{
	CheckNull(OwnerCharacter);
	ACPlayer* Player = Cast<ACPlayer>(OwnerCharacter);
	if (Player)
	{
		Skill1_Montages = Player->GetPlayerAsset()->GetSkill1Montages();
	}
}

void UCActionComponent::SetSkill2Montages()
{
	ACPlayer* Player = Cast<ACPlayer>(OwnerCharacter);
	if (Player)
	{
		Skill2_Montages = Player->GetPlayerAsset()->GetSkill2Montages();
	}
}

void UCActionComponent::SetSkill3Montages()
{
	ACPlayer* Player = Cast<ACPlayer>(OwnerCharacter);
	if (Player)
	{
		Skill3_Montages = Player->GetPlayerAsset()->GetSkill3Montages();
	}
}

void UCActionComponent::SetSkill4Montages()
{
	ACPlayer* Player = Cast<ACPlayer>(OwnerCharacter);
	if (Player)
	{
		Skill4_Montages = Player->GetPlayerAsset()->GetSkill4Montages();
	}
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
