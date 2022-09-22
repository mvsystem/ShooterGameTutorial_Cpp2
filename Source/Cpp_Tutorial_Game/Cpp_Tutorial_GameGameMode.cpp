// Copyright Epic Games, Inc. All Rights Reserved.

#include "Cpp_Tutorial_GameGameMode.h"
#include "Cpp_Tutorial_GameCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACpp_Tutorial_GameGameMode::ACpp_Tutorial_GameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
