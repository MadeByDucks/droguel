// Fill out your copyright notice in the Description page of Project Settings.


#include "DrogInfoBFL.h"
#include "DroguelGameInstance.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "LevelMgr.h"
#include "Kismet/GameplayStatics.h" //UGameplayStatics - GameInstance
#include "DroguelGameInstance.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"


//temp test function
FString UDrogInfoBFL::DumpInfo(FString Name)
{
    if (GEngine)
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("UDrogInfoBFL::DumpInfo - TEST TEST TEST"));
    return FString(Name);
}


void UDrogInfoBFL::DumpCharacterInfo(ACharacter* myCharacter)
{
    int curlev = 0;
    //  ACharacter* myCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
    if (myCharacter)
    {
        FVector pos = myCharacter->GetActorLocation();
        if (GEngine)
            GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("PlayerPos: %.2f, %.2f, %.2f"), pos.X, pos.Y, pos.Z));

        curlev = LevelMgr::getCurLevelByPos(pos.Z);
        if (GEngine)
            GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("PlayerLevel: %i"), curlev));


        //if (auto gi = Cast<UDroguelGameInstance>(GetGameInstance()))
        //{
        //    int xTilePos = pos.X / gi->m_tilemap.mapdef.xm;
        //    int yTilePos = pos.Y / gi->m_tilemap.mapdef.ym;
        //    int zTilePos = pos.Z / gi->m_tilemap.mapdef.zm;
        //    if (GEngine)
        //        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("PlayerPos: %d, %d, %d"), xTilePos, yTilePos, zTilePos));
        //}
        int xTilePos = pos.X / 300;
        int yTilePos = pos.Y / 300;
        int zTilePos = pos.Z / 800;
        if (GEngine)
            GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("PlayerPos: %d, %d, %d"), xTilePos, yTilePos, zTilePos));

    }
}



