#include "CinematicDirectorSubsystem.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Misc/PackageName.h"
#include "UObject/SavePackage.h"
#include "Misc/PackageName.h"
#include "LevelSequenceActor.h"
#include "LevelSequencePlayer.h"

#if WITH_EDITOR
#include "Misc/FileHelper.h"
#endif

UCinematicCreator* UCinematicDirectorSubsystem::CreateCinematic()
{
	UCinematicCreator* NewCreator = NewObject<UCinematicCreator>(this);
	NewCreator->InitializeCreator();
	ActiveCinematics.Add(NewCreator);
	return NewCreator;
}

void UCinematicDirectorSubsystem::DestroyCinematic(UCinematicCreator* Creator)
{
	if (Creator)
	{
		ActiveCinematics.Remove(Creator);
		Creator->ConditionalBeginDestroy();
	}
}

ALevelSequenceActor* UCinematicDirectorSubsystem::PlayCinematicByIndex(int32 Index, FTransform SpawnTransform)
{
	if (!ActiveCinematics.IsValidIndex(Index))
	{
		UE_LOG(LogTemp, Warning, TEXT("CinematicDirector: Index %d out of bounds!"), Index);
		return nullptr;
	}

	UCinematicCreator* Creator = ActiveCinematics[Index];
	if (!Creator || !Creator->GetSequence()) return nullptr;

	
	
	// 1. Параметры спавна
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	// 2. Спавним актора-плеера
	ALevelSequenceActor* NewSequenceActor = GetWorld()->SpawnActor<ALevelSequenceActor>(
		ALevelSequenceActor::StaticClass(), 
		SpawnTransform, 
		SpawnParams
	);

	if (NewSequenceActor)
	{
		// 3. Настройка плеера
		NewSequenceActor->SetSequence(Creator->GetSequence());
        
		ULevelSequencePlayer* Player = NewSequenceActor->GetSequencePlayer();
		if (Player)
		{
			Player->Play();
		}
	}

	return NewSequenceActor;
}




bool UCinematicDirectorSubsystem::SaveCinematicByIndex(int32 Index, FString AssetName, FString PackagePath)
{
#if WITH_EDITOR
    if (!ActiveCinematics.IsValidIndex(Index)) return false;
    
    UCinematicCreator* Creator = ActiveCinematics[Index];
    ULevelSequence* SourceSequence = Creator ? Creator->GetSequence() : nullptr;
    
    if (!SourceSequence || !SourceSequence->GetMovieScene()) return false;

    // 1. Подготовка пути
    FString CleanPath = PackagePath.TrimStartAndEnd();
    if (CleanPath.IsEmpty()) CleanPath = TEXT("/Game/Cinematics");
    FString FullPackagePath = FPaths::Combine(CleanPath, AssetName);
    FString PhysicalFilePath = FPackageName::LongPackageNameToFilename(FullPackagePath, FPackageName::GetAssetPackageExtension());

    // 2. Создание или очистка пакета
    UPackage* TargetPackage = CreatePackage(*FullPackagePath);
    TargetPackage->FullyLoad(); // КРИТИЧНО: чтобы избежать "partially loaded"
    TargetPackage->SetFlags(RF_Public | RF_Standalone);

    // 3. Полное дублирование секвенции (вместе с MovieScene и всеми биндингами акторов)
    FObjectDuplicationParameters Params(SourceSequence, TargetPackage);
    Params.DestName = FName(*AssetName);
    // Убираем флаг Transient, чтобы ассет и его внутренние объекты могли сохраниться
    Params.FlagMask = RF_AllFlags & ~RF_Transient;
    Params.ApplyFlags = RF_Public | RF_Standalone | RF_Transactional;
    
    ULevelSequence* NewSequence = Cast<ULevelSequence>(StaticDuplicateObjectEx(Params));
    if (!NewSequence) return false;

    // 5. Финализация ассета
    NewSequence->MarkPackageDirty();
    FAssetRegistryModule::AssetCreated(NewSequence);
    NewSequence->PostEditChange();

    // 6. Сохранение
    FSavePackageArgs SaveArgs;
    SaveArgs.TopLevelFlags = RF_Public | RF_Standalone;
    SaveArgs.SaveFlags = SAVE_NoError; // Можно добавить SAVE_KeepGUID, если нужно сохранять ID
    
    bool bSaved = UPackage::SavePackage(TargetPackage, NewSequence, *PhysicalFilePath, SaveArgs);

    if (bSaved)
    {
        UE_LOG(LogTemp, Log, TEXT("Cinematic saved successfully: %s"), *PhysicalFilePath);
        return true;
    }

    return false;
#else
    return false;
#endif
}