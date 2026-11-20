// Fill out your copyright notice in the Description page of Project Settings.


#include "DrogLevelTriggerGatewayActor.h"
#include "DroguelGameInstance.h"
#include "Kismet/GameplayStatics.h" //UGameplayStatics - GameInstance
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"
#include "DrogSingleLevActor.h"
#include "DrogEnemyAIChar.h"
#include "DrogItemActor.h"
#include "GameFramework/Pawn.h"
//#include "CharMonsterList.h" //ttdtodo - temp
//#include "ItemListObjects.h" //ttdtodo - temp
#include "DrogDef.h"


//https://www.youtube.com/watch?v=tc7fntJTbHM


// Sets default values
ADrogLevelTriggerGatewayActor::ADrogLevelTriggerGatewayActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionBox->SetBoxExtent(FVector(32.3, 32.f, 32.f));
	CollisionBox->SetCollisionProfileName("Trigger");
	RootComponent = CollisionBox;

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ADrogLevelTriggerGatewayActor::OnOverlapBegin);
	CollisionBox->OnComponentEndOverlap.AddDynamic(this, &ADrogLevelTriggerGatewayActor::OnOverlapEnd);

	m_LevelNum = -1;
}


// Called when the game starts or when spawned
void ADrogLevelTriggerGatewayActor::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void ADrogLevelTriggerGatewayActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}








void ADrogLevelTriggerGatewayActor::LoadMapData()
{
	if (auto gi = Cast<UDroguelGameInstance>(GetGameInstance()))
	{
		if (!m_mapDataLoaded)
		{
			//gi->GetGameData(ue_panel_list, ue_monster_list);
			gi->LoadGameData();
			m_pTileMap = gi->m_pTileMap;
			m_mapDataLoaded = true;
		}
	}
	else
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("FAILED: Load map data failed"));
	}
}








