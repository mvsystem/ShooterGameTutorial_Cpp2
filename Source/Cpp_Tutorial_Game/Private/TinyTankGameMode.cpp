// Mohamd Valizadeh


#include "TinyTankGameMode.h"

#include "Cpp_Tutorial_Game/EnamyPawn.h"
#include "Kismet/GameplayStatics.h"

#define OUT

ATinyTankGameMode::ATinyTankGameMode()
{
	ConstructorHelpers::FClassFinder<AEnamyPawn>Enemy_Class(TEXT("/Game/Blueprints/BP_EnamyPawn"));
	if(Enemy_Class.Class)
		EnemyClass=Enemy_Class.Class;
}

void ATinyTankGameMode::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*>Enemies;
	UGameplayStatics::GetAllActorsOfClass(this,EnemyClass,OUT Enemies);
	AllEnemiesCount = Enemies.Num();
	CurrentEnemiesCount = AllEnemiesCount;

	onEnemyDead.Broadcast(CurrentEnemiesCount,AllEnemiesCount);
}

void ATinyTankGameMode::EnemyDead()
{
	CurrentEnemiesCount--;
	onEnemyDead.Broadcast(CurrentEnemiesCount,AllEnemiesCount);
}
