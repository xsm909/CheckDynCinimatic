#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "LevelSequence.h"
#include "CinematicTypes_prot.h"
#include "Runtime/LevelSequence/Public/LevelSequenceActor.h"
#include "CinematicDirector_prot.generated.h"

UCLASS()
class CHECKDYNCINIMATIC_API UCinematicDirector_prot : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	// Главная функция генерации синематика
	UFUNCTION(BlueprintCallable, Category = "Cinematic")
	ULevelSequence* CreateSimpleCinematic(const TArray<FCinematicCommand>& Commands);
	
	UFUNCTION(BlueprintCallable, Category = "Cinematic")
	void PlayDynamicCinematic(ULevelSequence* InSequence);
	
	UFUNCTION(BlueprintCallable, Category = "Cinematic")
	bool SaveSequenceToAsset(ULevelSequence* Sequence, FString AssetName, FString PackagePath = TEXT("/Game/Cinematics"));
	

private:
	AActor* FindActorByTag(FName Tag) const;
	
	UPROPERTY()
	TObjectPtr<ALevelSequenceActor> OutActor;

	UPROPERTY()
	TObjectPtr<ULevelSequencePlayer> OutPlayer;
};