// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"
#include "../Public/TankTrack.h"


UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity()); //Getting slippage speed

	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector(); // Acceleration to correct this tick.

	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
		
	auto CorrectionForce = TankRoot->GetMass() * CorrectionAcceleration / 2; //Apply sideways to 2 tracks

	TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::SetThrottle(float Throttle)
{


	
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
