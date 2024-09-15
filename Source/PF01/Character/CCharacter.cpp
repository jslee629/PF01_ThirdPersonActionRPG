#include "CCharacter.h"
#include "Global.h"

#include "CCharacterAsset.h"
#include "Components/CActionComponent.h"
#include "Components/CAttributeComponent.h"
#include "Components/CCollisionComponent.h"
#include "Components/CStateComponent.h"

ACCharacter::ACCharacter()
{
	//Browse Asset
	CHelpers::GetAsset(&CharacterAsset, "/Game/DataAssets/DA_Mannequin");

	//Create Actor Component
	CHelpers::CreateActorComponent(this, &ActionComp, "ActionComp");
	CHelpers::CreateActorComponent(this, &StateComp, "StateComp");
	CHelpers::CreateActorComponent(this, &AttributeComp, "AttributeComp");
	CHelpers::CreateActorComponent(this, &CollisionComp, "CollisionComp");
}

void ACCharacter::BeginPlay()
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

	//Default Attack Skill
	ActionComp->SetSkill1ToAttack();
	//ActionComp->SetSkill2ToAttack();
	//ActionComp->SetSkill3ToAttack();
	//ActionComp->SetSkill4ToAttack();

	//Initialize Initial Attributes
	AttributeComp->SetInitialHealthPoint();
	AttributeComp->SetInitialManaPoint();
	AttributeComp->SetInitialSteminaPoint();
	AttributeComp->SetInitialAttackPoint();
	AttributeComp->SetInitialDefensePoint();

	//Initialize Max Attributes
	AttributeComp->SetMaxHealthPoint();
	AttributeComp->SetMaxManaPoint();
	AttributeComp->SetMaxSteminaPoint();
	AttributeComp->SetMaxAttackPoint();
	AttributeComp->SetMaxDefensePoint();

	//Initialize Cur Attributes
	AttributeComp->InitializeCurHealth();
	AttributeComp->InitializeCurMana();
	AttributeComp->InitializeCurStemina();
	AttributeComp->InitializeCurAttack();
	AttributeComp->InitializeCurDefense();
}

