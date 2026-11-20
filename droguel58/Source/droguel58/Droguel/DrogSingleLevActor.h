// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "DrogSingleLevActor.generated.h"

UCLASS()
class DROGUEL58_API ADrogSingleLevActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADrogSingleLevActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	bool m_LevelLoaded;
	void LoadLevel(int levelnum);

public:
	UPROPERTY(Transient)
	TArray<FTransform> TransformsWall;
	UPROPERTY(Transient)
	TArray<FTransform> TransformsFloor;
	UPROPERTY(Transient)
	TArray<FTransform> TransformsHalfwall;
	UPROPERTY(Transient)
	TArray<FTransform> TransformsDoor;
	UPROPERTY(Transient)
	TArray<FTransform> TransformsStairs;
	UPROPERTY(Transient)
	TArray<FTransform> TransformsGateway;

	UPROPERTY(VisibleAnywhere)
	UInstancedStaticMeshComponent* SM_wall;
	UPROPERTY(VisibleAnywhere)
	UInstancedStaticMeshComponent* SM_floor;
	UPROPERTY(VisibleAnywhere)
	UInstancedStaticMeshComponent* SM_halfwall;
	UPROPERTY(VisibleAnywhere)
	UInstancedStaticMeshComponent* SM_door;
	UPROPERTY(VisibleAnywhere)
	UInstancedStaticMeshComponent* SM_stair;
	UPROPERTY(VisibleAnywhere)
	UInstancedStaticMeshComponent* SM_gateway;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level")
	int m_LevelNum;

	UFUNCTION(BlueprintCallable, Category = "Level")
	int GetLevelNum();

	UPROPERTY(EditAnywhere, Category = "EnableDisable")
	bool m_isHidden;

	UFUNCTION(BlueprintCallable, Category = "EnableDisable")
	void DisableActor();

	UFUNCTION(BlueprintCallable, Category = "EnableDisable")
	void EnableActor();
};
