// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <vector>
#include "TileMap.h"
#include "GameFramework/Actor.h"
#include "DrogLevelTriggerGatewayActor.generated.h"

UCLASS()
class DROGUEL58_API ADrogLevelTriggerGatewayActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADrogLevelTriggerGatewayActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UBoxComponent* CollisionBox;





	///////////////////////////////////////////////////////////////////////////
	// Sort
	///////////////////////////////////////////////////////////////////////////

	void LevelGatewayHit();

	void LoadMapLevel(int levelnum);
	void LoadEnemyLevel(int levelnum);
	void LoadGatewayLevel(int levelnum);
	void LoadItemLevel(int levelnum);

	void LoadSingleLevel();


	///////////////////////////////////////////////////////////////////////////
	// Utility functions - move to better location
	///////////////////////////////////////////////////////////////////////////


	int GetPlayerLevel();
	void FindActorToEnable(int level_num, bool enable);


	///////////////////////////////////////////////////////////////////////////
	// Data Load - move to better location
	///////////////////////////////////////////////////////////////////////////


	bool m_mapDataLoaded;
	void LoadMapData();


	///////////////////////////////////////////////////////////////////////////
	// Builder functions - move to better location
	///////////////////////////////////////////////////////////////////////////


	TileMap *m_pTileMap;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor>SingleLevelActor;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor>MonsterActorToSpawn;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor>GatewayTriggerActorToSpawn;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor>ItemActorToSpawn;


	///////////////////////////////////////////////////////////////////////////
	// Properties
	///////////////////////////////////////////////////////////////////////////


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level")
	int m_LevelNum;
};
