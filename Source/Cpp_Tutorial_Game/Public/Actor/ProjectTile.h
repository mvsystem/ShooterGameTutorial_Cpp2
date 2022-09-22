// Mohamd Valizadeh

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "ProjectTile.generated.h"

UCLASS()
class CPP_TUTORIAL_GAME_API AProjectTile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectTile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere,Category="Tank")
	UStaticMeshComponent* ProjectTileMesh;
	UPROPERTY(EditAnywhere,Category="Tank")
	class UProjectileMovementComponent* ProjectTileMovement;

	UPROPERTY(EditAnywhere,Category="Tank")
	float Damage = 20;
	UPROPERTY(EditAnywhere,Category="Tank")
	TSubclassOf<class  UDamageType>DamageType;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};
