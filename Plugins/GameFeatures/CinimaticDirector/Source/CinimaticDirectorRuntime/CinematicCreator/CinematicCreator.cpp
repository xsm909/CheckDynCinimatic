#include "CinematicCreator.h"
#include "MovieScene.h"
#include "Tracks/MovieScene3DTransformTrack.h"
#include "Sections/MovieScene3DTransformSection.h"
#include "Channels/MovieSceneFloatChannel.h"
#include "Tracks/MovieSceneSpawnTrack.h"
#include "Sections/MovieSceneSpawnSection.h"
#include "Animation/SkeletalMeshActor.h"
#include "Engine/StaticMeshActor.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Tracks/MovieSceneDoubleTrack.h"
#include "Sections/MovieSceneDoubleSection.h"
#include "Channels/MovieSceneDoubleChannel.h"
#include "Tracks/MovieSceneFloatTrack.h"
#include "Sections/MovieSceneFloatSection.h"
#include "Channels/MovieSceneFloatChannel.h"
#include "Tracks/MovieSceneBoolTrack.h"
#include "Sections/MovieSceneBoolSection.h"
#include "Channels/MovieSceneBoolChannel.h"
#include "Tracks/MovieSceneStringTrack.h"
#include "Channels/MovieSceneStringChannel.h"
#include "Tracks/MovieSceneVectorTrack.h"
#include "Tracks/MovieSceneRotatorTrack.h"
#include "JsonObjectConverter.h"
#include "Serialization/JsonSerializer.h"

void UCinematicCreator::InitializeCreator()
{
    Sequence = NewObject<ULevelSequence>(this, NAME_None, RF_Transient);
    Sequence->Initialize();
}

bool UCinematicCreator::RegisterPossessableActor(AActor* Actor, FName Alias)
{
    if (!Actor || !Sequence) return false;
    UMovieScene* MovieScene = Sequence->GetMovieScene();
    FString ActorName = Actor->GetName();
    FGuid ActorGuid = MovieScene->AddPossessable(ActorName, Actor->GetClass());
    Sequence->BindPossessableObject(ActorGuid, *Actor, GetWorld());
    RegisteredActors.Add(Alias, ActorGuid);
    return true;
}



bool UCinematicCreator::RegisterSpawnableActor(TSubclassOf<AActor> ActorClass, FName Alias)
{
    if (!ActorClass || !Sequence) return false;

    UMovieScene* MovieScene = Sequence->GetMovieScene();
    
    // 1. Создаем временный объект-шаблон (Template)
    // НЕ используем RF_Transient, так как MovieScene::AddSpawnable скопирует этот флаг на внутренний шаблон,
    // и тогда актор не сохранится в ассете и может быть уничтожен GC в рантайме.
    AActor* SpawnTemplate = NewObject<AActor>(GetTransientPackage(), ActorClass, NAME_None);
    
    if (!SpawnTemplate) return false;

    // 2. Добавляем Spawnable через шаблон
    FGuid ActorGuid = MovieScene->AddSpawnable(Alias.ToString(), *SpawnTemplate);
    
    if (ActorGuid.IsValid())
    {
        // 3. Добавляем трек спавна, чтобы актор гарантированно спавнился в рантайме
        UMovieSceneSpawnTrack* SpawnTrack = MovieScene->AddTrack<UMovieSceneSpawnTrack>(ActorGuid);
        if (SpawnTrack)
        {
            UMovieSceneSpawnSection* SpawnSection = Cast<UMovieSceneSpawnSection>(SpawnTrack->CreateNewSection());
            if (SpawnSection)
            {
                SpawnSection->SetRange(TRange<FFrameNumber>::All());
                SpawnTrack->AddSection(*SpawnSection);
            }
        }

        RegisteredActors.Add(Alias, ActorGuid);
        return true;
    }
    
    return false;
}

