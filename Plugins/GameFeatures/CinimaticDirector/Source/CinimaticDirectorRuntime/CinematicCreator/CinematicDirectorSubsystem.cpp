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
    ULevelSequence* Sequence = Creator ? Creator->GetSequence() : nullptr;
    
    if (!Sequence || !Sequence->GetMovieScene())
    {
        UE_LOG(LogTemp, Error, TEXT("SaveCinematicByIndex: Sequence or MovieScene is null!"));
        return false;
    }

    // 1. Нормализация путей
    FString CleanPath = PackagePath.TrimStartAndEnd();
    if (CleanPath.IsEmpty()) CleanPath = TEXT("/Game/Cinematics");
    if (!CleanPath.StartsWith(TEXT("/"))) CleanPath = TEXT("/") + CleanPath;
    if (!CleanPath.StartsWith(TEXT("/Game"))) CleanPath = TEXT("/Game") + CleanPath;

    FString FullPackagePath = FPaths::Combine(*CleanPath, *AssetName);
    FString PhysicalFilePath = FPackageName::LongPackageNameToFilename(FullPackagePath, FPackageName::GetAssetPackageExtension());
    PhysicalFilePath = FPaths::ConvertRelativePathToFull(PhysicalFilePath);

    // 2. Работа с пакетом
    UPackage* TargetPackage = FindPackage(nullptr, *FullPackagePath);
    if (TargetPackage)
    {
        UObject* OldAsset = FindObject<UObject>(TargetPackage, *AssetName);
        if (OldAsset)
        {
            FString TrashName = FString::Printf(TEXT("OLD_%s_%s"), *AssetName, *FGuid::NewGuid().ToString());
            OldAsset->Rename(*TrashName, GetTransientPackage(), REN_DontCreateRedirectors);
        }
    }
    else
    {
        TargetPackage = CreatePackage(*FullPackagePath);
    }

    TargetPackage->SetFlags(RF_Public | RF_Standalone);

    // 3. Создание новой секвенции в пакете
    ULevelSequence* NewSequence = NewObject<ULevelSequence>(TargetPackage, *AssetName, RF_Public | RF_Standalone | RF_Transactional);
    NewSequence->Initialize(); 

	// 4. КОПИРУЕМ ДАННЫЕ БЕЗОПАСНО
	if (NewSequence->GetMovieScene())
	{
		// Вместо StaticDuplicateObject используем создание копии через копирование свойств
		// Это предотвращает крэши из-за связей с "мертвыми" объектами
		UMovieScene* OldMovieScene = Sequence->GetMovieScene();
    
		// Дублируем MovieScene в новый пакет
		UMovieScene* ClonedMovieScene = DuplicateObject<UMovieScene>(OldMovieScene, NewSequence, *OldMovieScene->GetName());
    
		// ПРИНУДИТЕЛЬНО ПЕРЕПРИВЯЗЫВАЕМ СЕКВЕНЦИЮ К НОВОЙ СЦЕНЕ
		NewSequence->MovieScene = ClonedMovieScene; 
    
		// ЭТОТ ШАГ КРИТИЧЕН: Если объект Spawnable, нужно обновить все ссылки внутри
		// Иначе при сохранении движок крашится, пытаясь сериализовать указатель на старый объект
		ClonedMovieScene->Rename(*OldMovieScene->GetName(), NewSequence);
	}
	
    NewSequence->MarkPackageDirty();
    NewSequence->PostEditChange();

    // 5. Сохранение
    FSavePackageArgs SaveArgs;
    SaveArgs.TopLevelFlags = RF_Public | RF_Standalone;
    SaveArgs.SaveFlags = SAVE_None;
    
    bool bSavedOnDisk = UPackage::SavePackage(TargetPackage, NewSequence, *PhysicalFilePath, SaveArgs);

    if (bSavedOnDisk)
    {
        FAssetRegistryModule::AssetCreated(NewSequence);
        UE_LOG(LogTemp, Log, TEXT("!!! SUCCESS !!! FILE GENERATED: %s"), *PhysicalFilePath);
        return true;
    }

    return false;
#else
    return false;
#endif
}