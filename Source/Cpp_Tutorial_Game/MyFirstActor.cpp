// Mohamd Valizadeh


#include "MyFirstActor.h"

#include "Components/BoxComponent.h"

// Sets default values
AMyFirstActor::AMyFirstActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Meshcomponent= CreateDefaultSubobject<UStaticMeshComponent>(FName("statcMesh"));
	RootComponent=Meshcomponent;
	Boxx = CreateDefaultSubobject<UBoxComponent>(FName("BOX"));
	Boxx->SetupAttachment(Meshcomponent);
	

}

// Called when the game starts or when spawned
void AMyFirstActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyFirstActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