bool UCinematicCreator::RegisterSpawnableSkeletalMeshActor(USkeletalMesh* Mesh, FName Alias)
{
    if (!Mesh || !Sequence) return false;

    UMovieScene* MovieScene = Sequence->GetMovieScene();
    
    ASkeletalMeshActor* SpawnTemplate = NewObject<ASkeletalMeshActor>(GetTransientPackage(), ASkeletalMeshActor::StaticClass(), NAME_None);
    if (!SpawnTemplate) return false;

    if (SpawnTemplate->GetSkeletalMeshComponent())
    {
        SpawnTemplate->GetSkeletalMeshComponent()->SetSkeletalMesh(Mesh);
    }

    FGuid ActorGuid = MovieScene->AddSpawnable(Alias.ToString(), *SpawnTemplate);
    
    if (ActorGuid.IsValid())
    {
        UMovieSceneSpawnTrack* SpawnTrack = MovieScene->AddTrack<UMovieSceneSpawnTrack>(ActorGuid);
        if (SpawnTrack)
        {
            UMovieSceneSpawnSection* SpawnSection = Cast<UMovieSceneSpawnSection>(SpawnTrack->CreateNewSection());
            if (SpawnSection)
            {
                SpawnSection->SetRange(TRange<FFrameNumber>::All());
                SpawnTrack->AddSection(*SpawnSection);
            }
        }

        RegisteredActors.Add(Alias, ActorGuid);
        return true;
    }
    
    return false;
}


bool UCinematicCreator::RegisterSpawnableStaticMeshActor(UStaticMesh* Mesh, FName Alias)
{
    if (!Mesh || !Sequence) return false;

    UMovieScene* MovieScene = Sequence->GetMovieScene();
    
    AStaticMeshActor* SpawnTemplate = NewObject<AStaticMeshActor>(GetTransientPackage(), AStaticMeshActor::StaticClass(), NAME_None);
    if (!SpawnTemplate) return false;

    if (SpawnTemplate->GetStaticMeshComponent())
    {
        SpawnTemplate->GetStaticMeshComponent()->SetStaticMesh(Mesh);
    }

    FGuid ActorGuid = MovieScene->AddSpawnable(Alias.ToString(), *SpawnTemplate);
    
    if (ActorGuid.IsValid())
    {
        UMovieSceneSpawnTrack* SpawnTrack = MovieScene->AddTrack<UMovieSceneSpawnTrack>(ActorGuid);
        if (SpawnTrack)
        {
            UMovieSceneSpawnSection* SpawnSection = Cast<UMovieSceneSpawnSection>(SpawnTrack->CreateNewSection());
            if (SpawnSection)
            {
                SpawnSection->SetRange(TRange<FFrameNumber>::All());
                SpawnTrack->AddSection(*SpawnSection);
            }
        }

        RegisteredActors.Add(Alias, ActorGuid);
        return true;
    }
    
    return false;
}

void UCinematicCreator::SetCinematicDuration(float DurationInSeconds)
{
    if (!Sequence || !Sequence->GetMovieScene()) return;

    UMovieScene* MovieScene = Sequence->GetMovieScene();
    FFrameRate TickResolution = MovieScene->GetTickResolution();
    
    FFrameTime EndFrameTime = DurationInSeconds * TickResolution;
    FFrameNumber EndFrame = EndFrameTime.FrameNumber;
    TRange<FFrameNumber> NewRange = TRange<FFrameNumber>(FFrameNumber(0), EndFrame);

    // 1. Устанавливаем рабочий диапазон воспроизведения
    MovieScene->SetPlaybackRange(NewRange);

    // 2. КРИТИЧНО: Устанавливаем диапазон просмотра (Working Range)
    // Именно он часто ограничивает плейбек в редакторе, если он меньше PlaybackRange
    MovieScene->SetWorkingRange(0, 1000);
    

    // 3. Уведомляем систему об изменениях
    MovieScene->Modify();
    Sequence->Modify();
    
    // Дополнительно: принудительное обновление для плеера
#if WITH_EDITOR
    MovieScene->PostEditChange();
#endif
}

