#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CCharacterAsset.generated.h"

class UAnimMontage;
class UTexture2D;

USTRUCT(BlueprintType)
struct FMontageAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	UAnimMontage* Montage;
	UPROPERTY(EditDefaultsOnly)
	float PlayRate = 1.f;
	UPROPERTY(EditDefaultsOnly)
	FName StartSection;
	UPROPERTY(EditDefaultsOnly)
	UTexture2D* Image;
};

USTRUCT(BlueprintType)
struct FAttributeAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	float HealthPoint;
	UPROPERTY(EditDefaultsOnly)
	float AttackPoint;
	UPROPERTY(EditDefaultsOnly)
	float DefensePoint;
};

UCLASS()
class PF01_API UCCharacterAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UCCharacterAsset();

	FMontageAsset GetRollMontage() const;
	TArray<FMontageAsset> GetSkill1Montages() const;
	TArray<FMontageAsset> GetSkill2Montages() const;
	TArray<FMontageAsset> GetSkill3Montages() const;
	TArray<FMontageAsset> GetSkill4Montages() const;
	FAttributeAsset GetAttribute() const;

protected:
	UPROPERTY(EditDefaultsOnly)
	FMontageAsset RollMontage;
	UPROPERTY(EditDefaultsOnly)
	TArray<FMontageAsset> Skill1Montages;
	UPROPERTY(EditDefaultsOnly)
	TArray<FMontageAsset> Skill2Montages;
	UPROPERTY(EditDefaultsOnly)
	TArray<FMontageAsset> Skill3Montages;
	UPROPERTY(EditDefaultsOnly)
	TArray<FMontageAsset> Skill4Montages;
	UPROPERTY(EditDefaultsOnly)
	FAttributeAsset Attribute;
};
