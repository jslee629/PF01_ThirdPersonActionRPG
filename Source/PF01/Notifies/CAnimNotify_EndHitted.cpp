#include "CAnimNotify_EndHitted.h"
#include "Global.h"
#include "GameFramework/Character.h"

#include "Components/CStateComponent.h"

FString UCAnimNotify_EndHitted::GetNotifyName_Implementation() const
{
	return "EndHitted";
}

void UCAnimNotify_EndHitted::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);

	ACharacter* OwnerCharacter = Cast<ACharacter>(MeshComp->GetOwner());
	CheckNull(OwnerCharacter);

	UCStateComponent* StateComp = CHelpers::GetComponent<UCStateComponent>(OwnerCharacter);
	CheckNull(StateComp);

	StateComp->SetIdleMode();
}