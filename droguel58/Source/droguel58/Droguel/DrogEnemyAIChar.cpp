// Fill out your copyright notice in the Description page of Project Settings.


#include "DrogEnemyAIChar.h"

// Sets default values
ADrogEnemyAIChar::ADrogEnemyAIChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADrogEnemyAIChar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADrogEnemyAIChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADrogEnemyAIChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ADrogEnemyAIChar::SetLevelNum(int levelnum)
{
	m_LevelNum = levelnum;
}

void ADrogEnemyAIChar::SetEnemyID(int enemyID)
{
	m_EnemyID = enemyID;
}

void ADrogEnemyAIChar::SetEnemyDesc(FString enemyDesc)
{
	m_EnemyDesc = enemyDesc;
}

