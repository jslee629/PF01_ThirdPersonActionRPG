#include "CEnemy.h"
#include "Global.h"
#include "Components/CapsuleComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Materials/MaterialInstanceConstant.h"

#include "CCharacterAsset.h"
#include "Components/CActionComponent.h"
#include "Components/CStateComponent.h"
#include "Components/CAttributeComponent.h"
#include "Components/CCollisionComponent.h"
#include "Weapon/CProjectile.h"

ACEnemy::ACEnemy()
{
	//initialize variables
	Color = FLinearColor::Black;
	TeamId = 1;
	ActionRange = 150.f;
	EscapeRange = 0.f;
	DetectRange = 600.f;
	InvisibleRange = 1000.f;

	//Browse Asset
	CHelpers::GetAsset(&CharacterAsset, "/Game/DataAssets/DA_Mannequin");

	//Create Actor Component
	CHelpers::CreateActorComponent(this, &StateComp, "StateComp");
	CHelpers::CreateActorComponent(this, &ActionComp, "ActionComp");
	CHelpers::CreateActorComponent(this, &AttributeComp, "AttributeComp");
	CHelpers::CreateActorComponent(this, &CollisionComp, "CollisionComp");

	//Component Settings
	//-> MeshComp
	GetMesh()->SetRelativeLocation(FVector(0, 0, -88.f));
	GetMesh()->SetRelativeRotation(FRotator(0, -90.f, 0));

	USkeletalMesh* MeshAsset;
	CHelpers::GetAsset(&MeshAsset, "/Game/Characters/Mannequin/Mesh/SK_Mannequin");
	GetMesh()->SetSkeletalMesh(MeshAsset);
}

void ACEnemy::OnConstruction(const FTransform& Transform)
{
	//-> Material
	UMaterialInstanceConstant* BodyMaterialAsset;
	UMaterialInstanceConstant* LogoMaterialAsset;
	CHelpers::GetAssetDynamic(&BodyMaterialAsset, "/Game/Characters/Mannequin/Materials/MI_UE4Man_Body_Inst");
	CHelpers::GetAssetDynamic(&LogoMaterialAsset, "/Game/Characters/Mannequin/Materials/MI_UE4Man_ChestLogo_Inst");
	BodyMaterial = UMaterialInstanceDynamic::Create(BodyMaterialAsset, this);
	LogoMaterial = UMaterialInstanceDynamic::Create(LogoMaterialAsset, this);
	GetMesh()->SetMaterial(0, BodyMaterial);
	GetMesh()->SetMaterial(1, LogoMaterial);
	ChangeColor();
}

void ACEnemy::BeginPlay()
{
	Super::BeginPlay();

	StateComp->SetOwnerCharacter(this);
	ActionComp->SetOwnerCharacter(this);
	AttributeComp->SetOwnerCharacter(this);
	CollisionComp->SetOwnerCharacter(this);

	//Set Montages
	ActionComp->SetRollMontage();
	ActionComp->SetSkill1Montages();
	ActionComp->SetSkill2Montages();
	ActionComp->SetSkill3Montages();
	ActionComp->SetSkill4Montages();

	//Default Attack Montage : Skill1
	ActionComp->SetSkill1ToAttack();

	//intialize Initial Attributes
	AttributeComp->SetInitialHealthPoint();
	AttributeComp->SetInitialManaPoint();
	AttributeComp->SetInitialSteminaPoint();
	AttributeComp->SetInitialAttackPoint();
	AttributeComp->SetInitialDefensePoint();

	//intialize Max Attributes
	AttributeComp->SetMaxHealthPoint();
	AttributeComp->SetMaxManaPoint();
	AttributeComp->SetMaxSteminaPoint();
	AttributeComp->SetMaxAttackPoint();
	AttributeComp->SetMaxDefensePoint();

	//initialize Cur Attributes
	AttributeComp->InitializeCurHealth();
	AttributeComp->InitializeCurMana();
	AttributeComp->InitializeCurStemina();
	AttributeComp->InitializeCurAttack();
	AttributeComp->InitializeCurDefense();

	//bind call back function
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(CollisionComp, &UCCollisionComponent::OnColliderBeginOverlap);
}

void ACEnemy::ChangeColor()
{
	//Set Material Color
	BodyMaterial->SetVectorParameterValue("BodyColor", (FVector)Color);
	LogoMaterial->SetVectorParameterValue("BaseColor", (FVector)Color);
}

void ACEnemy::Damaged(AActor* CausedActor, float Damage, const FHitResult& HitResult)
{
	//Set State Hitted
	StateComp->SetHittedMode();

	//Play Hitted Montage
	ActionComp->Hitted();

	//Set Damage to Attribute
	AttributeComp->ChangeCurHP(Damage);

	CLog::Print(Damage);
}

void ACEnemy::SendDataToProjectile(AActor* OutProjectile)
{
	ACProjectile* Projectile = Cast<ACProjectile>(OutProjectile);
	if (ensure(Projectile))
	{
		Projectile->SetOwnerDamage(AttributeComp->GetCurAttackPoint());
		Projectile->SetDamageRate(ActionComp->GetAttackDamageRate());
	}
}

