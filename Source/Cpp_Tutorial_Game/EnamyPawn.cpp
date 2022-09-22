// Mohamd Valizadeh


#include "EnamyPawn.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
AEnamyPawn::AEnamyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	

}

// Called when the game starts or when spawned
void AEnamyPawn::BeginPlay()
{
	Super::BeginPlay();

	PlayerPawn = UGameplayStatics::GetPlayerPawn(this,0);
	
}

// Called every frame
void AEnamyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector PlayerLocation = PlayerPawn->GetActorLocation();
	if(FVector::Dist(GetActorLocation(),PlayerLocation)<=MaxDistance)
	{
		LookAtTarget(PlayerLocation);
		if (FireTime>=FireRate)
		{
			Fire();
			FireTime = 0;
		}
	}
		FireTime +=DeltaTime;
	

}

// Called to bind functionality to input
void AEnamyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}



