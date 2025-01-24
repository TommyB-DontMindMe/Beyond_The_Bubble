// Copyright Epic Games, Inc. All Rights Reserved.

#include "Beyond_The_BubbleGameMode.h"
#include "Beyond_The_BubbleCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABeyond_The_BubbleGameMode::ABeyond_The_BubbleGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
