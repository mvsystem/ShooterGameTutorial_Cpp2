// Mohamd Valizadeh

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "EnamyPawn.generated.h"

UCLASS()
class CPP_TUTORIAL_GAME_API AEnamyPawn : public APawnBase
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnamyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditAnywhere, Category="Tank")
	float MaxDistance = 1000;
	UPROPERTY(EditAnywhere, Category="Tank")
	float FireRate = 2.f;
	float FireTime = 0;
	AActor* PlayerPawn = nullptr;
};
