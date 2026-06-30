#pragma once

#include "CoreMinimal.h"
#include "CinematicTypes.generated.h"

UENUM(BlueprintType)
enum class ECinematicInterpType : uint8
{
	Linear,
	Constant,
	Cubic
};

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