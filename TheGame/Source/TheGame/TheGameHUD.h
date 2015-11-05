// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once 
#include "GameFramework/HUD.h"
#include "TheGameHUD.generated.h"

UCLASS()
class ATheGameHUD : public AHUD
{
	GENERATED_BODY()


public:
	ATheGameHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

	bool ShowCursor = true;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;
	
};

