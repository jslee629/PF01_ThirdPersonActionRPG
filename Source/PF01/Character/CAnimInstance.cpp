#include "CAnimInstance.h"
#include "Global.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void UCAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	CheckNull(TryGetPawnOwner());
}

void UCAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	ACharacter* Character = Cast<ACharacter>(TryGetPawnOwner());
	CheckNull(Character);

	Speed = Character->GetVelocity().Size2D();
	Direction = CalculateDirection(Character->GetVelocity(), Character->GetControlRotation());
	bFalling = Character->GetCharacterMovement()->IsFalling();
}