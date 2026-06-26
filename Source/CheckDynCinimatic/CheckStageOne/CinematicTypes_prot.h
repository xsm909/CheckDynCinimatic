#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CinematicTypes_prot.generated.h"

UENUM(BlueprintType)
enum class ECinematicAction : uint8
{
	Teleport, // Мгновенно выставить позицию (Time = 0 или точка старта)
	Move      // Интерполировать до точки за указанное время
};

USTRUCT(BlueprintType)
struct FCinematicCommand
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName TargetTag; // Тег для поиска актора на сцене (например, "SphereTarget")

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECinematicAction Action;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TimeOffset; // Сколько времени занимает ИЛИ в какой момент времени происходит

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTransform TargetTransform;
};