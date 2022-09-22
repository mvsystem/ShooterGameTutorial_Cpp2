// Mohamd Valizadeh


#include "PawnBase.h"

#include "Component/HealthComponent.h"
#include "Public/Actor/ProjectTile.h"

// Sets default values
APawnBase::APawnBase()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("TankBody"));
	RootComponent = BodyMesh;
	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("TankTurret"));
	TurretMesh->SetupAttachment(BodyMesh);
	BarrelMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("TankBarret"));
	BarrelMesh->SetupAttachment(TurretMesh);
	ProjecTileSpawnPoint = CreateDefaultSubobject<USceneComponent>(FName("ProjecTileSpawnPoint"));
	ProjecTileSpawnPoint->SetupAttachment(BarrelMesh);

	HelthComponent = CreateDefaultSubobject<UHealthComponent>(FName("HelthComponent"));
}

// Called when the game starts or when spawned
void APawnBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APawnBase::LookAtTarget(FVector TargetLocation)
{
	FVector TurretLocation = TurretMesh->GetComponentLocation();
	FVector TargetFixedLocation = FVector(TargetLocation.X, TargetLocation.Y, TurretLocation.Z);
	FRotator NewTurreRotation = FVector(TargetFixedLocation - TurretLocation).Rotation();

	FRotator SmoothRotation = FMath::Lerp(TurretMesh->GetComponentRotation(), NewTurreRotation,
	                                      TurretRotationSpeed * GetWorld()->GetDeltaSeconds());

	TurretMesh->SetWorldRotation(SmoothRotation);
}

void APawnBase::Fire()
{
	AProjectTile* TempProjectile = GetWorld()->SpawnActor<AProjectTile>(
		ProjectileClass, ProjecTileSpawnPoint->GetComponentTransform());
	TempProjectile->SetOwner(this);


	//GetWorld()->SpawnActor<AProjectTile>(AProjectTile::StaticClass(),ProjecTileSpawnPoint->GetComponentTransform());
}
