#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Character/CCharacter.h"
#include "CActorComponentInterface.generated.h"

class ACharacter;

UINTERFACE(MinimalAPI)
class UCActorComponentInterface : public UInterface
{
	GENERATED_BODY()
};

class PF01_API ICActorComponentInterface
{
	GENERATED_BODY()

public:
	virtual void SetOwnerCharacter(ACCharacter* InCharacter) = 0;
};
