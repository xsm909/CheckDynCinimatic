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



bool UCalculationHelper::SaveTrajectoryToFile(const FString& FileName, const TArray<FShuttlecockPoint>& KeyFrames, float TimeStep)
{
    // 1. Генерируем JSON-строку с помощью нашей предыдущей функции
    FString JsonContent = GenerateTrajectoryWithCalculatedRotation(KeyFrames, TimeStep);
    
    if (JsonContent.Equals(TEXT("[]")))
    {
        UE_LOG(LogTemp, Warning, TEXT("SaveTrajectoryToFile: Generated JSON is empty."));
        return false;
    }

    // 2. Формируем полный путь к файлу. 
    // FPaths::ProjectSavedDir() сохранит файл в папку проекта: YourProject/Saved/Trajectories/
    FString FullPath = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("Trajectories"), FileName);

    // 3. Используем FFileHelper для записи строки в файл
    // FFileHelper::EEncodingOptions::ForceUTF8 гарантирует, что не поедут спецсимволы и кодировка
    bool bIsSaved = FFileHelper::SaveStringToFile(JsonContent, *FullPath, FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM);

    if (bIsSaved)
    {
        UE_LOG(LogTemp, Log, TEXT("Траектория успешно сохранена в файл: %s"), *FullPath);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Не удалось сохранить файл по пути: %s"), *FullPath);
    }

    return bIsSaved;
}

