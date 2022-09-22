// Mohamd Valizadeh

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

UCLASS()
class CPP_TUTORIAL_GAME_API APawnBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	void LookAtTarget(FVector TargetLocation);

	void Fire();
	UPROPERTY(EditAnywhere, Category="Tank")
	UStaticMeshComponent* BodyMesh;
	UPROPERTY(EditAnywhere, Category="Tank")
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(EditAnywhere, Category="Tank")
	UStaticMeshComponent* BarrelMesh;
	UPROPERTY(EditAnywhere, Category="Tank")
	USceneComponent* ProjecTileSpawnPoint;

	UPROPERTY(EditAnywhere, Category="Tank")
	class UHealthComponent* HelthComponent;

	UPROPERTY(EditAnywhere,Category = "Tank")
	TSubclassOf<class AProjectTile>ProjectileClass;
	
	UPROPERTY(EditAnywhere, Category="Tank")
	float TurretRotationSpeed = 2;

	
};
