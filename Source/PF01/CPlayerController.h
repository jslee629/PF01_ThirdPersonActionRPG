#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CPlayerController.generated.h"

UCLASS()
class PF01_API ACPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	void CreateMainHUDWidget();
};
