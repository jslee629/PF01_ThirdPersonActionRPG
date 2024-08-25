#include "CCollisionComponent.h"
#include "Global.h"
#include "GameFramework/Character.h"

#include "Interfaces/CCharacterInterface.h"
#include "Weapon/CProjectile.h"

UCCollisionComponent::UCCollisionComponent()
{

}

void UCCollisionComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UCCollisionComponent::InitializeComponent()
{
	Super::InitializeComponent();

	SetOwnerCharacter(Cast<ACharacter>(GetOwner()));
}

void UCCollisionComponent::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	TArray<FName> Tags = OtherComp->ComponentTags;
	if (Tags.IsValidIndex(0))
	{
		float FinalDamage = 0.f;

		ICCharacterInterface* ICharacter = Cast<ICCharacterInterface>(OverlappedComp->GetOwner());
		CheckNull(ICharacter);

		if (Tags[0] == TEXT("Projectile"))
		{
			ACProjectile* Projectile = Cast<ACProjectile>(OtherActor);
			CheckNull(Projectile);

			float BaseDamage = Projectile->GetBaseDamage();
			float OwnerDamage = Projectile->GetOwnerDamage();
			float DamageRate = Projectile->GetDamageRate();

			FinalDamage -= BaseDamage + OwnerDamage * DamageRate;
		}
		else if (Tags[0] == TEXT("Melee"))
		{
			FinalDamage = CalculateMeleeDamage(OtherActor, OtherComp);
		}

		ICharacter->Damaged(OtherActor, FinalDamage, SweepResult);
	}
}

void UCCollisionComponent::SetOwnerCharacter(ACharacter* InCharacter)
{
	OwnerCharacter = InCharacter;
}

float UCCollisionComponent::CalculateProjectileDamage(AActor* OtherActor, UPrimitiveComponent* OtherComp)
{
	float Damage = 0.f;

	ACProjectile* Projectile = Cast<ACProjectile>(OtherActor);
	CheckNullResult(Projectile, Damage);

	float BaseDamage = Projectile->GetBaseDamage();
	float OwnerDamage = Projectile->GetOwnerDamage();
	float DamageRate = Projectile->GetDamageRate();

	Damage -= BaseDamage + OwnerDamage * DamageRate;

	return Damage;
}

float UCCollisionComponent::CalculateMeleeDamage(AActor* OtherActor, UPrimitiveComponent* OtherComp)
{
	float Damage = 0.f;

	return Damage;
}
