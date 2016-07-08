// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"
#include "../Public/TankAIController.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	
	UE_LOG(LogTemp, Warning, TEXT("AIController working!"));
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not pointing at Player!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController pointing at: %s"), *PlayerTank->GetName());
	}
}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) {return nullptr;}
	return Cast<ATank>(PlayerPawn);
}