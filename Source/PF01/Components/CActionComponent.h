#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CCharacterAsset.h"
#include "CActionComponent.generated.h"

class ACharacter;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PF01_API UCActionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCActionComponent();

protected:
	virtual void BeginPlay() override;

public:
	void Roll();
	void Attack();

	void SetSkill1ToAttack();
	void SetSkill2ToAttack();
	void SetSkill3ToAttack();
	void SetSkill4ToAttack();

	void SetRollMontage();
	void SetSkill1Montages();
	void SetSkill2Montages();
	void SetSkill3Montages();
	void SetSkill4Montages();

	void SetCanCombo();
	void SetCanNotCombo();

	void IncreaseComboCount();
	void InitializeComboCount();

private:
	ACharacter* OwnerCharacter;
	FMontageAsset Roll_Montage;
	TArray<FMontageAsset> Skill1_Montages;
	TArray<FMontageAsset> Skill2_Montages;
	TArray<FMontageAsset> Skill3_Montages;
	TArray<FMontageAsset> Skill4_Montages;
	TArray<FMontageAsset> Attack_Montages;
	bool bCanCombo;
	int32 ComboCount;
};
