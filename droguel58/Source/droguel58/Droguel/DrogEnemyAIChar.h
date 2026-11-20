// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DrogEnemyAIChar.generated.h"

UCLASS()
class DROGUEL58_API ADrogEnemyAIChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADrogEnemyAIChar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gen")
	bool isSeeingPlayer;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level")
	int m_LevelNum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level")
	int m_EnemyID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level")
	FString m_EnemyDesc;



	UFUNCTION(BlueprintCallable, Category = "Level")
	void SetLevelNum(int levelnum);
	
	UFUNCTION(BlueprintCallable, Category = "Level")
	void SetEnemyID(int enemyID);

	UFUNCTION(BlueprintCallable, Category = "Level")
	void SetEnemyDesc(FString enemyDesc);
};
