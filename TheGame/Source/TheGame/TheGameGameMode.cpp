// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "TheGame.h"
#include "TheGameGameMode.h"
#include "TheGameHUD.h"
#include "TheGameCharacter.h"

ATheGameGameMode::ATheGameGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATheGameHUD::StaticClass();
}
