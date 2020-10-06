// Fill out your copyright notice in the Description page of Project Settings.


#include "GhostPawn.h"



void AGhostPawn::Hunt()
{
	State = EGhostState::Default;

	StateChangedEvent.Broadcast(State);
}

void AGhostPawn::Idle()
{
	State = EGhostState::Idle;

	StateChangedEvent.Broadcast(State);
}
