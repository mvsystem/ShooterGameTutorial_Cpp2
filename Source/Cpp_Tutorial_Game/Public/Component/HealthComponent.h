// Mohamd Valizadeh

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CPP_TUTORIAL_GAME_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere,Category="Properties")
	USoundBase* ExplosionSound;
	UPROPERTY(EditAnywhere,Category = "Properties" )
	UParticleSystem* ExplosionEffect;
	
	UPROPERTY(EditAnywhere,Category = "EVENT")
	float defaultHeith = 100;
	float CurrentHelth;

	bool IsDead = false;
	
    UFUNCTION()
	void TakDamage(AActor* DamagedActor,float Damage,const UDamageType* DamageType,AController* Instigator,AActor* DamageCouser);

	

		
};
