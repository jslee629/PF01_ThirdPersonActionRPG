#include "CCharacterAsset.h"
#include "Global.h"

UCCharacterAsset::UCCharacterAsset()
{
	CHelpers::GetAsset(&RollMontage.Montage, "/Game/Characters/Mannequin/Animations/Common/Roll_Montage");

	Attribute.HealthPoint = 100.f;
	Attribute.AttackPoint = 40.f;
	Attribute.DefensePoint = 0.f;
}

FMontageAsset UCCharacterAsset::GetRollMontage() const
{
	return RollMontage;
}

TArray<FMontageAsset> UCCharacterAsset::GetSkill1Montages() const
{
	return Skill1Montages;
}

TArray<FMontageAsset> UCCharacterAsset::GetSkill2Montages() const
{
	return Skill2Montages;
}

TArray<FMontageAsset> UCCharacterAsset::GetSkill3Montages() const
{
	return Skill3Montages;
}

TArray<FMontageAsset> UCCharacterAsset::GetSkill4Montages() const
{
	return Skill4Montages;
}

FAttributeAsset UCCharacterAsset::GetAttribute() const
{
	return Attribute;
}