/*

FString UCalculationHelper::GenerateTrajectoryWithCalculatedRotation(
    const TArray<FShuttlecockPoint>& KeyFrames, 
    float TimeStep)
{
    if (KeyFrames.Num() < 2) return TEXT("[]");

    FString OutputString;
    TSharedRef<TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>> Writer = 
        TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&OutputString);
    
    Writer->WriteArrayStart();

    const float TotalDuration = KeyFrames.Last().Time;
    float CurrentTime = KeyFrames[0].Time;
    FString AliasName = KeyFrames[0].Alias.IsEmpty() ? TEXT("Shuttlecock") : KeyFrames[0].Alias;

    FRotator LastValidRotation = FRotator::ZeroRotator;

    while (CurrentTime <= TotalDuration + KINDA_SMALL_NUMBER)
    {
        // Находим текущий сегмент
        int32 SegmentIdx = 0;
        while (SegmentIdx < KeyFrames.Num() - 1 && CurrentTime > KeyFrames[SegmentIdx + 1].Time)
            SegmentIdx++;

        const FShuttlecockPoint& P0 = KeyFrames[SegmentIdx];
        const FShuttlecockPoint& P1 = KeyFrames[FMath::Min(SegmentIdx + 1, KeyFrames.Num() - 1)];

        const float SegmentStart = P0.Time;
        const float SegmentDuration = P1.Time - P0.Time;

        FVector CalculatedPos = P0.Position;
        FString PointType = TEXT("transform_position");
        FRotator CalculatedRot = LastValidRotation;

        if (FMath::IsNearlyEqual(CurrentTime, P1.Time, TimeStep * 0.5f) && P1.Type == TEXT("teleport"))
        {
            CalculatedPos = P1.Position;
            PointType = TEXT("teleport");
        }
        else if (SegmentDuration > 0.001f)
        {
            float LocalTime = CurrentTime - SegmentStart;

            // Вычисляем начальную скорость сегмента
            FVector InitialVel = CalculateInitialVelocityForSegment(P0.Position, P1.Position, SegmentDuration);

            // Позиция через физику
            CalculatedPos = SimulateShuttlecockPhysics(P0.Position, InitialVel, LocalTime);

            // Скорость в текущий момент (для ротации)
            FVector CurrentVel = GetVelocityAtTime(InitialVel, LocalTime);

            if (!CurrentVel.IsNearlyZero(1.0f))
            {
                CalculatedRot = FRotationMatrix::MakeFromX(CurrentVel.GetSafeNormal()).Rotator();
                LastValidRotation = CalculatedRot;
            }
        }

        // === Запись в JSON ===
        Writer->WriteObjectStart();
        Writer->WriteValue(TEXT("Time"), CurrentTime);
        Writer->WriteValue(TEXT("Alias"), AliasName);
        Writer->WriteValue(TEXT("Type"), PointType);

        // Position
        Writer->WriteObjectStart(TEXT("VectorValue"));
        Writer->WriteValue(TEXT("X"), CalculatedPos.X);
        Writer->WriteValue(TEXT("Y"), CalculatedPos.Y);
        Writer->WriteValue(TEXT("Z"), CalculatedPos.Z);
        Writer->WriteObjectEnd();

        // Rotation
        Writer->WriteObjectStart(TEXT("RotatorValue"));
        Writer->WriteValue(TEXT("Pitch"), CalculatedRot.Pitch);
        Writer->WriteValue(TEXT("Yaw"), CalculatedRot.Yaw);
        Writer->WriteValue(TEXT("Roll"), CalculatedRot.Roll);
        Writer->WriteObjectEnd();

        Writer->WriteObjectEnd();

        CurrentTime += TimeStep;
    }

    Writer->WriteArrayEnd();
    Writer->Close();

    return OutputString;
}


FVector UCalculationHelper::SimulateShuttlecockPhysics(
    const FVector& StartPos, 
    const FVector& InitialVelocity, 
    float Time)
{
    if (Time <= 0.0f) return StartPos;

    // Простая численная интеграция (Euler + небольшое сопротивление)
    const int32 Steps = FMath::Max(4, FMath::CeilToInt(Time * 60.0f)); // ~60 FPS
    const float dt = Time / Steps;

    FVector Pos = StartPos;
    FVector Vel = InitialVelocity;

    for (int32 i = 0; i < Steps; ++i)
    {
        float Speed = Vel.Size();
        FVector DragForce = -Vel.GetSafeNormal() * AIR_DRAG * Speed * Speed;

        FVector Acceleration = FVector(0, 0, GRAVITY) + DragForce;

        Vel += Acceleration * dt;
        Pos += Vel * dt;
    }

    return Pos;
}

FVector UCalculationHelper::GetVelocityAtTime(const FVector& InitialVel, float Time)
{
    if (Time <= 0.0f)
        return InitialVel;

    const float dt = 0.016f;
    FVector Vel = InitialVel;
    float t = 0.0f;

    while (t < Time)
    {
        float Speed = Vel.Size();
        FVector Drag = -Vel.GetSafeNormal() * AIR_DRAG * Speed * Speed;

        FVector Accel = FVector(0.0f, 0.0f, GRAVITY) + Drag;
        Vel += Accel * dt;
        t += dt;
    }

    return Vel;
}

FVector UCalculationHelper::CalculateInitialVelocityForSegment(
    const FVector& StartPos, 
    const FVector& EndPos, 
    float SegmentDuration)
{
    if (SegmentDuration <= 0.001f)
    {
        return FVector::ZeroVector;
    }

    FVector Delta = EndPos - StartPos;
    float HorizontalDist = FVector(Delta.X, Delta.Y, 0.0f).Size();
    float HeightDiff = Delta.Z;

    // Горизонтальная составляющая
    float VHorizontal = HorizontalDist / SegmentDuration;

    // Вертикальная составляющая (учитываем гравитацию)
    // Формула: Vz = (Δz / t) + (g * t)/2
    float Vz = (HeightDiff / SegmentDuration) + (-GRAVITY * SegmentDuration) * 0.5f;

    FVector InitialVel = FVector::ZeroVector;

    if (HorizontalDist > 5.0f) // есть горизонтальное движение
    {
        FVector HorizDir = FVector(Delta.X, Delta.Y, 0.0f).GetSafeNormal();
        InitialVel = HorizDir * VHorizontal + FVector(0, 0, Vz);
    }
    else
    {
        // Почти вертикальный бросок
        InitialVel = FVector(0, 0, Vz);
    }

    // Ограничение максимальной скорости (реалистично для воланчика)
    const float MaxLaunchSpeed = 2500.0f; // см/с
    if (InitialVel.Size() > MaxLaunchSpeed)
    {
        InitialVel = InitialVel.GetSafeNormal() * MaxLaunchSpeed;
    }

    return InitialVel;
}*/

