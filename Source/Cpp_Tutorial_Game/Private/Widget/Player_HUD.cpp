// Mohamd Valizadeh


#include "Widget/Player_HUD.h"

#include "TinyTankGameMode.h"
#include "Components/Button.h"
#include "Components/ProgressBar.h"
#include "Cpp_Tutorial_Game/Pawn/Tank.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Widget/PauseMenu.h"
#include "UObject/ConstructorHelpers.h"

UPlayer_HUD::UPlayer_HUD(const FObjectInitializer& ObjectInitializer) : UUserWidget(ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UPauseMenu> PauseMenuRefrence(TEXT("/Game/Blueprints/PauseMenu"));
	if (!PauseMenuRefrence.Class)
	{
		UE_LOG(LogTemp, Warning, TEXT("PeydaNashod"))
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("PeydaNashod"))

	PauseMenuClass = PauseMenuRefrence.Class;
}


bool UPlayer_HUD::Initialize()
{
	bool bSuccess = Super::Initialize();
	UE_LOG(LogTemp, Warning, TEXT("Begin Play Widget"));
	if (!bSuccess) return false;
	Pause->OnClicked.AddDynamic(this, &UPlayer_HUD::OnPauseClicked);

	if (ATank* playerpawn = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0)))
	{
		playerpawn->onHealthChanged.AddDynamic(this, &UPlayer_HUD::HealthChanged);
	}

	AGameModeBase* Gamemode = UGameplayStatics::GetGameMode(this);
	ATinyTankGameMode* TinyTankGM = Cast<ATinyTankGameMode>(Gamemode);

	TinyTankGM->onEnemyDead.AddDynamic(this,&UPlayer_HUD::EnemyDead);

	return true;
}

void UPlayer_HUD::OnPauseClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Event Rokh Dad"));

	UPauseMenu* CreatPauseMenu = CreateWidget<UPauseMenu>(GetWorld(), PauseMenuClass, FName("Pause Menu Widget"));

	UGameplayStatics::SetGlobalTimeDilation(this,0);
	GetWorld()->GetFirstPlayerController()->DisableInput(GetWorld()->GetFirstPlayerController());

	CreatPauseMenu->AddToViewport();
}

void UPlayer_HUD::EnemyDead(int CurrentEnemies, int AllEnemies)
{
}

void UPlayer_HUD::HealthChanged(float Health)
{
	float CarrentHealthInpercent = Health / 100;
	Health_Progress->SetPercent(CarrentHealthInpercent);
}