//https://docs.unrealengine.com/4.27/en-US/InteractiveExperiences/HowTo/FindingActors/
void ADrogLevelTriggerGatewayActor::FindActorToEnable(int level_num, bool enable)
{
	bool foundActor = false;

	auto gi = Cast<UDroguelGameInstance>(GetGameInstance());
	//if (gi)
	{
		gi->m_pTileMap->levMgr.SetLevelEnabled(level_num, enable);
	}



	/////////////////////////////////////////////////////////////////////////////////////
	//ADrogEnemyAIChar
	/////////////////////////////////////////////////////////////////////////////////////

	TArray<AActor*> ActorsToFindMonster;
	if (UWorld* World = GetWorld())
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADrogEnemyAIChar::StaticClass(), ActorsToFindMonster);
	}
	for (AActor* MonsterGenActor : ActorsToFindMonster)
	{
		ADrogEnemyAIChar* MonsterCast = Cast<ADrogEnemyAIChar>(MonsterGenActor);
		if (MonsterCast)
		{
			if (MonsterCast->m_LevelNum == level_num)
			{
				foundActor = true;
				if (enable)
				{
					GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("ENABLE Monster: %i"), level_num));
					MonsterCast->SetActorHiddenInGame(false);
					MonsterCast->SetActorEnableCollision(true);
					MonsterCast->SetActorTickEnabled(true);
				}
				else
				{
					GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("DISABLE Monster: %i"), level_num));
					MonsterCast->SetActorHiddenInGame(true);
					MonsterCast->SetActorEnableCollision(false);
					MonsterCast->SetActorTickEnabled(false);
				}
			}
		}
		else
		{
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Failed: BoxHitEvent: Unable to find Monster Actor"));
		}
	}



	/////////////////////////////////////////////////////////////////////////////////////
	//ADrogItemActor
	/////////////////////////////////////////////////////////////////////////////////////

	TArray<AActor*> ActorsToFindItem;
	if (UWorld* World = GetWorld())
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADrogItemActor::StaticClass(), ActorsToFindItem);
	}
	for (AActor* ItemGenActor : ActorsToFindItem)
	{
		ADrogItemActor* ItemCast = Cast<ADrogItemActor>(ItemGenActor);
		if (ItemCast)
		{
			if (ItemCast->m_LevelNum == level_num)
			{
				foundActor = true;
				if (enable)
				{
					GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("ENABLE Item: %i"), level_num));
					ItemCast->SetActorHiddenInGame(false);
					ItemCast->SetActorEnableCollision(true);
					ItemCast->SetActorTickEnabled(true);
				}
				else
				{
					GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("DISABLE Item: %i"), level_num));
					ItemCast->SetActorHiddenInGame(true);
					ItemCast->SetActorEnableCollision(false);
					ItemCast->SetActorTickEnabled(false);
				}
			}
		}
		else
		{
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Failed: BoxHitEvent: Unable to find Item Actor"));
		}
	}

	/////////////////////////////////////////////////////////////////////////////////////
	//ADrogSingleLevActor
	/////////////////////////////////////////////////////////////////////////////////////

	////Find Actor
    TArray<AActor*> ActorsToFind;
    if (UWorld* World = GetWorld())
    {
        UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADrogSingleLevActor::StaticClass(), ActorsToFind);
    }
    for (AActor* MapGenActor : ActorsToFind)
    {
		ADrogSingleLevActor* MapGenCast = Cast<ADrogSingleLevActor>(MapGenActor);
        if (MapGenCast)
        {
            //GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("Process Gateway Level BoxHitEvent"));
            
            //FVector Foo = { 10.f, 20.f, 30.f };
            //MapGenCast->HitLevelGateway(Foo);
			if (MapGenCast->GetLevelNum() == level_num)
			{
				foundActor = true;
				if (enable)
				{
					GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("ENABLE: %i"), level_num));
					MapGenCast->EnableActor();
				}
				else
				{
					GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("DISABLE: %i"), level_num));
					MapGenCast->DisableActor();
				}
			}
        }
        else
        {
            if (GEngine)
                GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Failed: BoxHitEvent: Unable to find Mapping Actor"));
        }
    }

	/////////////////////////////////////////////////////////////////////////////////////
	//ADrogLevelTriggerGatewayActor
	/////////////////////////////////////////////////////////////////////////////////////

	TArray<AActor*> ActorsToFindGateway;
	if (UWorld* World = GetWorld())
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADrogEnemyAIChar::StaticClass(), ActorsToFindGateway);
	}
	for (AActor* GatewayGenActor : ActorsToFindGateway)
	{
		ADrogEnemyAIChar* GatewayCast = Cast<ADrogEnemyAIChar>(GatewayGenActor);
		if (GatewayCast)
		{
			if (m_LevelNum == level_num)  //(GatewayCast->GetLevelNum() == level_num)
			{
				foundActor = true;
				if (enable)
				{
					GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("ENABLE Gateway: %i"), level_num));
					GatewayCast->SetActorHiddenInGame(false);
					GatewayCast->SetActorEnableCollision(true);
					GatewayCast->SetActorTickEnabled(true);
				}
				else
				{
					GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("DISABLE Gateway: %i"), level_num));
					GatewayCast->SetActorHiddenInGame(true);
					GatewayCast->SetActorEnableCollision(false);
					GatewayCast->SetActorTickEnabled(false);
				}
			}
		}
		else
		{
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Failed: BoxHitEvent: Unable to find Gateway Actor"));
		}
	}
}




int ADrogLevelTriggerGatewayActor::GetPlayerLevel()
{
	int curlev = 0;
	ACharacter* myCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (myCharacter)
	{
		FVector pos = myCharacter->GetActorLocation();
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("GATEWAY GATEWAY GATEWAY PlayerPos: %f,%f,%f"), pos.X, pos.Y, pos.Z));

		curlev = LevelMgr::getCurLevelByPos(pos.Z);
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("GATEWAY GATEWAY GATEWAY PlayerLevel: %i"), curlev));
	}
	return curlev;
}




