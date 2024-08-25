#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CCharacterInterface.generated.h"

class UCCharacterAsset;

UINTERFACE(MinimalAPI)
class UCCharacterInterface : public UInterface
{
	GENERATED_BODY()
};

class PF01_API ICCharacterInterface
{
	GENERATED_BODY()

public:
	virtual void ChangeColor() {};
	virtual void Damaged(AActor* CausedActor, float Damage, const FHitResult& HitResult) = 0;
	virtual void SendDataToProjectile(AActor* OutProjectile) = 0;
};
