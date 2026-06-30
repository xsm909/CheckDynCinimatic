// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CinematicParserComponent.generated.h"

USTRUCT(BlueprintType)
struct FCinematicAction
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Time = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Alias;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Type; // Например, "move_to", "teleport", "play_montage"

	// Опциональные поля: заполняйте только те, которые нужны для конкретной команды
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector VectorValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator RotatorValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float FloatValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString StringValue; // Для имен анимаций или команд
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CINIMATICDIRECTORRUNTIME_API UCinematicParserComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCinematicParserComponent();

	UFUNCTION(BlueprintCallable)
	bool LoadScenario(FString JsonString);
	
	UFUNCTION(BlueprintPure, Category = "Cinematic")
	const TArray<FCinematicAction>& GetActions() const { return Actions; }

public:

	UPROPERTY()
	TArray<FCinematicAction> Actions;
    
	int32 CurrentIndex = 0;
	
};
