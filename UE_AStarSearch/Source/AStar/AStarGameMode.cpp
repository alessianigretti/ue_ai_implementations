// Copyright Epic Games, Inc. All Rights Reserved.

#include "AStarGameMode.h"
#include "AStarPlayerController.h"
#include "AStarCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAStarGameMode::AAStarGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AAStarPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}