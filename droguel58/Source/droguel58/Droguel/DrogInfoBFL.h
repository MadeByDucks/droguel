// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DrogInfoBFL.generated.h"

UCLASS()
class DROGUEL58_API UDrogInfoBFL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, Category = "DumpInfo")
    static FString DumpInfo(FString Name);

    UFUNCTION(BlueprintCallable, Category = "DumpCharacterInfo")
    static void DumpCharacterInfo(ACharacter* myCharacter);
};
