#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "CinematicCreator.h"
#include "CinematicDirectorSubsystem.generated.h"

UCLASS()
class CINIMATICDIRECTORRUNTIME_API UCinematicDirectorSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Cinematic")
	UCinematicCreator* CreateCinematic();

	UFUNCTION(BlueprintCallable, Category = "Cinematic")
	void DestroyCinematic(UCinematicCreator* Creator);

	UFUNCTION(BlueprintCallable, Category = "Cinematic")
	ALevelSequenceActor* PlayCinematicByIndex(int32 Index, FTransform SpawnTransform);
	
	UFUNCTION(BlueprintCallable, Category = "Cinematic")
	bool SaveCinematicByIndex(int32 Index, FString AssetName, FString PackagePath);

private:
	UPROPERTY()
	TArray<TObjectPtr<UCinematicCreator>> ActiveCinematics;
};