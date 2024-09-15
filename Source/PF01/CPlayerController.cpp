#include "CPlayerController.h"
#include "Global.h"
#include "Blueprint/UserWidget.h"

void ACPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	CreateMainHUDWidget();
}

void ACPlayerController::OnUnPossess()
{
	Super::OnUnPossess();
}

void ACPlayerController::CreateMainHUDWidget()
{
	MainHUDWidget = CreateWidget(this, MainHUDWidgetClass);
	MainHUDWidget->AddToViewport();
}

void ACPlayerController::CreateMainMenuWidget()
{
	MainMenuWidget = CreateWidget(this, MainMenuWidgetClass);
	MainMenuWidget->AddToViewport();
}