void UCinematicCreator::AddTransformKey(FName Alias, FTransform Transform, float Time, ECinematicInterpType Interp, bool bLimitSectionToKeys)
{
    FGuid* ActorGuid = RegisteredActors.Find(Alias);
    if (!ActorGuid || !Sequence || !Sequence->GetMovieScene()) return;

    UMovieScene* MovieScene = Sequence->GetMovieScene();
    
    // Получаем или создаем трек трансформа
    UMovieScene3DTransformTrack* Track = MovieScene->FindTrack<UMovieScene3DTransformTrack>(*ActorGuid);
    if (!Track) 
    {
        Track = MovieScene->AddTrack<UMovieScene3DTransformTrack>(*ActorGuid);
    }

    // Получаем или создаем секцию
    UMovieScene3DTransformSection* Section = nullptr;
    if (Track->GetAllSections().Num() > 0)
    {
        Section = Cast<UMovieScene3DTransformSection>(Track->GetAllSections()[0]);
    }
    else
    {
        Section = Cast<UMovieScene3DTransformSection>(Track->CreateNewSection());
        Track->AddSection(*Section);
        if (bLimitSectionToKeys)
        {
            Section->SetRange(TRange<FFrameNumber>::Empty());
        }
        else
        {
            Section->SetRange(TRange<FFrameNumber>::All());
        }
    }

    if (!Section) return;

    // Вычисляем кадр
    FFrameRate TickResolution = MovieScene->GetTickResolution();
    FFrameNumber FrameNumber = (Time * TickResolution).FrameNumber;

    if (bLimitSectionToKeys)
    {
        // Обновляем диапазон секции, чтобы он покрывал только ключи (включительно!)
        TRange<FFrameNumber> CurrentRange = Section->GetRange();
        if (CurrentRange.IsEmpty() || CurrentRange == TRange<FFrameNumber>::All())
        {
            Section->SetRange(TRange<FFrameNumber>(
                TRangeBound<FFrameNumber>::Inclusive(FrameNumber), 
                TRangeBound<FFrameNumber>::Inclusive(FrameNumber)
            ));
        }
        else
        {
            FFrameNumber Lower = FMath::Min(CurrentRange.GetLowerBoundValue(), FrameNumber);
            FFrameNumber Upper = FMath::Max(CurrentRange.GetUpperBoundValue(), FrameNumber);
            Section->SetRange(TRange<FFrameNumber>(
                TRangeBound<FFrameNumber>::Inclusive(Lower), 
                TRangeBound<FFrameNumber>::Inclusive(Upper)
            ));
        }
    }
    else
    {
        Section->SetRange(TRange<FFrameNumber>::All());
    }

    // Подготавливаем значения (включая масштаб)
    double Values[9] = { 
        Transform.GetLocation().X, Transform.GetLocation().Y, Transform.GetLocation().Z,
        Transform.Rotator().Roll, Transform.Rotator().Pitch, Transform.Rotator().Yaw,
        Transform.GetScale3D().X, Transform.GetScale3D().Y, Transform.GetScale3D().Z 
    };

    // Определяем тип интерполяции
    ERichCurveInterpMode CurveInterp = ERichCurveInterpMode::RCIM_Linear;
    if (Interp == ECinematicInterpType::Constant) CurveInterp = ERichCurveInterpMode::RCIM_Constant;
    else if (Interp == ECinematicInterpType::Cubic) CurveInterp = ERichCurveInterpMode::RCIM_Cubic;

    // Доступ к каналам через прокси
    FMovieSceneChannelProxy& ChannelProxy = Section->GetChannelProxy();
    
    // В UE5 3DTransform секция имеет индексы 0-8 (добавлен масштаб 6-8)
    for(int i = 0; i < 9; ++i)
    {
        FMovieSceneDoubleChannel* Channel = ChannelProxy.GetChannel<FMovieSceneDoubleChannel>(i);
        if (Channel)
        {
            FMovieSceneDoubleValue NewValue;
            NewValue.Value = Values[i];
            NewValue.InterpMode = CurveInterp;

            // Добавляем ключ
            Channel->GetData().AddKey(FrameNumber, NewValue);
        }
    }

    // Сообщаем движку, что секция изменилась
    Section->Modify();
    Track->Modify();
    
    // Опционально: обновляем диапазон воспроизведения, если ключ вышел за пределы
    UpdatePlaybackRange();
}

