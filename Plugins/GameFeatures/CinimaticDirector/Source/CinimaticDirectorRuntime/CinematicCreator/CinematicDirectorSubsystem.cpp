#include "CinematicDirectorSubsystem.h"

#include "LevelSequenceActor.h"
#include "LevelSequencePlayer.h"

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


#include "AssetRegistry/AssetRegistryModule.h"
#include "Misc/PackageName.h"
#include "UObject/SavePackage.h"
#include "Misc/PackageName.h"
#include "Misc/FileHelper.h"

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

    // 3. Создание новой секвенции
    // Не вызываем Initialize(), так как мы подменим MovieScene
    ULevelSequence* NewSequence = NewObject<ULevelSequence>(TargetPackage, *AssetName, RF_Public | RF_Standalone | RF_Transactional);

    // 4. Безопасное копирование данных (MovieScene)
    UMovieScene* OldMovieScene = SourceSequence->GetMovieScene();
    
    // Используем параметры дублирования для корректного переноса ссылок
    FObjectDuplicationParameters Params(OldMovieScene, NewSequence);
    Params.DestName = OldMovieScene->GetFName();
    
    UMovieScene* ClonedMovieScene = Cast<UMovieScene>(StaticDuplicateObjectEx(Params));
    
    // Привязываем склонированную сцену к новой секвенции
    NewSequence->MovieScene = ClonedMovieScene;

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