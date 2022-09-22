// Mohamd Valizadeh


#include "Object_MV.h"

// Sets default values
AObject_MV::AObject_MV()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AObject_MV::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AObject_MV::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AObject_MV::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	if (this->Door)
	{
		this->Door->SetActorLocation(FVector(-90, -40, 300));
	}
}

void AObject_MV::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);
	if (this->Door)
	{
		this->Door->SetActorLocation(FVector(-90, -40, 105));
	}
}
