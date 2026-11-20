// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "DroguelSaveGame.generated.h"


//data
//THisPC documents programming FGTemplate FG Saved SaveGames

/**
 * 
 */
UCLASS()
class DROGUEL58_API UDroguelSaveGame : public USaveGame
{
	GENERATED_BODY()
	



//droguel
public:
	UDroguelSaveGame();

	UPROPERTY(VisibleAnywhere)
	int currency;


};
