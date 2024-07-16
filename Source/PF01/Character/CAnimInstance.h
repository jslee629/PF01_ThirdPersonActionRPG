#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CAnimInstance.generated.h"

UCLASS()
class PF01_API UCAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "BlendSpace")
	float Speed;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "BlendSpace")
	float Direction;
	UPROPERTY(BlueprintReadOnly, Category = "Jump")
	bool bFalling;
};