void UCinematicCreator::AddFloatPropertyKey(FName Alias, FName PropertyName, float Value, float Time, ECinematicInterpType Interp)
{
    FGuid* ActorGuid = RegisteredActors.Find(Alias);
    if (!ActorGuid || !Sequence || !Sequence->GetMovieScene()) return;

    UMovieScene* MovieScene = Sequence->GetMovieScene();
    
    UMovieSceneDoubleTrack* Track = nullptr;
    for (UMovieSceneTrack* ExistingTrack : MovieScene->FindTracks(UMovieSceneDoubleTrack::StaticClass(), *ActorGuid))
    {
        if (UMovieSceneDoubleTrack* DoubleTrack = Cast<UMovieSceneDoubleTrack>(ExistingTrack))
        {
            if (DoubleTrack->GetPropertyName() == PropertyName)
            {
                Track = DoubleTrack;
                break;
            }
        }
    }
    
    if (!Track) 
    {
        Track = MovieScene->AddTrack<UMovieSceneDoubleTrack>(*ActorGuid);
        if (Track)
        {
            Track->SetPropertyNameAndPath(PropertyName, PropertyName.ToString());
        }
    }

    if (!Track) return;

    UMovieSceneSection* Section = nullptr;
    if (Track->GetAllSections().Num() > 0)
    {
        Section = Track->GetAllSections()[0];
    }
    else
    {
        Section = Track->CreateNewSection();
        Track->AddSection(*Section);
        Section->SetRange(TRange<FFrameNumber>::All());
    }

    if (!Section) return;

    FFrameRate TickResolution = MovieScene->GetTickResolution();
    FFrameNumber FrameNumber = (Time * TickResolution).FrameNumber;

    ERichCurveInterpMode CurveInterp = ERichCurveInterpMode::RCIM_Linear;
    if (Interp == ECinematicInterpType::Constant) CurveInterp = ERichCurveInterpMode::RCIM_Constant;
    else if (Interp == ECinematicInterpType::Cubic) CurveInterp = ERichCurveInterpMode::RCIM_Cubic;

    FMovieSceneChannelProxy& ChannelProxy = Section->GetChannelProxy();
    FMovieSceneDoubleChannel* Channel = ChannelProxy.GetChannel<FMovieSceneDoubleChannel>(0);
    if (Channel)
    {
        FMovieSceneDoubleValue NewValue;
        NewValue.Value = Value;
        NewValue.InterpMode = CurveInterp;
        Channel->GetData().AddKey(FrameNumber, NewValue);
    }

    Section->Modify();
    Track->Modify();
    UpdatePlaybackRange();
}

void UCinematicCreator::AddBoolPropertyKey(FName Alias, FName PropertyName, bool bValue, float Time)
{
    FGuid* ActorGuid = RegisteredActors.Find(Alias);
    if (!ActorGuid || !Sequence || !Sequence->GetMovieScene()) return;

    UMovieScene* MovieScene = Sequence->GetMovieScene();
    
    UMovieSceneBoolTrack* Track = nullptr;
    for (UMovieSceneTrack* ExistingTrack : MovieScene->FindTracks(UMovieSceneBoolTrack::StaticClass(), *ActorGuid))
    {
        if (UMovieSceneBoolTrack* BoolTrack = Cast<UMovieSceneBoolTrack>(ExistingTrack))
        {
            if (BoolTrack->GetPropertyName() == PropertyName)
            {
                Track = BoolTrack;
                break;
            }
        }
    }
    
    if (!Track) 
    {
        Track = MovieScene->AddTrack<UMovieSceneBoolTrack>(*ActorGuid);
        if (Track)
        {
            Track->SetPropertyNameAndPath(PropertyName, PropertyName.ToString());
        }
    }

    if (!Track) return;

    UMovieSceneSection* Section = nullptr;
    if (Track->GetAllSections().Num() > 0)
    {
        Section = Track->GetAllSections()[0];
    }
    else
    {
        Section = Track->CreateNewSection();
        Track->AddSection(*Section);
        Section->SetRange(TRange<FFrameNumber>::All());
    }

    if (!Section) return;

    FFrameRate TickResolution = MovieScene->GetTickResolution();
    FFrameNumber FrameNumber = (Time * TickResolution).FrameNumber;

    FMovieSceneChannelProxy& ChannelProxy = Section->GetChannelProxy();
    FMovieSceneBoolChannel* Channel = ChannelProxy.GetChannel<FMovieSceneBoolChannel>(0);
    if (Channel)
    {
        Channel->GetData().AddKey(FrameNumber, bValue);
    }

    Section->Modify();
    Track->Modify();
    UpdatePlaybackRange();
}

