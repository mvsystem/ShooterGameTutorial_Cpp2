// Mohamd Valizadeh

#pragma once

#include "CoreMinimal.h"
#include "../Cpp_Tutorial_GameGameMode.h"
#include "TinyTankGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FEnemyDead,int,CurrentEnemies,int,AllEnemies);

/**
 * 
 */
UCLASS()
class CPP_TUTORIAL_GAME_API ATinyTankGameMode : public ACpp_Tutorial_GameGameMode
{
	GENERATED_BODY()
public:
	ATinyTankGameMode();

	virtual void BeginPlay() override;

	void EnemyDead();

	FEnemyDead onEnemyDead;

private:
	TSubclassOf<class AEnamyPawn>EnemyClass;
	int AllEnemiesCount;
	int CurrentEnemiesCount;
	
};
