#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CCharacterInterface.generated.h"

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
	virtual void Escape() {};
};
