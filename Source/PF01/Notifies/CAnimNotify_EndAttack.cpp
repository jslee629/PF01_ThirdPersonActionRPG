#include "CAnimNotify_EndAttack.h"
#include "Global.h"
#include "GameFramework/Character.h"

#include "Components/CActionComponent.h"

FString UCAnimNotify_EndAttack::GetNotifyName_Implementation() const
{
	return "EndAttack";
}

void UCAnimNotify_EndAttack::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);

	ACharacter* OwnerCharacter = Cast<ACharacter>(MeshComp->GetOwner());
	CheckNull(OwnerCharacter);

	UCActionComponent* ActionComp = CHelpers::GetComponent<UCActionComponent>(OwnerCharacter);
	CheckNull(ActionComp);

	ActionComp->End_Attack();

}