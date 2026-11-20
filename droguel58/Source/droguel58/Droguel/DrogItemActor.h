// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DrogItemActor.generated.h"

UCLASS()
class DROGUEL58_API ADrogItemActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADrogItemActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level")
	int m_LevelNum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level")
	int m_ItemID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level")
	FString m_ItemDesc;


	UFUNCTION(BlueprintCallable, Category = "Level")
	void SetLevelNum(int levelnum);

	UFUNCTION(BlueprintCallable, Category = "Level")
	void SetItemID(int itemID);

	UFUNCTION(BlueprintCallable, Category = "Level")
	void SetItemDesc(FString itemDesc);


};
