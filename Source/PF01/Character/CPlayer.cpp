#include "CPlayer.h"
#include "Global.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

#include "CCharacterAsset.h"
#include "Components/CActionComponent.h"
#include "Components/CStateComponent.h"
#include "Components/CAttributeComponent.h"

ACPlayer::ACPlayer()
{
	//Browse Asset
	CHelpers::GetAsset(&CharacterAsset, "/Game/DataAssets/DA_Mannequin");

	//Create Scene Component
	CHelpers::CreateSceneComponent(this, &SpringArmComp, "SpringArmComp", GetMesh());
	CHelpers::CreateSceneComponent(this, &CameraComp, "CameraComp", SpringArmComp);

	//Create Actor Component
	CHelpers::CreateActorComponent(this, &ActionComp, "ActionComp");
	CHelpers::CreateActorComponent(this, &StateComp, "StateComp");
	CHelpers::CreateActorComponent(this, &AttributeComp, "AttributeComp");

	//Component Settings
	//-> MeshComp
	GetMesh()->SetRelativeLocation(FVector(0, 0, -88.f));
	GetMesh()->SetRelativeRotation(FRotator(0, -90.f, 0));

	USkeletalMesh* MeshAsset;
	CHelpers::GetAsset(&MeshAsset, "/Game/Characters/Mannequin/Mesh/SK_Mannequin");
	GetMesh()->SetSkeletalMesh(MeshAsset);

	//-> SpringArmComp
	SpringArmComp->SetRelativeLocation(FVector(0, 0, 140.f));
	SpringArmComp->SetRelativeRotation(FRotator(0, 90.f, 0));
	SpringArmComp->TargetArmLength = 200.0f;
	SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->bEnableCameraLag = true;

	//-> Movement
	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0, 720.f, 0);

	//-> Attribute
	AttributeComp->SetInitialHealthPoint();
	AttributeComp->SetInitialManaPoint();
	AttributeComp->SetInitialSteminaPoint();
	AttributeComp->SetInitialAttackPoint();
	AttributeComp->SetInitialDefensePoint();
}

void ACPlayer::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	//initialize Max Attribute
	AttributeComp->SetMaxHealthPoint();
	AttributeComp->SetMaxManaPoint();
	AttributeComp->SetMaxSteminaPoint();
	AttributeComp->SetMaxAttackPoint();
	AttributeComp->SetMaxDefensePoint();
}

void ACPlayer::BeginPlay()
{
	Super::BeginPlay();

	ActionComp->SetRollMontage();

	//Set Montages
	ActionComp->SetRollMontage();
	ActionComp->SetHittedMontage();
	ActionComp->SetSkill1Montages();
	ActionComp->SetSkill2Montages();
	ActionComp->SetSkill3Montages();
	ActionComp->SetSkill4Montages();

	//Default Attack Montage : Skill1
	ActionComp->SetSkill1ToAttack();

	//Set Attributes
	AttributeComp->InitializeCurHealth();
	AttributeComp->InitializeCurMana();
	AttributeComp->InitializeCurStemina();
	AttributeComp->InitializeCurAttack();
	AttributeComp->InitializeCurDefense();
}

void ACPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Axis Event Binding
	PlayerInputComponent->BindAxis("MoveForward", this, &ACPlayer::OnMoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACPlayer::OnMoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &ACPlayer::OnTurn);
	PlayerInputComponent->BindAxis("LookUp", this, &ACPlayer::OnLookUp); 

	// Action Event Binding
	PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ACPlayer::OnJump);
	PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAction("Roll", EInputEvent::IE_Pressed, this, &ACPlayer::OnRoll);
	PlayerInputComponent->BindAction("Attack", EInputEvent::IE_Pressed, this, &ACPlayer::OnAttack);

	PlayerInputComponent->BindAction("Skill1", EInputEvent::IE_Pressed, this, &ACPlayer::OnSkill1);
	PlayerInputComponent->BindAction("Skill2", EInputEvent::IE_Pressed, this, &ACPlayer::OnSkill2);
	PlayerInputComponent->BindAction("Skill3", EInputEvent::IE_Pressed, this, &ACPlayer::OnSkill3);
	PlayerInputComponent->BindAction("Skill4", EInputEvent::IE_Pressed, this, &ACPlayer::OnSkill4);
}

FGenericTeamId ACPlayer::GetGenericTeamId() const
{
	return FGenericTeamId(TeamId);
}

void ACPlayer::OnMoveForward(float AxisValue)
{
	FRotator ControlRotation = FRotator(0, GetControlRotation().Yaw, 0);
	FVector Direction = FQuat(ControlRotation).GetForwardVector();

	AddMovementInput(Direction, AxisValue);
}

void ACPlayer::OnMoveRight(float AxisValue)
{
	FRotator ControlRotation = FRotator(0, GetControlRotation().Yaw, 0);
	FVector Direction = FQuat(ControlRotation).GetRightVector();

	AddMovementInput(Direction, AxisValue);
}

void ACPlayer::OnTurn(float AxisValue)
{
	AddControllerYawInput(AxisValue);
}

void ACPlayer::OnLookUp(float AxisValue)
{
	AddControllerPitchInput(AxisValue);
}

void ACPlayer::OnJump()
{
	CheckTrue(StateComp->IsAttackMode());
	Jump();
}

void ACPlayer::OnRoll()
{
	CheckFalse(StateComp->IsIdleMode());
	StateComp->SetRollMode();
	ActionComp->Roll();
}

void ACPlayer::OnAttack_Implementation()
{
	CheckTrue(StateComp->IsRollMode());
	CheckTrue(GetCharacterMovement()->IsFalling());
	StateComp->SetAttackMode();
	ActionComp->Attack();
}

void ACPlayer::OnSkill1_Implementation()
{
	ActionComp->SetSkill1ToAttack();
}

void ACPlayer::OnSkill2_Implementation()
{
	ActionComp->SetSkill2ToAttack();
}

void ACPlayer::OnSkill3_Implementation()
{
	ActionComp->SetSkill3ToAttack();
}

void ACPlayer::OnSkill4_Implementation()
{
	ActionComp->SetSkill4ToAttack();
}
