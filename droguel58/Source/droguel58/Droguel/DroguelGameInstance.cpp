// Fill out your copyright notice in the Description page of Project Settings.


#include "DroguelGameInstance.h"
#include "MapBuilder.h"
#include "Kismet/GameplayStatics.h" //what features ttdtodo study
#include "DroguelSaveGame.h"

//Saving& Loading!| How To Make YOUR OWN Fighting Game | UE4 / UE5 & C++ Tutorial, Part 181
//https://www.youtube.com/watch?v=1XojoHjAOMY




void UDroguelGameInstance::Init()
{
    Super::Init();
    //FCoreDelegates::OnControllerConnectionChange.AddUObject(this, &UBaseGameInstance::ControllerConnectionChanged);

    if (GEngine)
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("UDroguelGameInstance::Init()"));

    map_loaded = false;

    //Load the game upon tinitializing the BaseGameInstance
    LoadGame();
}


///////////////////////////////////////////////////////////////////////////////
// Game Load/Save Mgr
///////////////////////////////////////////////////////////////////////////////


void UDroguelGameInstance::CreateSaveFile()
{
    //Kismet
    //Create a SaveGame object and save to the default slot
    UDroguelSaveGame* dataToSave = Cast<UDroguelSaveGame>(UGameplayStatics::CreateSaveGameObject(UDroguelSaveGame::StaticClass()));
    UGameplayStatics::SaveGameToSlot(dataToSave, "Slot1", 0); //user index
}

void UDroguelGameInstance::SaveGame()
{
    //Initialize data to save
    UDroguelSaveGame* dataToSave = Cast<UDroguelSaveGame>(UGameplayStatics::LoadGameFromSlot("Slot1", 0));

    //If there is a valid SaveGame object to use for saving
    if (dataToSave != nullptr)
    {
        dataToSave->currency = totalCurrency;
        UGameplayStatics::SaveGameToSlot(dataToSave, "Slot1", 0);
    }
    else if (!UGameplayStatics::DoesSaveGameExist("Slot1", 0))
    {
        //Create a default save file since
        CreateSaveFile();
    }
}

void UDroguelGameInstance::LoadGameData()
{
    if (map_loaded == false)
    {
        m_pTileMap = new TileMap(MAPDEF_DEFAULT_TILES_X, MAPDEF_DEFAULT_TILES_Y, MAPDEF_DEFAULT_LEVELS_Z, 0, "main");
        MapBuilder x;
        x.BuildMap(*m_pTileMap, true); //stacked map
        m_pTileMap->dumpTileMap("D:\\projects\\devduck\\temp\\droguel\\active_level_data.txt");
        map_loaded = true;
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("UDroguelGameInstance::LoadGameData - Map Data Loaded"));
    }
}

////void UDroguelGameInstance::GetGameData()//std::vector<TileMap::ue_panels>& panel_list, std::vector<TileMap::ue_monster>& monster_list)
////{
////    LoadGameData();
////    //monster_list = m_tilemap.ue_monster_list;
////    //panel_list = m_tilemap.ue_panel_list;
////}

void UDroguelGameInstance::LoadGame()
{
    LoadGameData();

    //Retriecve data to load
    UDroguelSaveGame* dataToLoad = Cast<UDroguelSaveGame>(UGameplayStatics::LoadGameFromSlot("Slot1", 0));

    //If there is a valid data to load
    if (dataToLoad != nullptr)
    {
        totalCurrency = dataToLoad->currency;
    }
    else if (!UGameplayStatics::DoesSaveGameExist("Slot1", 0))
    {
        //Creaet a default save file since
        CreateSaveFile();
    }
}
