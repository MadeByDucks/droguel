// Fill out your copyright notice in the Description page of Project Settings.


#include "DrogItemActor.h"

// Sets default values
ADrogItemActor::ADrogItemActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADrogItemActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADrogItemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void ADrogItemActor::SetLevelNum(int levelnum)
{
	m_LevelNum = levelnum;
}

void ADrogItemActor::SetItemID(int itemID)
{
	m_ItemID = itemID;
}

void ADrogItemActor::SetItemDesc(FString itemDesc)
{
	m_ItemDesc = itemDesc;
}
