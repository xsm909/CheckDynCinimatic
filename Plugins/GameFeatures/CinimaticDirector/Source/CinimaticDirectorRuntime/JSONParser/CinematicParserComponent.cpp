// Fill out your copyright notice in the Description page of Project Settings.


#include "CinematicParserComponent.h"

#include "JsonObjectConverter.h"


// Sets default values for this component's properties
UCinematicParserComponent::UCinematicParserComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

bool UCinematicParserComponent::LoadScenario(FString JsonString)
{
	// Используем TJsonReader для чтения строки
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonString);
    
	// Прямая десериализация в TArray через встроенный конвертер
	// Это избавляет нас от ручного цикла и создания промежуточных FJsonValue
	TArray<FCinematicAction> TempActions;
	if (!FJsonObjectConverter::JsonArrayStringToUStruct(JsonString, &TempActions))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to deserialize JSON array to FCinematicAction array"));
		return false;
	}

	// Присваиваем результат и сортируем
	Actions = MoveTemp(TempActions);
    
	Actions.Sort([](const FCinematicAction& A, const FCinematicAction& B) {
		return A.Time < B.Time;
	});

	CurrentIndex = 0;
	return true;
}
