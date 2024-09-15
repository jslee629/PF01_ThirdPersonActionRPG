#include "CEnemy.h"
#include "Global.h"
#include "Components/CapsuleComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Materials/MaterialInstanceConstant.h"

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
	StateComp->SetHittedMode();

	AttributeComp->ChangeCurHP(-Damage);

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

