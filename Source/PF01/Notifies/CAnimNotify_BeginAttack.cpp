#include "CAnimNotify_BeginAttack.h"
#include "Global.h"
#include "GameFramework/Character.h"

#include "Components/CActionComponent.h"

FString UCAnimNotify_BeginAttack::GetNotifyName_Implementation() const
{
	return "BeginAttack";
}

void UCAnimNotify_BeginAttack::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);

	ACharacter* OwnerCharacter = Cast<ACharacter>(MeshComp->GetOwner());
	CheckNull(OwnerCharacter);

	UCActionComponent* ActionComp = CHelpers::GetComponent<UCActionComponent>(OwnerCharacter);
	CheckNull(ActionComp);

	ActionComp->IncreaseComboCount();
}