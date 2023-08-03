// Copyright Epic Games, Inc. All Rights Reserved.

#include "DecisionMakerGameMode.h"
#include "DecisionMakerCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADecisionMakerGameMode::ADecisionMakerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
