#include "CinematicCreator.h"
#include "MovieScene.h"
#include "Tracks/MovieScene3DTransformTrack.h"
#include "Sections/MovieScene3DTransformSection.h"
#include "Channels/MovieSceneDoubleChannel.h" // Убедитесь, что это есть
#include "Channels/MovieSceneFloatChannel.h"

void UCinematicCreator::InitializeCreator()
{
    Sequence = NewObject<ULevelSequence>(this, NAME_None, RF_Transient);
    Sequence->Initialize();
}

bool UCinematicCreator::RegisterPossessableActor(AActor* Actor, FName Alias)
{
    if (!Actor || !Sequence) return false;
    
    UMovieScene* MovieScene = Sequence->GetMovieScene();
    FGuid ActorGuid = MovieScene->AddPossessable(Actor->GetActorLabel(), Actor->GetClass());
    Sequence->BindPossessableObject(ActorGuid, *Actor, GetWorld());
    
    RegisteredActors.Add(Alias, ActorGuid);
    return true;
}

bool UCinematicCreator::RegisterSpawnableActor(TSubclassOf<AActor> ActorClass, FName Alias)
{
    if (!ActorClass || !Sequence) return false;

    UMovieScene* MovieScene = Sequence->GetMovieScene();
    
    // 1. Создаем временный объект-шаблон (Template) в Transient пакете
    // MovieScene будет использовать его как прототип для спавна в мире
    AActor* SpawnTemplate = NewObject<AActor>(GetTransientPackage(), ActorClass, NAME_None, RF_Transient);
    
    if (!SpawnTemplate) return false;

    // 2. Добавляем Spawnable через шаблон
    // AddSpawnable возвращает FGuid, но внутри себя делает копию нашего шаблона
    FGuid ActorGuid = MovieScene->AddSpawnable(Alias.ToString(), *SpawnTemplate);
    
    if (ActorGuid.IsValid())
    {
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

    // Преобразуем секунды в количество кадров
    FFrameNumber StartFrame = FFrameNumber(0);
    FFrameNumber EndFrame = (DurationInSeconds * TickResolution).FrameNumber;

    // Устанавливаем диапазон воспроизведения
    // TRange создает интервал [Start, End)
    TRange<FFrameNumber> PlaybackRange = TRange<FFrameNumber>(StartFrame, EndFrame);
    
    MovieScene->SetPlaybackRange(PlaybackRange);
    
    // Помечаем объект как измененный, чтобы изменения сохранились
    Sequence->Modify();
}

void UCinematicCreator::AddTransformKey(FName Alias, FTransform Transform, float Time, ECinematicInterpType Interp)
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
        Section->SetRange(TRange<FFrameNumber>::All());
    }

    if (!Section) return;

    // Вычисляем кадр
    FFrameRate TickResolution = MovieScene->GetTickResolution();
    FFrameNumber FrameNumber = (Time * TickResolution).FrameNumber;

    // Подготавливаем значения
    double Values[6] = { 
        Transform.GetLocation().X, Transform.GetLocation().Y, Transform.GetLocation().Z,
        Transform.Rotator().Roll, Transform.Rotator().Pitch, Transform.Rotator().Yaw 
    };

    // Определяем тип интерполяции
    ERichCurveInterpMode CurveInterp = ERichCurveInterpMode::RCIM_Linear;
    if (Interp == ECinematicInterpType::Constant) CurveInterp = ERichCurveInterpMode::RCIM_Constant;
    else if (Interp == ECinematicInterpType::Cubic) CurveInterp = ERichCurveInterpMode::RCIM_Cubic;

    // Доступ к каналам через прокси
    FMovieSceneChannelProxy& ChannelProxy = Section->GetChannelProxy();
    
    // В UE5.7 3DTransform секция имеет индексы 0-5
    for(int i = 0; i < 6; ++i)
    {
        FMovieSceneDoubleChannel* Channel = ChannelProxy.GetChannel<FMovieSceneDoubleChannel>(i);
        if (Channel)
        {
            // Создаем структуру значения, так как современный API требует FMovieSceneDoubleValue
            FMovieSceneDoubleValue NewValue;
            NewValue.Value = Values[i];
            NewValue.InterpMode = CurveInterp;

            // Добавляем ключ
            Channel->GetData().AddKey(FrameNumber, NewValue);
            
            // Сортируем ключи, чтобы Sequencer их корректно отобразил
            
        }
    }

    // Сообщаем движку, что секция изменилась
    Section->Modify();
    Track->Modify();
    
    // Опционально: обновляем диапазон воспроизведения, если ключ вышел за пределы
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