void UCinematicCreator::AddStringPropertyKey(FName Alias, FName PropertyName, const FString& Value, float Time)
{
    FGuid* ActorGuid = RegisteredActors.Find(Alias);
    if (!ActorGuid || !Sequence || !Sequence->GetMovieScene()) return;

    UMovieScene* MovieScene = Sequence->GetMovieScene();
    
    UMovieSceneStringTrack* Track = nullptr;
    for (UMovieSceneTrack* ExistingTrack : MovieScene->FindTracks(UMovieSceneStringTrack::StaticClass(), *ActorGuid))
    {
        if (UMovieSceneStringTrack* StringTrack = Cast<UMovieSceneStringTrack>(ExistingTrack))
        {
            if (StringTrack->GetPropertyName() == PropertyName)
            {
                Track = StringTrack;
                break;
            }
        }
    }
    
    if (!Track) 
    {
        Track = MovieScene->AddTrack<UMovieSceneStringTrack>(*ActorGuid);
        if (Track)
        {
            Track->SetPropertyNameAndPath(PropertyName, PropertyName.ToString());
        }
    }

    if (!Track) return;

    UMovieSceneSection* Section = nullptr;
    if (Track->GetAllSections().Num() > 0)
    {
        Section = Track->GetAllSections()[0];
    }
    else
    {
        Section = Track->CreateNewSection();
        Track->AddSection(*Section);
        Section->SetRange(TRange<FFrameNumber>::All());
    }

    if (!Section) return;

    FFrameRate TickResolution = MovieScene->GetTickResolution();
    FFrameNumber FrameNumber = (Time * TickResolution).FrameNumber;

    FMovieSceneChannelProxy& ChannelProxy = Section->GetChannelProxy();
    FMovieSceneStringChannel* Channel = ChannelProxy.GetChannel<FMovieSceneStringChannel>(0);
    if (Channel)
    {
        Channel->GetData().AddKey(FrameNumber, Value);
    }

    Section->Modify();
    Track->Modify();
    UpdatePlaybackRange();
}

