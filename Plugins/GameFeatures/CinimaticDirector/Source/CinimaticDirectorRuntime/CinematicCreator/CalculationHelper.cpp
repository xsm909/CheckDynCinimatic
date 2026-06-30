// Fill out your copyright notice in the Description page of Project Settings.


#include "CalculationHelper.h"


float UCalculationHelper::CalculateTimeToTarget(
    const FVector& StartPosition,
    const FVector& TargetPosition,
    const FVector& InitialVelocity, // Если стоим, передаем FVector::ZeroVector
    float MaxSpeed,
    float MaxAcceleration,
    float BrakingDeceleration,
    float AcceptanceRadius = 5.0f)
{
    float TotalDistance = FVector::Dist(StartPosition, TargetPosition);
    
    if (TotalDistance <= AcceptanceRadius)
    {
        return 0.0f; 
    }

    // Если начальная скорость нулевая (стоим), считаем чистую физику разгона/торможения
    if (InitialVelocity.IsNearlyZero())
    {
        // 1. Находим дистанцию, необходимую для полного торможения с MaxSpeed до 0
        // Формула: S = V^2 / (2 * a)
        float BrakeDistanceForMaxSpeed = (MaxSpeed * MaxSpeed) / (2.0f * BrakingDeceleration);

        // 2. Проверяем, успеем ли мы вообще разогнаться до MaxSpeed на таком расстоянии
        float DistanceForFullSpeedTime = (MaxSpeed * MaxSpeed) / (2.0f * MaxAcceleration);
        
        if ((DistanceForFullSpeedTime + BrakeDistanceForMaxSpeed) <= TotalDistance)
        {
            // СЛУЧАЙ А: Дистанции хватает, чтобы выйти на максимальную скорость и подержать ее
            
            // Время разгона до MaxSpeed: t = V / a
            float TimeToAccelerate = MaxSpeed / MaxAcceleration;
            // Время торможения с MaxSpeed до 0: t = V / a_decel
            float TimeToBrake = MaxSpeed / BrakingDeceleration;
            
            // Расстояние, пройденное за время разгона и торможения
            float ExecutedDistance = DistanceForFullSpeedTime + BrakeDistanceForMaxSpeed;
            // Оставшийся кусок пути, который мы бежим на максимальной скорости
            float CruiseDistance = TotalDistance - ExecutedDistance;
            float TimeCruise = CruiseDistance / MaxSpeed;

            return TimeToAccelerate + TimeCruise + TimeToBrake;
        }
        else
        {
            // СЛУЧАЙ Б: Дистанция слишком коротка, мы начнем тормозить раньше, чем наберем MaxSpeed
            // Пиковая скорость, которую мы успеем развить: V_peak = sqrt( (2 * a_acc * a_dec * S) / (a_acc + a_dec) )
            float PeakSpeedSqr = (2.0f * MaxAcceleration * BrakingDeceleration * TotalDistance) / (MaxAcceleration + BrakingDeceleration);
            float PeakSpeed = FMath::Sqrt(PeakSpeedSqr);

            float TimeToAccelerate = PeakSpeed / MaxAcceleration;
            float TimeToBrake = PeakSpeed / BrakingDeceleration;

            return TimeToAccelerate + TimeToBrake;
        }
    }
    else
    {
        // СЛУЧАЙ В: Если мы уже двигались (есть InitialVelocity)
        // Для максимальной точности используем пошаговую симуляцию (как в прошлом шаге), 
        // но крутим цикл до тех пор, пока не достигнем точки, и возвращаем накопленный Time.
        
        float SimTime = 0.0f;
        FVector SimPos = StartPosition;
        FVector SimVel = InitialVelocity;
        float DeltaStep = 0.016f; // Считаем с шагом 60 кадров/сек для высокой точности
        
        // Предел безопасности, чтобы цикл не стал бесконечным, если проскочили точку
        int32 MaxIterations = 2000; 
        
        while (FVector::Dist(SimPos, TargetPosition) > AcceptanceRadius && MaxIterations > 0)
        {
            MaxIterations--;
            SimTime += DeltaStep;
            
            FVector TargetDir = (TargetPosition - SimPos).GetSafeNormal();
            
            // Простая логика торможения перед точкой: 
            // Если расстояние меньше тормозного пути для текущей скорости — тормозим
            float CurrentSpeed = SimVel.Size();
            float BrakingDist = (CurrentSpeed * CurrentSpeed) / (2.0f * BrakingDeceleration);
            
            FVector DesiredVelocity = (FVector::Dist(SimPos, TargetPosition) <= BrakingDist) 
                ? FVector::ZeroVector 
                : TargetDir * MaxSpeed;
                
            float CurrentAccelRate = (FVector::DotProduct(SimVel.GetSafeNormal(), TargetDir) < 0.0f || DesiredVelocity.IsZero()) 
                ? BrakingDeceleration 
                : MaxAcceleration;

            SimVel = FMath::VInterpTo(SimVel, DesiredVelocity, DeltaStep, CurrentAccelRate / MaxSpeed);
            SimPos += SimVel * DeltaStep;
        }
        
        return SimTime;
    }
}