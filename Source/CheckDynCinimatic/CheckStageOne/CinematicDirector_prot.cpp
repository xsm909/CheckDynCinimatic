#include "CinematicDirector_prot.h"
#include "Kismet/GameplayStatics.h"
#include "MovieScene.h"
#include "Tracks/MovieScene3DTransformTrack.h"
#include "Sections/MovieScene3DTransformSection.h"
#include "Channels/MovieSceneFloatChannel.h"
#include "Runtime/LevelSequence/Public/LevelSequencePlayer.h"
#include "Sections/MovieScene3DTransformSection.h" 
#include "Channels/MovieSceneChannelProxy.h"
#include "Channels/MovieSceneFloatChannel.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "UObject/SavePackage.h"
#include "Misc/PackageName.h"
#include "FileHelpers.h"
#include "AssetToolsModule.h"
#include "AssetToolsModule.h"
#include "FileHelpers.h"
#include "AssetToolsModule.h"
#include "FileHelpers.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "CinematicDirector_prot.h"
#include "MovieScene.h"
#include "FileHelpers.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Misc/FileHelper.h"
#include "UnrealExporter.h"
#include "Misc/StringOutputDevice.h"

AActor* UCinematicDirector_prot::FindActorByTag(FName Tag) const
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), Tag, FoundActors);
	return FoundActors.Num() > 0 ? FoundActors[0] : nullptr;
}

