// Mohamd Valizadeh

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Object_MV.generated.h"

UCLASS()
class CPP_TUTORIAL_GAME_API AObject_MV : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObject_MV();

	UPROPERTY(EditAnywhere,Category="Actor")
	AActor* Door=nullptr;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

};
