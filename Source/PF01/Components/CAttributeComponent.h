#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interfaces/CActorComponentInterface.h"
#include "CCharacterAsset.h"
#include "CAttributeComponent.generated.h"

class ACharacter;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PF01_API UCAttributeComponent : public UActorComponent, public ICActorComponentInterface
{
	GENERATED_BODY()

public:	
	UCAttributeComponent();

protected:
	virtual void BeginPlay() override;
	virtual void InitializeComponent() override;

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetLVPoint() { return LV; }
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetEXPPoint() { return EXP; }
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetCurHealthPoint() { return CurHP; }
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetCurManaPoint() { return CurMP; }
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetCurSteminaPoint() { return CurSP; }
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetCurAttackPoint() { return CurAP; }
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetCurDefensePoint() { return CurDP; }
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetMaxHealthPoint() { return MaxHP; }
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetMaxManaPoint() { return MaxMP; }
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetMaxSteminaPoint() { return MaxSP; }
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetMaxAttackPoint() { return MaxAP; }
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetMaxDefensePoint() { return MaxDP; }

	//for level up
	void LevelUp();

	void SetInitialHealthPoint();
	void SetInitialManaPoint();
	void SetInitialSteminaPoint();
	void SetInitialAttackPoint();
	void SetInitialDefensePoint();

	void SetMaxHealthPoint();
	void SetMaxManaPoint();
	void SetMaxSteminaPoint();
	void SetMaxAttackPoint();
	void SetMaxDefensePoint();

	void InitializeCurHealth();
	void InitializeCurMana();
	void InitializeCurStemina();
	void InitializeCurAttack();
	void InitializeCurDefense();

	//for change HP, MP, SP, AP, DP
	void ChangeCurHP(float Change);
	void ChangeCurMP(float Change);
	void ChangeCurSP(float Change);
	void ChangeCurAP(float Change);
	void ChangeCurDP(float Change);

	//Inherited from ICActorComponentInterface
	virtual void SetOwnerCharacter(ACharacter* InCharacter) override;

private:
	ACharacter* OwnerCharacter;

	float LV;
	float EXP;
	float CurHP;
	float MaxHP;
	float CurMP;
	float MaxMP;
	float CurSP;
	float MaxSP;
	float CurAP;
	float MaxAP;
	float CurDP;
	float MaxDP;

	UPROPERTY(EditDefaultsOnly, Category = "Initial Status")
	float InitialHP;
	UPROPERTY(EditDefaultsOnly, Category = "Initial Status")
	float InitialMP;
	UPROPERTY(EditDefaultsOnly, Category = "Initial Status")
	float InitialSP;
	UPROPERTY(EditDefaultsOnly, Category = "Initial Status")
	float InitialAP;
	UPROPERTY(EditDefaultsOnly, Category = "Initial Status")
	float InitialDP;
};
