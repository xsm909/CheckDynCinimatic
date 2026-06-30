// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetRegistry/AssetData.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AssetsHelper.generated.h"

/**
 * 
 */
UCLASS()
class CINIMATICDIRECTORRUNTIME_API UAssetsHelper : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "Assets Helper", meta = (DeterminesOutputType = "AssetClass"))
	static TArray<FAssetData> GetAssetsByPath(FString DirectoryPath, TSubclassOf<UObject> AssetClass, bool bRecursive = true);
};
