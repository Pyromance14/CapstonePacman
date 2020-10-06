// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GhostPawn.generated.h"

UENUM(BlueprintType)
enum class EGhostState : uint8
{
	Default, // going to be used to search for player
	Idle // going to be used to stand still
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGhostStateChangedEvent, EGhostState, NewState);
UCLASS()
class CAPSTONE1PACMAN_API AGhostPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EGhostState State = EGhostState::Default; // set for default enemy state also 
	 
	UFUNCTION(BlueprintCallable)
		void Hunt(); // For when ghost chases player

	UFUNCTION(BlueprintCallable)
		void Idle(); // For when ghost can't find player

	FGhostStateChangedEvent& OnStageChanged() { return StateChangedEvent; }

private:

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
		FGhostStateChangedEvent StateChangedEvent;
};
