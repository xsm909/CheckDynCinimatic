#pragma once

#include "CoreMinimal.h"
#include "CinematicTypes.h"
#include "StructUtils/InstancedStruct.h"
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
	bool RegisterSpawnableSkeletalMeshActor(class USkeletalMesh* Mesh, FName Alias);

	UFUNCTION(BlueprintCallable, Category = "Cinematic")
	bool RegisterSpawnableStaticMeshActor(class UStaticMesh* Mesh, FName Alias);
	
	
	UFUNCTION(BlueprintCallable, Category = "Cinematic")
	void SetCinematicDuration(float DurationInSeconds);

	UFUNCTION(BlueprintCallable, Category = "Cinematic")
	void AddTransformKey(FName Alias, FTransform Transform, float Time, ECinematicInterpType Interp);

	UFUNCTION(BlueprintCallable, Category = "Cinematic|Variables")
	void AddFloatPropertyKey(FName Alias, FName PropertyName, float Value, float Time, ECinematicInterpType Interp);

	UFUNCTION(BlueprintCallable, Category = "Cinematic|Variables")
	void AddBoolPropertyKey(FName Alias, FName PropertyName, bool bValue, float Time);

	UFUNCTION(BlueprintCallable, Category = "Cinematic|Variables")
	void AddStringPropertyKey(FName Alias, FName PropertyName, const FString& Value, float Time);

	UFUNCTION(BlueprintCallable, Category = "Cinematic|Variables")
	void AddVectorPropertyKey(FName Alias, FName PropertyName, FVector Value, float Time, ECinematicInterpType Interp);

	UFUNCTION(BlueprintCallable, Category = "Cinematic|Variables")
	void AddRotatorPropertyKey(FName Alias, FName PropertyName, FRotator Value, float Time, ECinematicInterpType Interp);

	UFUNCTION(BlueprintPure, Category = "Cinematic|Helpers")
	static FString InstancedStructToString(const FInstancedStruct& InStruct);

	UFUNCTION(BlueprintPure, Category = "Cinematic|Helpers")
	static FInstancedStruct StringToInstancedStruct(const FString& InString);

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