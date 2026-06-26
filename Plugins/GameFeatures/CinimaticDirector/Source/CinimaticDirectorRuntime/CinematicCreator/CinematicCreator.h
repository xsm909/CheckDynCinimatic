#pragma once

#include "CoreMinimal.h"
#include "CinematicTypes.h"
#include "LevelSequence.h"
#include "CinematicCreator.generated.h"

UCLASS(BlueprintType)
class CINIMATICDIRECTORRUNTIME_API UCinematicCreator : public UObject
{
	GENERATED_BODY()

public:
	void InitializeCreator();

	// Регистрация уже существующего актора (Possessable)
	UFUNCTION(BlueprintCallable, Category = "Cinematic")
	bool RegisterPossessableActor(AActor* Actor, FName Alias);

	// Регистрация актора, который будет создан синематиком (Spawnable)
	UFUNCTION(BlueprintCallable, Category = "Cinematic")
	bool RegisterSpawnableActor(TSubclassOf<AActor> ActorClass, FName Alias);
	
	
	UFUNCTION(BlueprintCallable, Category = "Cinematic")
	void SetCinematicDuration(float DurationInSeconds);

	UFUNCTION(BlueprintCallable, Category = "Cinematic")
	void AddTransformKey(FName Alias, FTransform Transform, float Time, ECinematicInterpType Interp);
	void UpdatePlaybackRange();

	UFUNCTION(BlueprintCallable, Category = "Cinematic")
	void FlushChanges();
	
	UFUNCTION(BlueprintPure, Category = "Cinematic")
	ULevelSequence* GetSequence() const { return Sequence; }
	

private:
	UPROPERTY()
	ULevelSequence* Sequence;

	TMap<FName, FGuid> RegisteredActors;
};