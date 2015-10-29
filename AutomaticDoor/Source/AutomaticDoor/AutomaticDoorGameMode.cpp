// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "AutomaticDoor.h"
#include "AutomaticDoorGameMode.h"
#include "AutomaticDoorHUD.h"
#include "AutomaticDoorCharacter.h"

AAutomaticDoorGameMode::AAutomaticDoorGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AAutomaticDoorHUD::StaticClass();
}
