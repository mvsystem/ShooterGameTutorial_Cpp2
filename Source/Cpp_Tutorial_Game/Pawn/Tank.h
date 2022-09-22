// Mohamd Valizadeh

#pragma once

#include "CoreMinimal.h"
#include "Cpp_Tutorial_Game/PawnBase.h"
#include "Tank.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged,float,Health);
UCLASS()
class CPP_TUTORIAL_GAME_API ATank : public APawnBase
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	
	UPROPERTY(BlueprintAssignable)
	FOnHealthChanged onHealthChanged;

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
	class USpringArmComponent* SpringArm;
	UPROPERTY(EditAnywhere, Category="Tank")
	class UCameraComponent* Camera;
	UPROPERTY(EditAnywhere, Category="Tank")
	class UFloatingPawnMovement* FloatingPawnMovement;
	UPROPERTY(EditAnywhere, Category="Tank")
	float BodyRotationSpeed = 50;


	UPROPERTY(EditAnywhere, Category="Tank")
	float BarretRotationSpeed = 50;

	void MoveForward(float Value);
	void MoveRight(float value);
	void Turn(float value);
};