void UCinematicCreator::AddTransformPropertyKey(FName Alias, FName PropertyName, FTransform Value, float Time, ECinematicInterpType Interp)
{
    FGuid* ActorGuid = RegisteredActors.Find(Alias);
    if (!ActorGuid || !Sequence || !Sequence->GetMovieScene()) return;

    UMovieScene* MovieScene = Sequence->GetMovieScene();

    // Ищем существующий трек
    UMovieScene3DTransformTrack* Track = nullptr;
    for (UMovieSceneTrack* ExistingTrack : MovieScene->FindTracks(UMovieScene3DTransformTrack::StaticClass(), *ActorGuid))
    {
        if (UMovieScene3DTransformTrack* TransformTrack = Cast<UMovieScene3DTransformTrack>(ExistingTrack))
        {
            if (TransformTrack->GetPropertyName() == PropertyName)
            {
                Track = TransformTrack;
                break;
            }
        }
    }

    // Создаём новый трек, если не нашли
    if (!Track)
    {
        Track = MovieScene->AddTrack<UMovieScene3DTransformTrack>(*ActorGuid);
        if (Track)
        {
            Track->SetPropertyNameAndPath(PropertyName, PropertyName.ToString());
        }
    }

    if (!Track) return;

    // Берём или создаём секцию
    UMovieSceneSection* Section = nullptr;
    if (Track->GetAllSections().Num() > 0)
    {
        Section = Track->GetAllSections()[0];
    }
    else
    {
        Section = Track->CreateNewSection();
        Track->AddSection(*Section);
        Section->SetRange(TRange<FFrameNumber>::All());
    }

    if (!Section) return;

    FFrameRate TickResolution = MovieScene->GetTickResolution();
    FFrameNumber FrameNumber = (Time * TickResolution).FrameNumber;

    ERichCurveInterpMode CurveInterp = ERichCurveInterpMode::RCIM_Linear;
    if (Interp == ECinematicInterpType::Constant) CurveInterp = ERichCurveInterpMode::RCIM_Constant;
    else if (Interp == ECinematicInterpType::Cubic) CurveInterp = ERichCurveInterpMode::RCIM_Cubic;

    // Получаем канал-прокси
    FMovieSceneChannelProxy& ChannelProxy = Section->GetChannelProxy();

    // Translation (0-2)
    {
        FVector Location = Value.GetLocation();
        double Values[3] = { Location.X, Location.Y, Location.Z };
        for (int32 i = 0; i < 3; ++i)
        {
            FMovieSceneDoubleChannel* Channel = ChannelProxy.GetChannel<FMovieSceneDoubleChannel>(i);
            if (Channel)
            {
                FMovieSceneDoubleValue NewValue;
                NewValue.Value = Values[i];
                NewValue.InterpMode = CurveInterp;
                Channel->GetData().AddKey(FrameNumber, NewValue);
            }
        }
    }

    // Rotation (3-5) — в Euler (Roll, Pitch, Yaw)
    {
        FRotator Rotation = Value.Rotator(); // или Value.GetRotation().Rotator()
        double Values[3] = { Rotation.Roll, Rotation.Pitch, Rotation.Yaw };
        for (int32 i = 0; i < 3; ++i)
        {
            FMovieSceneDoubleChannel* Channel = ChannelProxy.GetChannel<FMovieSceneDoubleChannel>(3 + i);
            if (Channel)
            {
                FMovieSceneDoubleValue NewValue;
                NewValue.Value = Values[i];
                NewValue.InterpMode = CurveInterp;
                Channel->GetData().AddKey(FrameNumber, NewValue);
            }
        }
    }

    // Scale (6-8)
    {
        FVector Scale = Value.GetScale3D();
        double Values[3] = { Scale.X, Scale.Y, Scale.Z };
        for (int32 i = 0; i < 3; ++i)
        {
            FMovieSceneDoubleChannel* Channel = ChannelProxy.GetChannel<FMovieSceneDoubleChannel>(6 + i);
            if (Channel)
            {
                FMovieSceneDoubleValue NewValue;
                NewValue.Value = Values[i];
                NewValue.InterpMode = CurveInterp;
                Channel->GetData().AddKey(FrameNumber, NewValue);
            }
        }
    }

    Section->Modify();
    Track->Modify();
    UpdatePlaybackRange();
}
void UCinematicCreator::AddVectorPropertyKey(FName Alias, FName PropertyName, FVector Value, float Time, ECinematicInterpType Interp)
{
    FGuid* ActorGuid = RegisteredActors.Find(Alias);
    if (!ActorGuid || !Sequence || !Sequence->GetMovieScene()) return;

    UMovieScene* MovieScene = Sequence->GetMovieScene();
    
    UMovieSceneDoubleVectorTrack* Track = nullptr;
    for (UMovieSceneTrack* ExistingTrack : MovieScene->FindTracks(UMovieSceneDoubleVectorTrack::StaticClass(), *ActorGuid))
    {
        if (UMovieSceneDoubleVectorTrack* VecTrack = Cast<UMovieSceneDoubleVectorTrack>(ExistingTrack))
        {
            if (VecTrack->GetPropertyName() == PropertyName)
            {
                Track = VecTrack;
                break;
            }
        }
    }
    
    if (!Track) 
    {
        Track = MovieScene->AddTrack<UMovieSceneDoubleVectorTrack>(*ActorGuid);
        if (Track)
        {
            Track->SetNumChannelsUsed(3);
            Track->SetPropertyNameAndPath(PropertyName, PropertyName.ToString());
        }
    }

    if (!Track) return;

    UMovieSceneSection* Section = nullptr;
    if (Track->GetAllSections().Num() > 0)
    {
        Section = Track->GetAllSections()[0];
    }
    else
    {
        Section = Track->CreateNewSection();
        Track->AddSection(*Section);
        Section->SetRange(TRange<FFrameNumber>::All());
    }

    if (!Section) return;

    FFrameRate TickResolution = MovieScene->GetTickResolution();
    FFrameNumber FrameNumber = (Time * TickResolution).FrameNumber;

    ERichCurveInterpMode CurveInterp = ERichCurveInterpMode::RCIM_Linear;
    if (Interp == ECinematicInterpType::Constant) CurveInterp = ERichCurveInterpMode::RCIM_Constant;
    else if (Interp == ECinematicInterpType::Cubic) CurveInterp = ERichCurveInterpMode::RCIM_Cubic;

    FMovieSceneChannelProxy& ChannelProxy = Section->GetChannelProxy();
    
    double Values[3] = { Value.X, Value.Y, Value.Z };
    for (int32 i = 0; i < 3; ++i)
    {
        FMovieSceneDoubleChannel* Channel = ChannelProxy.GetChannel<FMovieSceneDoubleChannel>(i);
        if (Channel)
        {
            FMovieSceneDoubleValue NewValue;
            NewValue.Value = Values[i];
            NewValue.InterpMode = CurveInterp;
            Channel->GetData().AddKey(FrameNumber, NewValue);
        }
    }

    Section->Modify();
    Track->Modify();
    UpdatePlaybackRange();
}

