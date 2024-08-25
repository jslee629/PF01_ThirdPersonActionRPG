#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interfaces/CActorComponentInterface.h"
#include "CStateComponent.h"
#include "CCharacterAsset.h"
#include "CActionComponent.generated.h"

class ACharacter;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PF01_API UCActionComponent : public UActorComponent, public ICActorComponentInterface
{
	GENERATED_BODY()

public:	
	UCActionComponent();

protected:
	virtual void BeginPlay() override;
	virtual void InitializeComponent() override;

public:
	void Roll();
	void Hitted();
	void Attack();

	UFUNCTION(BlueprintCallable)
	FORCEINLINE int32 GetComboCount() { return ComboCount; }

	FORCEINLINE float GetAttackDamageRate() { return Attack_DamageRate; }
	FORCEINLINE float GetAttackHealthCost() { return Attack_HealthCost; }
	FORCEINLINE float GetAttackManaCost() { return Attack_ManaCost; }

	void SetSkill1ToAttack();
	void SetSkill2ToAttack();
	void SetSkill3ToAttack();
	void SetSkill4ToAttack();

	void SetRollMontage();
	void SetHittedMontage();
	void SetSkill1Montages();
	void SetSkill2Montages();
	void SetSkill3Montages();
	void SetSkill4Montages();

	void Begin_Attack();		//for notify
	void End_Attack();			//for notify

	void SetCanCombo();
	void SetCanNotCombo();

	void IncreaseComboCount();
	void InitializeComboCount();

	void ChangeSkill(int32 Number);		//for AI

	//Inherited from ICActorComponentInterface
	virtual void SetOwnerCharacter(ACharacter* InCharacter) override;

private:
	ACharacter* OwnerCharacter;
	FMontageAsset Roll_Montage;
	FMontageAsset Hitted_Montage;
	TArray<FMontageAsset> Skill1_Montages;
	TArray<FMontageAsset> Skill2_Montages;
	TArray<FMontageAsset> Skill3_Montages;
	TArray<FMontageAsset> Skill4_Montages;
	TArray<FMontageAsset> Attack_Montages;

	float Attack_DamageRate;		// for Projectile
	float Attack_HealthCost;		// for Projectile
	float Attack_ManaCost;			// for Projectile

	bool bCanCombo;
	int32 ComboCount;
};
