// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CinematicCharacter.generated.h"




UCLASS()
class CHECKDYNCINIMATIC_API ACinematicCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cinimatic")
	bool bIsTeleporting = false;
	
	UFUNCTION (BlueprintSetter, Category = "CinimaticParameters")
	void SetTeleportTransform(const FTransform NewTransform);

	UFUNCTION (BlueprintSetter, Category = "CinimaticParameters")
	void SetPosition (const FVector NewVector);
	
	UFUNCTION (BlueprintSetter, Category = "CinimaticParameters")
	void SetFocus (const FVector NewVector);
	
	UFUNCTION (BlueprintSetter, Category = "CinimaticParameters")
	void SetCommand (const FString NewString);
	
	UFUNCTION (BlueprintCallable, Category = "CinimaticParameters")
	void ResetCommand () {Command = "";};
	
	UFUNCTION (BlueprintNativeEvent, Category = "CinimaticEvent")
	void OnTeleportTransform (const FTransform& NewTransform);

	UFUNCTION (BlueprintNativeEvent, Category = "CinimaticEvent")
	void OnPosition (const FVector& NewVector);
	
	UFUNCTION (BlueprintNativeEvent, Category = "CinimaticEvent")
	void OnFocus (const FVector& NewVector);
	
	UFUNCTION (BlueprintNativeEvent, Category = "CinimaticEvent")
	void OnCommand (const FString& NewString);
	
	UFUNCTION(BlueprintCallable, Category = "Cinimatic")
	void DoTeleportTransform(const FTransform& NewTransform);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CinimaticParameters", meta=(BlueprintSetter="SetCommand"))
	FString Command;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CinimaticParameters", meta=(BlueprintSetter="SetTeleportTransform"))
	FTransform TeleportTransform;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CinimaticParameters", meta=(BlueprintSetter="SetPosition"))
	FVector Position;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CinimaticParameters",  meta=(BlueprintSetter="SetFocus"))
	FVector Focus;
	
	// Sets default values for this character's properties
	ACinematicCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
