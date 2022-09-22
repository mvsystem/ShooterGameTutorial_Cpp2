// Mohamd Valizadeh


#include "Cpp_Tutorial_Game/Public/Actor/ProjectTile.h"



#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AProjectTile::AProjectTile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectTileMesh=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectTileMesh"));
	RootComponent = ProjectTileMesh;
	
	ProjectTileMesh->OnComponentHit.AddDynamic(this,&AProjectTile::OnHit);
	
	ProjectTileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectTileMovement"));
}

// Called when the game starts or when spawned
void AProjectTile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

}

void AProjectTile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp,Warning,TEXT("Barkhord"));

	UGameplayStatics::ApplyDamage(OtherActor,Damage,GetOwner()->GetInstigatorController(),this,DamageType);

	Destroy();
}

