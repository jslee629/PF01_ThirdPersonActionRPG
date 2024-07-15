#include "CAnimNotify_EndRoll.h"
#include "Global.h"
#include "GameFramework/Character.h"

#include "Components/CStateComponent.h"

FString UCAnimNotify_EndRoll::GetNotifyName_Implementation() const
{
	return "EndRoll";
}

void UCAnimNotify_EndRoll::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);

	ACharacter* OwnerCharacter = Cast<ACharacter>(MeshComp->GetOwner());
	CheckNull(OwnerCharacter);

	UCStateComponent* StateComp = CHelpers::GetComponent<UCStateComponent>(OwnerCharacter);
	CheckNull(StateComp);

	StateComp->SetIdleMode();
}
