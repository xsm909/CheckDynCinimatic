#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CoreMinimal.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonWriter.h"
#include "Serialization/JsonSerializer.h"


#include "CalculationHelper.generated.h"


USTRUCT(BlueprintType, Blueprintable)
struct FShuttlecockPoint
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cinimatic")
	float Time;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cinimatic")
	FString Alias;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cinimatic")
	FString Type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cinimatic")
	FVector Position;
};

USTRUCT(BlueprintType, Blueprintable)
struct FSimState
{
	GENERATED_BODY()
	FVector Pos;
	FVector Vel;
};

constexpr float GRAVITY = -980.0f;           // см/с²
constexpr float AIR_DRAG = 0.0085f;          // коэффициент сопротивления (подбирается под ощущение)
constexpr float TERMINAL_VELOCITY = 600.0f;  // примерно реальная скорость падения воланчика

UCLASS()
class CINIMATICDIRECTORRUNTIME_API UCalculationHelper : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable, Category = "Cinimatic")
	static float CalculateTimeToTarget(const FVector& StartPosition, const FVector& TargetPosition,
								const FVector& InitialVelocity,
								float MaxSpeed, float MaxAcceleration, float BrakingDeceleration,
								float AcceptanceRadius);

	
	UFUNCTION(BlueprintCallable, Category = "Cinimatic")
	static bool SaveTrajectoryToFile(const FString& FileName, const TArray<FShuttlecockPoint>& KeyFrames, float TimeStep = 0.04f);
	
	/*
	
	
	UFUNCTION(BlueprintCallable, Category = "Cinimatic")
	static FString GenerateTrajectoryWithCalculatedRotation(const TArray<FShuttlecockPoint>& KeyFrames, float TimeStep = 0.04f);	
	
	
	static FVector SimulateShuttlecockPhysics(const FVector& StartPos, const FVector& InitialVelocity, float Time);
	static FVector GetVelocityAtTime(const FVector& InitialVel, float Time);
	static FVector CalculateInitialVelocityForSegment(const FVector& StartPos, const FVector& EndPos, float SegmentDuration);	
*/
	
	static  FVector CalculateInitialVelocityForSegment(
	const FVector& StartPos,
	const FVector& EndPos,
	float Time)
	{
		if (Time <= KINDA_SMALL_NUMBER)
		{
			return FVector::ZeroVector;
		}

		return FVector(
			(EndPos.X - StartPos.X) / Time,
			(EndPos.Y - StartPos.Y) / Time,
			(EndPos.Z - StartPos.Z - 0.5f * GRAVITY * Time * Time) / Time
		);
	}
	
	static  FVector GetVelocityAtTime(
	const FVector& InitialVelocity,
	float Time)
	{
		return FVector(
			InitialVelocity.X,
			InitialVelocity.Y,
			InitialVelocity.Z + GRAVITY * Time
		);
	}
	
	static FVector SimulateShuttlecockPhysics(
	const FVector& StartPos,
	const FVector& InitialVelocity,
	float Time)
	{
		return FVector(
			StartPos.X + InitialVelocity.X * Time,
			StartPos.Y + InitialVelocity.Y * Time,
			StartPos.Z + InitialVelocity.Z * Time + 0.5f * GRAVITY * Time * Time
		);
	}
	
	static FString GenerateTrajectoryWithCalculatedRotation(
    const TArray<FShuttlecockPoint>& KeyFrames,
    float TimeStep)
{
    if (KeyFrames.Num() < 2)
    {
        return TEXT("[]");
    }

    FString OutputString;

    TSharedRef<TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>> Writer =
        TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&OutputString);

    Writer->WriteArrayStart();

    const FString Alias =
        KeyFrames[0].Alias.IsEmpty() ? TEXT("Shuttlecock") : KeyFrames[0].Alias;

    FRotator LastRotation = FRotator::ZeroRotator;

    for (int32 i = 0; i < KeyFrames.Num() - 1; i++)
    {
        const FShuttlecockPoint& A = KeyFrames[i];
        const FShuttlecockPoint& B = KeyFrames[i + 1];

        float T = B.Time - A.Time;
        if (T <= KINDA_SMALL_NUMBER)
        {
            continue;
        }

        // если телепорт — просто вставляем точку
        if (B.Type == TEXT("teleport"))
        {
            Writer->WriteObjectStart();

            Writer->WriteValue(TEXT("Time"), B.Time);
            Writer->WriteValue(TEXT("Alias"), Alias);
            Writer->WriteValue(TEXT("Type"), TEXT("teleport"));

            Writer->WriteObjectStart(TEXT("VectorValue"));
            Writer->WriteValue(TEXT("X"), B.Position.X);
            Writer->WriteValue(TEXT("Y"), B.Position.Y);
            Writer->WriteValue(TEXT("Z"), B.Position.Z);
            Writer->WriteObjectEnd();

            Writer->WriteObjectStart(TEXT("RotatorValue"));
            Writer->WriteValue(TEXT("Pitch"), LastRotation.Pitch);
            Writer->WriteValue(TEXT("Yaw"), LastRotation.Yaw);
            Writer->WriteValue(TEXT("Roll"), LastRotation.Roll);
            Writer->WriteObjectEnd();

            Writer->WriteObjectEnd();
            continue;
        }

        // =========================
        //  БАЛЛИСТИКА (ТОЛЬКО g)
        // =========================

        FVector Delta = B.Position - A.Position;

        FVector V0;
        V0.X = Delta.X / T;
        V0.Y = Delta.Y / T;
        V0.Z = (Delta.Z - 0.5f * GRAVITY * T * T) / T;

        // =========================
        //  генерация траектории
        // =========================

        float LocalTime = 0.f;

        while (LocalTime < T)
        {
            FVector Pos;

            Pos.X = A.Position.X + V0.X * LocalTime;
            Pos.Y = A.Position.Y + V0.Y * LocalTime;
            Pos.Z = A.Position.Z + V0.Z * LocalTime + 0.5f * GRAVITY * LocalTime * LocalTime;

            FVector Vel;
            Vel.X = V0.X;
            Vel.Y = V0.Y;
            Vel.Z = V0.Z + GRAVITY * LocalTime;

            // =========================
            // rotation (волан вверх)
            // =========================

            FVector Forward = Vel.GetSafeNormal();
            FVector Up = FVector(0, 0, 1);

            if (FMath::Abs(FVector::DotProduct(Forward, Up)) > 0.98f)
            {
                Up = FVector(0, 1, 0);
            }

            FRotator Rot = FRotationMatrix::MakeFromXZ(Forward, Up).Rotator();
            LastRotation = Rot;

            // =========================
            // write JSON
            // =========================

            Writer->WriteObjectStart();

            Writer->WriteValue(TEXT("Time"), A.Time + LocalTime);
            Writer->WriteValue(TEXT("Alias"), Alias);
            Writer->WriteValue(TEXT("Type"), TEXT("transform_position"));

            Writer->WriteObjectStart(TEXT("VectorValue"));
            Writer->WriteValue(TEXT("X"), Pos.X);
            Writer->WriteValue(TEXT("Y"), Pos.Y);
            Writer->WriteValue(TEXT("Z"), Pos.Z);
            Writer->WriteObjectEnd();

            Writer->WriteObjectStart(TEXT("RotatorValue"));
            Writer->WriteValue(TEXT("Pitch"), Rot.Pitch);
            Writer->WriteValue(TEXT("Yaw"), Rot.Yaw);
            Writer->WriteValue(TEXT("Roll"), Rot.Roll);
            Writer->WriteObjectEnd();

            Writer->WriteObjectEnd();

            LocalTime += TimeStep;
        }

        // гарантируем точку B
        FVector FinalVel;
        FinalVel.X = V0.X;
        FinalVel.Y = V0.Y;
        FinalVel.Z = V0.Z + GRAVITY * T;

        FVector Forward = FinalVel.GetSafeNormal();
        FVector Up = FVector(0, 0, 1);

        if (FMath::Abs(FVector::DotProduct(Forward, Up)) > 0.98f)
        {
            Up = FVector(0, 1, 0);
        }

        LastRotation = FRotationMatrix::MakeFromXZ(Forward, Up).Rotator();

        Writer->WriteObjectStart();

        Writer->WriteValue(TEXT("Time"), B.Time);
        Writer->WriteValue(TEXT("Alias"), Alias);
        Writer->WriteValue(TEXT("Type"), TEXT("transform_position"));

        Writer->WriteObjectStart(TEXT("VectorValue"));
        Writer->WriteValue(TEXT("X"), B.Position.X);
        Writer->WriteValue(TEXT("Y"), B.Position.Y);
        Writer->WriteValue(TEXT("Z"), B.Position.Z);
        Writer->WriteObjectEnd();

        Writer->WriteObjectStart(TEXT("RotatorValue"));
        Writer->WriteValue(TEXT("Pitch"), LastRotation.Pitch);
        Writer->WriteValue(TEXT("Yaw"), LastRotation.Yaw);
        Writer->WriteValue(TEXT("Roll"), LastRotation.Roll);
        Writer->WriteObjectEnd();

        Writer->WriteObjectEnd();
    }

    Writer->WriteArrayEnd();
    Writer->Close();

    return OutputString;
}
};