void UCinematicDirector_prot::PlayDynamicCinematic(ULevelSequence* InSequence)
{
	if (!InSequence) return;

	// 1. Спавним LevelSequenceActor на сцене. Он нужен как проводник между кодом и миром игры.
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	
	OutActor = GetWorld()->SpawnActor<ALevelSequenceActor>(ALevelSequenceActor::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
	
	if (OutActor)
	{
		// 2. Инициализируем плеер внутри актора. Передаем настройки (например, выключаем автостарт, так как запустим сами)
		FMovieSceneSequencePlaybackSettings Settings;
		Settings.bAutoPlay = false;
		Settings.LoopCount.Value = 0; // 0 - проиграть 1 раз, -1 - бесконечный цикл
		Settings.bPauseAtEnd = true;  // Замрать на последнем кадре

		// SetSequence автоматически создает внутренний ULevelSequencePlayer
		OutActor->PlaybackSettings = Settings;
		OutActor->SetSequence(InSequence);
		
		OutPlayer = OutActor->GetSequencePlayer();
		
		if (OutPlayer)
		{
			// 3. Поехали!
			OutPlayer->Play();
			UE_LOG(LogTemp, Log, TEXT("CinematicDirector: Dynamic sequence started playing successfully."));
		}
	}
}

ULevelSequence* UCinematicDirector_prot::CreateSimpleCinematic(const TArray<FCinematicCommand>& Commands)
{
    if (Commands.Num() == 0) return nullptr;

    // 1. Создаем Transient (временный) Level Sequence в оперативной памяти
    ULevelSequence* NewSequence = NewObject<ULevelSequence>(GetTransientPackage(), ULevelSequence::StaticClass(), NAME_None, RF_Transient);
    if (!NewSequence) return nullptr;

    UMovieScene* MovieScene = NewSequence->GetMovieScene();
    if (!MovieScene)
    {
       NewSequence->Initialize(); 
       MovieScene = NewSequence->GetMovieScene();
    }

    if (!MovieScene)
    {
       UE_LOG(LogTemp, Error, TEXT("CinematicDirector: Failed to initialize MovieScene!"));
       return nullptr;
    }
    
    FFrameRate TickResolution = MovieScene->GetTickResolution();
    
    AActor* TargetActor = FindActorByTag(Commands[0].TargetTag);
    if (!TargetActor)
    {
       UE_LOG(LogTemp, Error, TEXT("CinematicDirector: Actor with tag %s not found!"), *Commands[0].TargetTag.ToString());
       return nullptr;
    }

    // 2. Registrate Actor as Possessable
	FGuid ActorGuid = MovieScene->AddPossessable(TargetActor->GetActorLabel(), TargetActor->GetClass());
    NewSequence->BindPossessableObject(ActorGuid, *TargetActor, GetWorld());

    // 3. Создаем Transform Трек и Секцию
    UMovieScene3DTransformTrack* TransformTrack = MovieScene->AddTrack<UMovieScene3DTransformTrack>(ActorGuid);
    if (!TransformTrack) return nullptr;

    UMovieScene3DTransformSection* TransformSection = Cast<UMovieScene3DTransformSection>(TransformTrack->CreateNewSection());
    if (!TransformSection) return nullptr;

    // Включаем маску на Location (Translation) и Rotation (Scale отключаем, чтобы не забивать память)
    EMovieSceneTransformChannel Mask = EMovieSceneTransformChannel::TranslationX | 
                                       EMovieSceneTransformChannel::TranslationY | 
                                       EMovieSceneTransformChannel::TranslationZ |
                                       EMovieSceneTransformChannel::RotationX | 
                                       EMovieSceneTransformChannel::RotationY | 
                                       EMovieSceneTransformChannel::RotationZ;
    TransformSection->SetMask(Mask);

    TransformTrack->AddSection(*TransformSection);
    TransformSection->SetRange(TRange<FFrameNumber>::All());

     
    // Запрашиваем Double-каналы. В UE5 маска TranslationXYZ + RotationXYZ генерирует ровно 6 Double-каналов.
    FMovieSceneChannelProxy& ChannelProxy = TransformSection->GetChannelProxy();
    
    FMovieSceneDoubleChannel* RawX     = ChannelProxy.GetChannel<FMovieSceneDoubleChannel>(0);
    FMovieSceneDoubleChannel* RawY     = ChannelProxy.GetChannel<FMovieSceneDoubleChannel>(1);
    FMovieSceneDoubleChannel* RawZ     = ChannelProxy.GetChannel<FMovieSceneDoubleChannel>(2);
    FMovieSceneDoubleChannel* RawRoll  = ChannelProxy.GetChannel<FMovieSceneDoubleChannel>(3);
    FMovieSceneDoubleChannel* RawPitch = ChannelProxy.GetChannel<FMovieSceneDoubleChannel>(4);
    FMovieSceneDoubleChannel* RawYaw   = ChannelProxy.GetChannel<FMovieSceneDoubleChannel>(5);

    // Проверяем, что все каналы успешно получены
    if (!RawX || !RawY || !RawZ || !RawRoll || !RawPitch || !RawYaw)
    {
        UE_LOG(LogTemp, Error, TEXT("CinematicDirector: Failed to resolve Double channels! Check if Mask matches."));
        return nullptr;
    }

    float CurrentSequenceTime = 0.0f;

    // 4. Итерируемся по командам и забиваем ключи
    for (const FCinematicCommand& Cmd : Commands)
    {
       if (Cmd.Action == ECinematicAction::Teleport)
       {
          CurrentSequenceTime = Cmd.TimeOffset; 
       }
       else if (Cmd.Action == ECinematicAction::Move)
       {
          CurrentSequenceTime += Cmd.TimeOffset;
       }

       FFrameTime FrameTime = CurrentSequenceTime * TickResolution;
       FVector Location = Cmd.TargetTransform.GetLocation();
       FRotator Rotation = Cmd.TargetTransform.Rotator();
       FFrameNumber TargetFrameNumber = FrameTime.FrameNumber;

       // Записываем данные типа double (FVector/FRotator в UE5 автоматически кастятся к double)
       RawX->AddLinearKey(TargetFrameNumber, Location.X);
       RawY->AddLinearKey(TargetFrameNumber, Location.Y);
       RawZ->AddLinearKey(TargetFrameNumber, Location.Z);
       
       RawRoll->AddLinearKey(TargetFrameNumber, Rotation.Roll);
       RawPitch->AddLinearKey(TargetFrameNumber, Rotation.Pitch);
       RawYaw->AddLinearKey(TargetFrameNumber, Rotation.Yaw);
    }

    // 5. Финализируем границы таймлайна в MovieScene
    FFrameNumber StartFrame(0);
    FFrameNumber TotalFrames = (CurrentSequenceTime * TickResolution).FrameNumber;
    
    int32 Duration = TotalFrames.Value - StartFrame.Value; 
    if (Duration < 1) 
    {
        Duration = 1;
    }

    MovieScene->SetPlaybackRange(StartFrame, Duration, true);

    return NewSequence;
}


bool UCinematicDirector_prot::SaveSequenceToAsset(ULevelSequence* Sequence, FString AssetName, FString PackagePath)
{
#if WITH_EDITOR
    if (!Sequence || !Sequence->GetMovieScene())
    {
        UE_LOG(LogTemp, Error, TEXT("SaveSequenceToAsset: Sequence or MovieScene is null!"));
        return false;
    }

    // 1. Нормализуем пути к контенту проекта
    FString CleanPath = PackagePath.TrimStartAndEnd();
    if (CleanPath.IsEmpty()) CleanPath = TEXT("/Game/Cinematics");
    if (!CleanPath.StartsWith(TEXT("/")))    CleanPath = TEXT("/") + CleanPath;
    if (!CleanPath.StartsWith(TEXT("/Game"))) CleanPath = TEXT("/Game") + CleanPath;

    FString FullPackagePath = FPaths::Combine(*CleanPath, *AssetName);
    FPackageName::TryConvertLongPackageNameToFilename(FullPackagePath, FullPackagePath); 
    FullPackagePath = FPackageName::FilenameToLongPackageName(FullPackagePath);

    FString PhysicalFilePath = FPackageName::LongPackageNameToFilename(FullPackagePath, FPackageName::GetAssetPackageExtension());
    PhysicalFilePath = FPaths::ConvertRelativePathToFull(PhysicalFilePath);

    // 2. Ищем и зачищаем старый пакет в памяти
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

    if (!TargetPackage)
    {
        UE_LOG(LogTemp, Error, TEXT("SaveSequenceToAsset: Failed to allocate TargetPackage."));
        return false;
    }

    TargetPackage->SetFlags(RF_Public | RF_Standalone);

    // 3. СОЗДАЕМ ЧИСТУЮ СЕКВЕНЦИЮ СРАЗУ В ПАКЕТЕ ПРОЕКТА
    ULevelSequence* NewSequence = NewObject<ULevelSequence>(TargetPackage, *AssetName, RF_Public | RF_Standalone | RF_Transactional);
    if (!NewSequence)
    {
        UE_LOG(LogTemp, Error, TEXT("SaveSequenceToAsset: Failed to allocate NewSequence."));
        return false;
    }

    // Инициализируем базовую MovieScene внутри новой секвенции
    NewSequence->Initialize(); 

    // 4. КОПИРУЕМ ДАННЫЕ МЕТОДОМ ДУБЛИРОВАНИЯ СТРУКТУРЫ (БЕЗ РАНТАЙМ ПЛЕЕРА)
    if (NewSequence->GetMovieScene())
    {
        // Клонируем только MovieScene из исходного синематика прямо в наш новый ассет
        UMovieScene* ClonedMovieScene = Cast<UMovieScene>(StaticDuplicateObject(Sequence->GetMovieScene(), NewSequence));
        if (ClonedMovieScene)
        {
            // Подменяем дефолтную пустую сцену на наш чистый клон со всеми треками
            NewSequence->MovieScene = ClonedMovieScene; 
        }
    }

    // Выставляем редакторы метаданных
    TargetPackage->MarkPackageDirty();
    NewSequence->MarkPackageDirty();
    NewSequence->PostEditChange();

    // 5. Регистрируем в Asset Registry
    FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
    AssetRegistryModule.Get().AssetCreated(NewSequence);

    // 6. НИЗКОУРОВНЕВОЕ СОХРАНЕНИЕ НА ДИСК
    FSavePackageArgs SaveArgs;
    SaveArgs.TopLevelFlags = RF_Public | RF_Standalone;
    SaveArgs.SaveFlags = SAVE_None;
    SaveArgs.Error = GLog;

    bool bSavedOnDisk = UPackage::SavePackage(TargetPackage, NewSequence, *PhysicalFilePath, SaveArgs);

    if (bSavedOnDisk)
    {
        TArray<FAssetData> SavedAssetsData;
        SavedAssetsData.Add(FAssetData(NewSequence));
        AssetRegistryModule.Get().AssetsSaved(MoveTemp(SavedAssetsData));
        
        TArray<FString> PathsToScan;
        PathsToScan.Add(CleanPath); 
        AssetRegistryModule.Get().ScanPathsSynchronous(PathsToScan, true);

        if (IFileManager::Get().FileExists(*PhysicalFilePath))
        {
            UE_LOG(LogTemp, Log, TEXT("!!! SUCCESS !!! FILE PHYSICALLY GENERATED ON DISK: %s"), *PhysicalFilePath);
            return true;
        }
    }

    UE_LOG(LogTemp, Error, TEXT("SaveSequenceToAsset: Save failed. Pipeline still blocked."));
    return false;
#else
    return false;
#endif
    return false;
}