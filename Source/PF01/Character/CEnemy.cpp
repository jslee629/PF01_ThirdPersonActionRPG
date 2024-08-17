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

	//initialize variables
	Color = FLinearColor::Black;
	TeamId = 1;
	ActionRange = 150.f;

	//Browse Asset
	CHelpers::GetAsset(&CharacterAsset, "/Game/DataAssets/DA_Mannequin");

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

	//Set Montages
	ActionComp->SetRollMontage();
	ActionComp->SetSkill1Montages();
	ActionComp->SetSkill2Montages();
	ActionComp->SetSkill3Montages();
	ActionComp->SetSkill4Montages();

	//Default Attack Montage : Skill1
	ActionComp->SetSkill1ToAttack();

	//initialize Max Attributes
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
}

void ACEnemy::ChangeColor()
{
	//Set Material Color
	BodyMaterial->SetVectorParameterValue("BodyColor", (FVector)Color);
	LogoMaterial->SetVectorParameterValue("BaseColor", (FVector)Color);
}



