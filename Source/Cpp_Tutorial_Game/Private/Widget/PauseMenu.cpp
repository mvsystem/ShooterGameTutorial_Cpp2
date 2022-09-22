// Mohamd Valizadeh


#include "Widget/PauseMenu.h"

#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UPauseMenu::QuitTinyTank()
{
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("Quit");
}

void UPauseMenu::resumeButton1()
{
	UGameplayStatics::SetGlobalTimeDilation(this,1);
	GetWorld()->GetFirstPlayerController()->EnableInput(GetWorld()->GetFirstPlayerController());
	RemoveFromParent();
}

bool UPauseMenu::Initialize()
{
	bool bSuccess = Super::Initialize();
	UE_LOG(LogTemp,Warning,TEXT("Pause Menu Begin Play Widget"));
	if(!bSuccess) return false;

	ResumeButton->OnClicked.AddDynamic(this,&UPauseMenu::resumeButton1);
	QuitButton->OnClicked.AddDynamic(this,&UPauseMenu::QuitTinyTank);

	return true;
}