void ADrogLevelTriggerGatewayActor::LevelGatewayHit()
{
	int curlev = GetPlayerLevel();
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("Hit Level Gateway: %i"), curlev));


	auto gi = Cast<UDroguelGameInstance>(GetGameInstance());
	if (gi)
	{
		/////////////////////////////////////////////////////////////////////////////
        //Build New Levels
        /////////////////////////////////////////////////////////////////////////////
        int minLevel;
        int maxLevel;
        gi->m_pTileMap->levMgr.GetLevelsToLoad(gi->m_pTileMap->m_mapdef, curlev, minLevel, maxLevel);
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("---Level Loading Min / Max / Cur: %i / %i / %i"), minLevel, maxLevel, curlev));

        for (int i = minLevel; i <= maxLevel; i++)
        {
            if (!gi->m_pTileMap->levMgr.IsLevelLoaded(i))
            {
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("---Level Loading: %i"), i));
				LoadMapLevel(i);
                LoadGatewayLevel(i);

				if (DrogDef::UE_ADD_ITEMS)
				{
					LoadItemLevel(i);
				}
				if (DrogDef::UE_ADD_MONSTER)
				{
					LoadEnemyLevel(i);
				}

                gi->m_pTileMap->levMgr.SetLevelLoaded(i, true);
            }
            else
            {
                /////////////////////////////////////////////////////////////////////////////
                //Activate Level iff hidden - ttdtodo: need to check if enabled before setting enabled again
                /////////////////////////////////////////////////////////////////////////////	
				if (!gi->m_pTileMap->levMgr.IsLevelEnabled(i))
				{
					GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("---Level already loaded - Enable : %i"), i));
					FindActorToEnable(i, true);
				}
            }
        }


		/////////////////////////////////////////////////////////////////////////////
		//Destroy Old Levels - ttdtodo: save list so not to traverse all actors
		/////////////////////////////////////////////////////////////////////////////
		for (int i = 0; i < gi->m_pTileMap->levMgr.m_levels.size(); i++)
		{
			//if ((gi->m_pTileMap->levMgr.m_levelLoaded[i] < minLevel) || (gi->m_pTileMap->levMgr.m_levelLoaded[i] > maxLevel))//ttdtodo figure it out
			if ((i < minLevel) || (i > maxLevel))
			{
				if (gi->m_pTileMap->levMgr.IsLevelEnabled(i))
				{
			        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("---Hide Level - Disable : %i"), i));
					FindActorToEnable(i, false);
				}
			}
		}
	}
	else
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("FAILED: Unable to get GameInstance to load level")));
	}
}





void ADrogLevelTriggerGatewayActor::LoadMapLevel(int levelnum)
{
	//AActor
	//ADrogSingleLevActor 
		AActor *sla = GetWorld()->SpawnActor<AActor>(SingleLevelActor,
        FTransform(
            FRotator(0.0, 0.0, 0.0),
            FVector(0.0, 0.0, 0.0),
            FVector(1.0, 1.0, 1.0)
        )
    );

	ADrogSingleLevActor* blablabla = Cast<ADrogSingleLevActor>(sla);

	if (sla == NULL)
	{
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Failed: Did not retrieve SingleLevelActor"));
	}
	else
	{
       GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("PASSED: prep loading SingleLevelActor"));
	}
	if (blablabla == NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Failed: Did not retrieve SingleLevelActor222"));
	}
	else
	{
		//ttdtodo: can do all init on spawn actor then just set level number instead of creating class then building meshes
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("PASSED: prep loading SingleLevelActor222"));
		blablabla->LoadLevel(levelnum);
	}
}

void ADrogLevelTriggerGatewayActor::LoadEnemyLevel(int levelnum)
{
    GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Spawning Monsters"));
    LoadMapData();

    for (int i = 0; i < m_pTileMap->level[levelnum].ue_monster_list.size(); i++)
    {
        LevelData::ue_monster monstObj = m_pTileMap->level[levelnum].ue_monster_list[i];
        AActor* actor = GetWorld()->SpawnActor<AActor>(MonsterActorToSpawn,
            FTransform(
                FRotator(monstObj.pos.ry, monstObj.pos.rz, monstObj.pos.rx),
                FVector(monstObj.pos.tx, monstObj.pos.ty, monstObj.pos.tz),
                FVector(monstObj.pos.sx, monstObj.pos.sy, monstObj.pos.sz)
            )
        );

        ADrogEnemyAIChar* blablabla = Cast<ADrogEnemyAIChar>(actor);
        if (blablabla == NULL)
        {
            GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Failed: Did not retrieve ADrogEnemyAIChar"));
        }
        else
        {
            GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("PASSED: prep loading ADrogEnemyAIChar"));
            blablabla->SetLevelNum(levelnum);


			//ttdtodo - temp
			std::string monster_str;
//			int monster_id;
//			CharMonsterList list;
//			list.selectRandomMonster(monster_id, monster_str);
//			FString monster_fstr(monster_str.c_str());
int monster_id = 123;
FString monster_fstr = "123 Monster";
			blablabla->SetEnemyID(monster_id);
			blablabla->SetEnemyDesc(monster_fstr);


			//Actor needs to fully load before calling
			//SetActorHiddenInGame(true);
			//SetActorEnableCollision(false);
			//SetActorTickEnabled(false);
        }
    }
}


