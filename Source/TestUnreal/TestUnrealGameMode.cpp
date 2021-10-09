// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestUnrealGameMode.h"
#include "TestUnrealCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATestUnrealGameMode::ATestUnrealGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
