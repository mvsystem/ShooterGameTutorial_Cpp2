// Mohamd Valizadeh


#include "Pawn/Tank.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(FName("SpringArm"));
	SpringArm->SetupAttachment(BodyMesh);
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	//this->bUseControllerRotationYaw = true;
	
	
	
	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovement"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UWorld* World = GetWorld();
	APlayerController* PlayerController = World->GetFirstPlayerController();
	PlayerController->bShowMouseCursor = true	;
	FHitResult HitResult;
	PlayerController->GetHitResultUnderCursor(ECC_Visibility,false,HitResult);
	FVector MouseLocation = HitResult.ImpactPoint;

	LookAtTarget(MouseLocation);

	
	

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward",this,&ATank::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight",this,&ATank::MoveRight);
	PlayerInputComponent->BindAction("Fire",IE_Pressed,this,&ATank::Fire);
	//PlayerInputComponent->BindAxis("Turn",this,&ATank::Turn);
	//PlayerInputComponent->BindAxis("LookUp",this,&ATank::LookUp);

}

void ATank::MoveForward(float Value)
{
	//UE_LOG(LogTemp,Warning,TEXT("%f"),Value);
	this->AddMovementInput(GetActorForwardVector(),Value);
}

void ATank::MoveRight(float value)
{
	//this->AddMovementInput(GetActorRightVector(),value);
	BodyMesh->AddRelativeRotation(FRotator(0,value * BodyRotationSpeed * GetWorld()->GetDeltaSeconds() ,0));
}

void ATank::Turn(float value)
{
	//this->AddControllerYawInput(value);
	BodyMesh->AddRelativeRotation(FRotator(0,value * TurretRotationSpeed * GetWorld()->GetDeltaSeconds() ,0));
}


