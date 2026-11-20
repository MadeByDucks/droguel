// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "vector"
#include "TileMap.h"
#include "LevelMgr.h"
#include "Engine/GameInstance.h"
#include "DroguelGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class DROGUEL58_API UDroguelGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	virtual void Init() override;

	//std::vector<TileMap::ue_panels> ue_panel_list;
	//std::vector<TileMap::ue_monster> ue_monster_list;
	TileMap *m_pTileMap;
	//std::vector<int> m_levelLoaded;
	//LevelMgr levMgr;
	
	void CreateSaveFile();
	void SaveGame();
	void LoadGame();
	void LoadGameData();
	/////void GetGameData();// std::vector<TileMap::ue_panels>& panel_list, std::vector<TileMap::ue_monster>& monster_list);

	//The amount of currency the main player has at the current time
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Profile")
	int totalCurrency;

	UPROPERTY(EditAnywhere)
	bool map_loaded;

};