void UCinematicCreator::AddRotatorPropertyKey(FName Alias, FName PropertyName, FRotator Value, float Time, ECinematicInterpType Interp)
{
    FGuid* ActorGuid = RegisteredActors.Find(Alias);
    if (!ActorGuid || !Sequence || !Sequence->GetMovieScene()) return;

    UMovieScene* MovieScene = Sequence->GetMovieScene();
    
    UMovieSceneRotatorTrack* Track = nullptr;
    for (UMovieSceneTrack* ExistingTrack : MovieScene->FindTracks(UMovieSceneRotatorTrack::StaticClass(), *ActorGuid))
    {
        if (UMovieSceneRotatorTrack* RotTrack = Cast<UMovieSceneRotatorTrack>(ExistingTrack))
        {
            if (RotTrack->GetPropertyName() == PropertyName)
            {
                Track = RotTrack;
                break;
            }
        }
    }
    
    if (!Track) 
    {
        Track = MovieScene->AddTrack<UMovieSceneRotatorTrack>(*ActorGuid);
        if (Track)
        {
            Track->SetPropertyNameAndPath(PropertyName, PropertyName.ToString());
        }
    }

    if (!Track) return;

    UMovieSceneSection* Section = nullptr;
    if (Track->GetAllSections().Num() > 0)
    {
        Section = Track->GetAllSections()[0];
    }
    else
    {
        Section = Track->CreateNewSection();
        Track->AddSection(*Section);
        Section->SetRange(TRange<FFrameNumber>::All());
    }

    if (!Section) return;

    FFrameRate TickResolution = MovieScene->GetTickResolution();
    FFrameNumber FrameNumber = (Time * TickResolution).FrameNumber;

    ERichCurveInterpMode CurveInterp = ERichCurveInterpMode::RCIM_Linear;
    if (Interp == ECinematicInterpType::Constant) CurveInterp = ERichCurveInterpMode::RCIM_Constant;
    else if (Interp == ECinematicInterpType::Cubic) CurveInterp = ERichCurveInterpMode::RCIM_Cubic;

    FMovieSceneChannelProxy& ChannelProxy = Section->GetChannelProxy();
    
    // Rotator sequence is usually Roll (X), Pitch (Y), Yaw (Z) in Sequencer
    double Values[3] = { Value.Roll, Value.Pitch, Value.Yaw };
    for (int32 i = 0; i < 3; ++i)
    {
        FMovieSceneDoubleChannel* Channel = ChannelProxy.GetChannel<FMovieSceneDoubleChannel>(i);
        if (Channel)
        {
            FMovieSceneDoubleValue NewValue;
            NewValue.Value = Values[i];
            NewValue.InterpMode = CurveInterp;
            Channel->GetData().AddKey(FrameNumber, NewValue);
        }
    }

    Section->Modify();
    Track->Modify();
    UpdatePlaybackRange();
}

