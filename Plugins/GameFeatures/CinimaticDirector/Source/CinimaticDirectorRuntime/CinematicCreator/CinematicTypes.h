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