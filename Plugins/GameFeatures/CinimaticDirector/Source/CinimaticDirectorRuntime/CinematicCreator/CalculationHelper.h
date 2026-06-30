// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CalculationHelper.generated.h"

/**
 * 
 */
UCLASS()
class CINIMATICDIRECTORRUNTIME_API UCalculationHelper : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	float CalculateTimeToTarget(const FVector& StartPosition, const FVector& TargetPosition,
	                            const FVector& InitialVelocity,
	                            float MaxSpeed, float MaxAcceleration, float BrakingDeceleration,
	                            float AcceptanceRadius);
};
