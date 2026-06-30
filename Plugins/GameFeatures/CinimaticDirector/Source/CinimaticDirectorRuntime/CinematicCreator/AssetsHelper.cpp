// Fill out your copyright notice in the Description page of Project Settings.


#include "AssetsHelper.h"

#include "AssetRegistry/AssetRegistryModule.h"

TArray<FAssetData> UAssetsHelper::GetAssetsByPath(FString DirectoryPath, TSubclassOf<UObject> AssetClass,
                                                  bool bRecursive)
{
	TArray<FAssetData> OutAssets;

	// Загружаем модуль AssetRegistry
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();

	// Настраиваем фильтр
	FARFilter Filter;
	Filter.PackagePaths.Add(FName(*DirectoryPath));
	Filter.bRecursivePaths = bRecursive;
    
	// Указываем класс (используем GetClassPathName для актуальности в последних версиях UE)
	if (AssetClass)
	{
		Filter.ClassPaths.Add(AssetClass->GetClassPathName());
	}

	// Получаем данные
	AssetRegistry.GetAssets(Filter, OutAssets);

	return OutAssets;
}
