// Mohamd Valizadeh


#include "Component/HealthComponent.h"

#include "Cpp_Tutorial_Game/Pawn/Tank.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentHelth = defaultHeith;

	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakDamage);

	// ...
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::TakDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
                                 AController* Instigator, AActor* DamageCouser)
{
	if (Damage <= 0 || IsDead) return;
	UE_LOG(LogTemp, Warning, TEXT("DamageApplide"));
	CurrentHelth -= Damage;

	if (ATank* Player = Cast<ATank>(GetOwner()))
	{
		Player->onHealthChanged.Broadcast(CurrentHelth);
	}

	if (CurrentHelth <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Dead"));
		IsDead = true;

		UGameplayStatics::PlaySoundAtLocation(this, ExplosionSound, GetOwner()->GetActorLocation(),
		                                      GetOwner()->GetActorRotation());
		UGameplayStatics::SpawnEmitterAtLocation(this, ExplosionEffect, GetOwner()->GetActorLocation());
		/*if (ATank* player = Cast<ATank>(GetOwner()))
		{
			GetWorld()->GetFirstPlayerController()->StartSpectatingOnly();
		}*/
		GetOwner()->Destroy();
	}
}
