// Fill out your copyright notice in the Description page of Project Settings.

#include "DrogSingleLevActor.h"
#include "TileMap.h"
#include "DroguelGameInstance.h"


// Sets default values
ADrogSingleLevActor::ADrogSingleLevActor()
{
    if (GEngine)
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("DrogSingleLevActor Declared")));


 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    m_LevelLoaded = false;
    m_LevelNum = -1;
	SM_wall = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("SM_wall"));
	SM_floor = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("SM_floor"));
	SM_halfwall = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("SM_halfwall"));
	SM_door = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("SM_door"));
	SM_stair = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("SM_stair"));
	SM_gateway = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("SM_gateway"));


    //
    //Set mesh inside of class instead of in blueprints
    // 
    ////UInstancedStaticMeshComponent* SM_floor;
    //static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/MyMesh.MyMesh"));
    //UStaticMesh* Asset = MeshAsset.Object;
    //SM_floor->SetStaticMesh(Asset);
    
    
    m_isHidden = false;
}


// Called when the game starts or when spawned
void ADrogSingleLevActor::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void ADrogSingleLevActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void ADrogSingleLevActor::LoadLevel(int levelnum)
{
    GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString::Printf(TEXT("Loading Map: %d"), levelnum));
    m_LevelNum = levelnum;

   // std::vector<TileMap::ue_panels> ue_panel_list;
   // std::vector<TileMap::ue_monster> ue_monster_list;
    TileMap* pTileMap = NULL;
    if (auto gi = Cast<UDroguelGameInstance>(GetGameInstance()))
    {
        //gi->GetGameData(ue_panel_list, ue_monster_list);
        gi->LoadGameData();
        pTileMap = gi->m_pTileMap;
        m_LevelLoaded = true;
    }
    else
    {
        if (GEngine)
            GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("FAILED: Loading Map failed: %d"), levelnum));
    }

    for (int i = 0; i < pTileMap->level[levelnum].ue_panel_list.size(); i++)
    {
        LevelData::ue_panels panelObj = pTileMap->level[levelnum].ue_panel_list[i];

        //if (ue_panel_list[i].level == levelnum)
        //{
           // GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Building Level: %d"), levelnum));

            if (panelObj.tt == TileData::TT_PathWall) //2)//halfwall
            {
                TransformsHalfwall.Add(
                    FTransform(
                        FRotator(panelObj.pos.ry, panelObj.pos.rz, panelObj.pos.rx),  //swap y x
                        FVector(panelObj.pos.tx, panelObj.pos.ty, panelObj.pos.tz),
                        FVector(panelObj.pos.sx, panelObj.pos.sy, panelObj.pos.sz)
                    )
                );
            }
            else if (panelObj.tt == TileData::TT_StairUp) //4)//stairs
            {
                TransformsStairs.Add(
                    FTransform(
                        FRotator(panelObj.pos.ry, panelObj.pos.rz, panelObj.pos.rx),
                        FVector(panelObj.pos.tx, panelObj.pos.ty, panelObj.pos.tz),
                        FVector(panelObj.pos.sx, panelObj.pos.sy, panelObj.pos.sz)
                    )
                );
            }
            else if (panelObj.tt == TileData::TT_StairDown) //5)//stairs
            {
                TransformsStairs.Add(
                    FTransform(
                        FRotator(panelObj.pos.ry, panelObj.pos.rz, panelObj.pos.rx),
                        FVector(panelObj.pos.tx, panelObj.pos.ty, panelObj.pos.tz),
                        FVector(panelObj.pos.sx, panelObj.pos.sy, panelObj.pos.sz)
                    )
                );
            }
            else if (panelObj.tt == TileData::TT_Gateway)
            {
                TransformsGateway.Add(
                    FTransform(
                        FRotator(panelObj.pos.ry, panelObj.pos.rz, panelObj.pos.rx),
                        FVector(panelObj.pos.tx, panelObj.pos.ty, panelObj.pos.tz),
                        FVector(panelObj.pos.sx, panelObj.pos.sy, panelObj.pos.sz)
                    )
                );
            }
            else if (panelObj.tt == TileData::TT_Wall) //3)//wall
            {
                TransformsWall.Add(
                    FTransform(
                        FRotator(panelObj.pos.ry, panelObj.pos.rz, panelObj.pos.rx),
                        FVector(panelObj.pos.tx, panelObj.pos.ty, panelObj.pos.tz),
                        FVector(panelObj.pos.sx, panelObj.pos.sy, panelObj.pos.sz)
                    )
                );
            }
            else if (panelObj.tt == TileData::TT_Floor)// 0)//floor
            {
                TransformsFloor.Add(
                    FTransform(
                        FRotator(panelObj.pos.ry, panelObj.pos.rz, panelObj.pos.rx),
                        FVector(panelObj.pos.tx, panelObj.pos.ty, panelObj.pos.tz),
                        FVector(panelObj.pos.sx, panelObj.pos.sy, panelObj.pos.sz)
                    )
                );
            }
            else if (panelObj.tt == TileData::TT_Door) //36) //door
            {
                TransformsDoor.Add(
                    FTransform(
                        FRotator(panelObj.pos.ry, panelObj.pos.rz, panelObj.pos.rx),
                        FVector(panelObj.pos.tx, panelObj.pos.ty, panelObj.pos.tz),
                        FVector(panelObj.pos.sx, panelObj.pos.sy, panelObj.pos.sz)
                    )
                );
            }
        //}
    }

    if (m_LevelLoaded)
    {
        bool floorOnly = false;

        if (GEngine)
            GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("Drawing Level: %d"), levelnum));

        if (!floorOnly)
        {
            SM_wall->AddInstances(TransformsWall, false);// , true);
        }

        SM_floor->RegisterComponent();
        SM_floor->AddInstances(TransformsFloor, false);// , true);
        SM_floor->SetCollisionProfileName("BlockAll");
        SM_floor->SetCustomNavigableGeometry(EHasCustomNavigableGeometry::EvenIfNotCollidable);

        if (!floorOnly)
        {        
            SM_halfwall->AddInstances(TransformsHalfwall, false);// , false, true);
        }

        if (!floorOnly)
        {
            SM_door->AddInstances(TransformsDoor, false);// , true);
        }

        SM_stair->RegisterComponent();
        SM_stair->AddInstances(TransformsStairs, false);// , true);
        SM_stair->SetCollisionProfileName("BlockAll");
        SM_stair->SetCustomNavigableGeometry(EHasCustomNavigableGeometry::EvenIfNotCollidable);

        SM_gateway->AddInstances(TransformsGateway, false);// , true);
    }
}

int ADrogSingleLevActor::GetLevelNum()
{
    return m_LevelNum;
}

void ADrogSingleLevActor::DisableActor()
{
    m_isHidden = true;
    SetActorHiddenInGame(true);
    SetActorEnableCollision(false);
    SetActorTickEnabled(false);
}

void ADrogSingleLevActor::EnableActor()
{
    m_isHidden = false;
    SetActorHiddenInGame(false);
    SetActorEnableCollision(true);
    SetActorTickEnabled(true);
}
