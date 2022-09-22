// Mohamd Valizadeh

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Player_HUD.generated.h"

/**
 * 
 */
UCLASS()
class CPP_TUTORIAL_GAME_API UPlayer_HUD : public UUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* Health_Progress = nullptr;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Enemies = nullptr;
	UPROPERTY(meta = (BindWidget))
	class UButton* Pause = nullptr;
	UFUNCTION()
	void OnPauseClicked();

	UFUNCTION()
	void EnemyDead(int CurrentEnemies,int AllEnemies);
	
	UFUNCTION()
	void HealthChanged(float Health);

	TSubclassOf<class UPauseMenu>PauseMenuClass;
public:
	virtual bool Initialize() override;
	UPlayer_HUD(const FObjectInitializer& ObjectInitializer);
	
	
	
	
};
