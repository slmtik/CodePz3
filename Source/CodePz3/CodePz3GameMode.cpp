// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "CodePz3GameMode.h"
#include "CodePz3HUD.h"
#include "CodePz3Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Turret.h"

ACodePz3GameMode::ACodePz3GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ACodePz3HUD::StaticClass();

	TArray<AActor*> turretActors;
	UGameplayStatics::GetAllActorsOfClass(this, ATurret::StaticClass(), turretActors);
	for (AActor* turretActor : turretActors)
	{
		ATurret* turret = Cast<ATurret>(turretActor);
		if (turret)
		{
			turret->OnTurretKilled.AddUFunction(this, "OnTurretKilled", turret->ScoreForKill);
		}
	}
}

void ACodePz3GameMode::OnTurretKilled(float ScoreChangeValue)
{
	_Score += ScoreChangeValue;
}
