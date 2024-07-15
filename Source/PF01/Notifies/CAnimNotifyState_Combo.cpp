#include "CAnimNotifyState_Combo.h"
#include "Global.h"
#include "GameFramework/Character.h"

#include "Components/CActionComponent.h"

FString UCAnimNotifyState_Combo::GetNotifyName_Implementation() const
{
	return "Combo";
}

void UCAnimNotifyState_Combo::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);

	ACharacter* OwnerCharacter = Cast<ACharacter>(MeshComp->GetOwner());
	CheckNull(OwnerCharacter);

	UCActionComponent* ActionComp = CHelpers::GetComponent<UCActionComponent>(OwnerCharacter);
	CheckNull(ActionComp);

	ActionComp->SetCanCombo();
}

void UCAnimNotifyState_Combo::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);

	ACharacter* OwnerCharacter = Cast<ACharacter>(MeshComp->GetOwner());
	CheckNull(OwnerCharacter);

	UCActionComponent* ActionComp = CHelpers::GetComponent<UCActionComponent>(OwnerCharacter);
	CheckNull(ActionComp);

	ActionComp->SetCanNotCombo();
}