void ADrogLevelTriggerGatewayActor::LoadItemLevel(int levelnum)
{
    GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Spawning Items"));
    LoadMapData();

    for (int i = 0; i < m_pTileMap->level[levelnum].ue_item_list.size(); i++)
    {
        LevelData::ue_item itemObj = m_pTileMap->level[levelnum].ue_item_list[i];
        AActor* actor = GetWorld()->SpawnActor<AActor>(ItemActorToSpawn,
            FTransform(
                FRotator(itemObj.pos.ry, itemObj.pos.rz, itemObj.pos.rx),
                FVector(itemObj.pos.tx, itemObj.pos.ty, itemObj.pos.tz),
                FVector(itemObj.pos.sx, itemObj.pos.sy, itemObj.pos.sz)
            )
        );

		ADrogItemActor* blablabla = Cast<ADrogItemActor>(actor);
		if (blablabla == NULL)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Failed: Did not retrieve ADrogItemActor"));
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("PASSED: prep loading ADrogITemActor"));
			blablabla->SetLevelNum(levelnum);



			//ttdtodo - temp
			std::string item_str;
			//int item_id;
			//ItemListObjects list;
			//list.selectRandomItem(item_id, item_str);
			//FString item_fstr(item_str.c_str());
int item_id = 123;
FString item_fstr = "temp Item Desc";
			blablabla->SetItemID(item_id);
			blablabla->SetItemDesc(item_fstr);

			

			//Actor needs to fully load before calling
			//SetActorHiddenInGame(true);
			//SetActorEnableCollision(false);
			//SetActorTickEnabled(false);
		}
    }
}

void ADrogLevelTriggerGatewayActor::LoadGatewayLevel(int levelnum)
{
    GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Spawning Gateways"));
    LoadMapData();

    for (int i = 0; i < m_pTileMap->level[levelnum].ue_panel_list.size(); i++)
    {
        LevelData::ue_panels panelObj = m_pTileMap->level[levelnum].ue_panel_list[i];

        if (panelObj.tt == TileData::TT_Gateway)
        {
            AActor* actor = GetWorld()->SpawnActor<AActor>(GatewayTriggerActorToSpawn,
                FTransform(
                    FRotator(panelObj.pos.ry, panelObj.pos.rz, panelObj.pos.rx),
                    FVector(panelObj.pos.tx, panelObj.pos.ty, panelObj.pos.tz),
                    FVector(5, 5, 5) //ttdtodo
                    //FVector(panelObj.pos.sx, panelObj.pos.sy, panelObj.pos.sz)
                )
            );
        }
    }
}











//https://docs.unrealengine.com/4.26/en-US/ProgrammingAndScripting/ProgrammingWithCPP/UnrealArchitecture/Actors/Spawning/
void ADrogLevelTriggerGatewayActor::LoadSingleLevel()
{
	LevelGatewayHit();
}

void ADrogLevelTriggerGatewayActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Gateway OnOverlapBegin"));

	// Only the player triggers a level load (enemies/items overlapping the gateway are ignored).
	APawn* mechar = Cast<APawn>(OtherActor);
	if (mechar != nullptr && mechar->IsPlayerControlled())
	{
		LoadSingleLevel();
	}
	else
	{
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("FAILED: Unable to get ADrogLevelTriggerGatewayActor Character"));
	}
}


void ADrogLevelTriggerGatewayActor::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Gateway OnOverlapEnd"));
}
