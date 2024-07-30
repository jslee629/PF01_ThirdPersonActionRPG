#include "CEnemy.h"
#include "Global.h"
#include "Components/CapsuleComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Materials/MaterialInstanceConstant.h"

#include "CCharacterAsset.h"
#include "Components/CActionComponent.h"
#include "Components/CStateComponent.h"
#include "Components/CAttributeComponent.h"

ACEnemy::ACEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

	//Browse Asset
	CHelpers::GetAsset(&PlayerAsset, "/Game/DataAssets/DA_Mannequin");

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

	//-> Attribute
	AttributeComp->SetInitialHealthPoint();
	AttributeComp->SetInitialManaPoint();
	AttributeComp->SetInitialSteminaPoint();
	AttributeComp->SetInitialAttackPoint();
	AttributeComp->SetInitialDefensePoint();
}

void ACEnemy::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	//initialize Max Attribute
	AttributeComp->SetMaxHealthPoint();
	AttributeComp->SetMaxManaPoint();
	AttributeComp->SetMaxSteminaPoint();
	AttributeComp->SetMaxAttackPoint();
	AttributeComp->SetMaxDefensePoint();

	//Set Material Color
	UMaterialInstanceConstant* BodyMaterialAsset;
	UMaterialInstanceConstant* LogoMaterialAsset;
	CHelpers::GetAssetDynamic(&BodyMaterialAsset, "/Game/Characters/Mannequin/Materials/MI_UE4Man_Body_Inst");
	CHelpers::GetAssetDynamic(&LogoMaterialAsset, "/Game/Characters/Mannequin/Materials/MI_UE4Man_ChestLogo_Inst");
	BodyMaterial = UMaterialInstanceDynamic::Create(BodyMaterialAsset, this);
	LogoMaterial = UMaterialInstanceDynamic::Create(LogoMaterialAsset, this);
	BodyMaterial->SetVectorParameterValue("BodyColor", Color);
	LogoMaterial->SetVectorParameterValue("BaseColor", Color);
	GetMesh()->SetMaterial(0, BodyMaterial);
	GetMesh()->SetMaterial(1, LogoMaterial);
}

void ACEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	//Set Montages
	ActionComp->SetRollMontage();
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

void ACEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


