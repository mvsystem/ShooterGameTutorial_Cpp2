// Mohamd Valizadeh


#include "C++Doreh/MyActor.h"

#include "Math/TransformCalculus3D.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	moh = Door->GetActorLocation();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	if (Door!=nullptr)
	{
		Door->SetActorLocation(FVector(0,0,200));
	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("khali%s"),TEXT("xxx"));
	}
	
}

void AMyActor::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);
Door->SetActorLocation(moh);
	
	
}

