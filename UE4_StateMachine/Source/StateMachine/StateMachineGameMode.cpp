// Copyright Epic Games, Inc. All Rights Reserved.

#include "StateMachineGameMode.h"
#include "StateMachineHUD.h"
#include "StateMachineCharacter.h"
#include "UObject/ConstructorHelpers.h"

AStateMachineGameMode::AStateMachineGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AStateMachineHUD::StaticClass();
}
