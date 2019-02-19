// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CodePz3GameMode.generated.h"

UCLASS(minimalapi)
class ACodePz3GameMode : public AGameModeBase
{
	GENERATED_BODY()

	float _Score;

public:
	ACodePz3GameMode();

	UFUNCTION()
	void OnTurretKilled(float ScoreChangeValue);

	UFUNCTION()
	float GetScore() { return _Score; }
};



