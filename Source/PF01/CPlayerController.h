#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CPlayerController.generated.h"

class UUserWidget;

UCLASS()
class PF01_API ACPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void OnPossess(APawn* aPawn) override;
	virtual void OnUnPossess() override;
};