void UCinematicCreator::UpdatePlaybackRange()
{
    if (!Sequence || !Sequence->GetMovieScene()) return;

    UMovieScene* MovieScene = Sequence->GetMovieScene();
    
    // Получаем текущие границы всех треков
    TRange<FFrameNumber> PlaybackRange = MovieScene->GetPlaybackRange();


    
    // Находим максимальное время среди всех треков, чтобы растянуть таймлайн
    FFrameNumber MaxFrame = FFrameNumber(0);
    for (UMovieSceneTrack* Track : MovieScene->GetTracks())
    {
        for (UMovieSceneSection* Section : Track->GetAllSections())
        {
            if (Section->GetRange().GetUpperBoundValue() > MaxFrame)
            {
                MaxFrame = Section->GetRange().GetUpperBoundValue();
            }
        }
    }

    // Если MaxFrame всё еще 0 (например, ключи в 0 секунд), ставим хотя бы 1 секунду
    if (MaxFrame.Value <= 0)
    {
        MaxFrame = FFrameNumber(MovieScene->GetTickResolution().AsFrameNumber(1.0f));
    }

    // Устанавливаем новый диапазон
    MovieScene->SetPlaybackRange(TRange<FFrameNumber>(FFrameNumber(0), MaxFrame));
}

void UCinematicCreator::FlushChanges()
{
    if (!Sequence || !Sequence->GetMovieScene()) return;

    UMovieScene* MovieScene = Sequence->GetMovieScene();
    UE_LOG(LogTemp, Warning, TEXT("--- FLUSH START ---"));
    UE_LOG(LogTemp, Error, TEXT("DEBUG: Sequence pointer: %p"), Sequence);
    UE_LOG(LogTemp, Error, TEXT("DEBUG: MovieScene pointer: %p"), Sequence ? Sequence->GetMovieScene() : nullptr);
    
    for (UMovieSceneTrack* Track : MovieScene->GetTracks())
    {
        for (UMovieSceneSection* Section : Track->GetAllSections())
        {
            FMovieSceneChannelProxy& Proxy = Section->GetChannelProxy();
            
            // Получаем список каналов через прокси напрямую
            TArrayView<FMovieSceneChannel*> Channels = Proxy.GetChannels<FMovieSceneChannel>();
            
            UE_LOG(LogTemp, Warning, TEXT("Section %s: Found %d channels"), *Section->GetName(), Channels.Num());

            for (FMovieSceneChannel* Channel : Channels)
            {
                if (!Channel) continue;

                // Проверяем, является ли канал Double-каналом (трансформы)
                FMovieSceneDoubleChannel* DoubleChan = static_cast<FMovieSceneDoubleChannel*>(Channel);
                if (DoubleChan)
                {
                    TArrayView<const FFrameNumber> Times = DoubleChan->GetTimes();
                    UE_LOG(LogTemp, Warning, TEXT("  DoubleChannel has %d keys"), Times.Num());
                    for (const FFrameNumber& Time : Times)
                    {
                        UE_LOG(LogTemp, Warning, TEXT("    Key Frame: %d"), Time.Value);
                    }
                }
            }
        }
    }
}

FString UCinematicCreator::InstancedStructToString(const FInstancedStruct& InStruct)
{
    const UScriptStruct* ScriptStruct = InStruct.GetScriptStruct();
    if (!ScriptStruct) return FString();

    FString JsonString;
    if (FJsonObjectConverter::UStructToJsonObjectString(ScriptStruct, InStruct.GetMemory(), JsonString, 0, 0))
    {
        return FString::Printf(TEXT("%s||%s"), *ScriptStruct->GetPathName(), *JsonString);
    }
    return FString();
}

FInstancedStruct UCinematicCreator::StringToInstancedStruct(const FString& InString)
{
    FString StructPath;
    FString JsonString;
    if (InString.Split(TEXT("||"), &StructPath, &JsonString))
    {
        UScriptStruct* ScriptStruct = FindObject<UScriptStruct>(nullptr, *StructPath);
        if (!ScriptStruct)
        {
            ScriptStruct = LoadObject<UScriptStruct>(nullptr, *StructPath);
        }
        
        if (ScriptStruct)
        {
            FInstancedStruct OutStruct;
            OutStruct.InitializeAs(ScriptStruct);
            
            TSharedPtr<FJsonObject> JsonObject;
            TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(JsonString);
            if (FJsonSerializer::Deserialize(JsonReader, JsonObject) && JsonObject.IsValid())
            {
                if (FJsonObjectConverter::JsonObjectToUStruct(JsonObject.ToSharedRef(), ScriptStruct, OutStruct.GetMutableMemory(), 0, 0))
                {
                    return OutStruct;
                }
            }
        }
    }
    return FInstancedStruct();
}