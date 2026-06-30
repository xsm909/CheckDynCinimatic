// Fill out your copyright notice in the Description page of Project Settings.


#include "CinematicCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AIController.h"
#include "MotionWarpingComponent.h"
#include "BrainComponent.h"

void ACinematicCharacter::SetTeleportTransform(const FTransform NewTransform)
{
	if (!TeleportTransform.Equals(NewTransform, 0.0001f))
	{
		TeleportTransform = NewTransform;
		OnTeleportTransform(NewTransform);
	}
}


void ACinematicCharacter::SetPosition(const FVector NewVector)
{
	if (!Position.Equals(NewVector, 0.0001f))
	{
		Position = NewVector;
		OnPosition(NewVector);
	}
}

void ACinematicCharacter::SetFocus(const FVector NewVector)
{
	if (!Focus.Equals(NewVector, 0.0001f))
	{
		Focus = NewVector;
		OnFocus(Focus);
	}
}

void ACinematicCharacter::SetCommand(const FString NewString)
{
	if (Command != NewString)
	{
		Command = NewString;
		OnCommand(NewString);
	}
}




void ACinematicCharacter::DoTeleportTransform(const FTransform& NewTransform)
{
	// 1. Останавливаем всё движение физически
	UCharacterMovementComponent* MoveComp = GetCharacterMovement();
	if (MoveComp)
	{
		MoveComp->StopMovementImmediately(); // Убирает вектор скорости
		MoveComp->Velocity = FVector::ZeroVector; // Обнуляет вектор скорости
	}

	// 2. Телепортация
	TeleportTo(NewTransform.GetLocation(), NewTransform.GetRotation().Rotator(), false, true);

	// 3. ПРИНУДИТЕЛЬНЫЙ СБРОС ТРАЕКТОРИИ (Ключевой момент)
	// В большинстве MM систем есть компонент с функцией Reset
	// Если у вас есть доступ к компоненту траектории (поищите что-то вроде UTrajectoryComponent), 
	// вызовите его сброс:
	// TrajectoryComp->Reset(); 

	// 4. Поворачиваем актора и контроллер
	SetActorRotation(NewTransform.GetRotation());
	if (GetController())
	{
		GetController()->SetControlRotation(NewTransform.GetRotation().Rotator());
	}

	// 5. "Обманка" для Motion Matching
	// MM часто использует "Rotation Rate" для плавного поворота.
	// Если поставить значение очень высоким на один кадр, он мгновенно довернется.
	if (MoveComp)
	{
		MoveComp->RotationRate = FRotator(0.f, 10000.f, 0.f); 
	}
}

void ACinematicCharacter::OnCommand_Implementation(const FString& NewString)
{
	
}

void ACinematicCharacter::OnTeleportTransform_Implementation(const FTransform& NewTransform)
{
}

void ACinematicCharacter::OnPosition_Implementation(const FVector& NewVector)
{
}

void ACinematicCharacter::OnFocus_Implementation(const FVector& NewVector)
{
}

// Sets default values
ACinematicCharacter::ACinematicCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACinematicCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACinematicCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ACinematicCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

