// Mohamd Valizadeh

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyFirstActor.generated.h"

UCLASS()
class CPP_TUTORIAL_GAME_API AMyFirstActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyFirstActor();
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="mv")
	UStaticMeshComponent* Meshcomponent;
	UPROPERTY(EditAnywhere,Category = "mv")
	class UBoxComponent* Boxx;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	
};
