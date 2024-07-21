#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CCharacterAsset.h"
#include "CAttributeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PF01_API UCAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCAttributeComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetLVPoint() { return LV_Point; }
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetEXPPoint() { return EXP_Point; }
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetCurHealthPoint() { return CurHealthP; }
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetCurManaPoint() { return CurManaP; }
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetCurSteminaPoint() { return CurSteminaP; }
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetCurAttackPoint() { return CurAttackP; }
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetCurDefensePoint() { return CurDefenseP; }
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetMaxHealthPoint() { return MaxHealthP; }
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetMaxManaPoint() { return MaxManaP; }
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetMaxSteminaPoint() { return MaxSteminaP; }
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetMaxAttackPoint() { return MaxAttackP; }
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetMaxDefensePoint() { return MaxDefenseP; }

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

private:
	ACharacter* OwnerCharacter;

	float LV_Point;
	float EXP_Point;
	float CurHealthP;
	float MaxHealthP;
	float CurManaP;
	float MaxManaP;
	float CurSteminaP;
	float MaxSteminaP;
	float CurAttackP;
	float MaxAttackP;
	float CurDefenseP;
	float MaxDefenseP;

	UPROPERTY(EditDefaultsOnly, Category = "Initial Status")
	float HP;
	UPROPERTY(EditDefaultsOnly, Category = "Initial Status")
	float MP;
	UPROPERTY(EditDefaultsOnly, Category = "Initial Status")
	float SP;
	UPROPERTY(EditDefaultsOnly, Category = "Initial Status")
	float AP;
	UPROPERTY(EditDefaultsOnly, Category = "Initial Status")
	float DP;
};
