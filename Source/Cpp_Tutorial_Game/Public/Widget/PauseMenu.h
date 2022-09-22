// Mohamd Valizadeh

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PauseMenu.generated.h"

/**
 * 
 */
UCLASS()
class CPP_TUTORIAL_GAME_API UPauseMenu : public UUserWidget
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable)
	void QuitTinyTank();

	UFUNCTION(BlueprintCallable)
	void resumeButton1();

	
	UPROPERTY(meta=(bindwidget))
	class UButton* ResumeButton = nullptr;
	UPROPERTY(meta = (bindwidget))
	class UButton* OptionButton = nullptr;
	UPROPERTY(meta = (bindwidget))
	class UButton* QuitButton = nullptr;

public:
	virtual bool Initialize() override;
	
	
};
