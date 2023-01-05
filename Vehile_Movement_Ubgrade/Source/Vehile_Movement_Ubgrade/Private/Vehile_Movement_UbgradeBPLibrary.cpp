// Copyright Epic Games, Inc. All Rights Reserved.

#include "Vehile_Movement_UbgradeBPLibrary.h"
//#include "WheeledVehicleMovementComponent.h"
#include "Vehile_Movement_Ubgrade.h"

UVehile_Movement_UbgradeBPLibrary::UVehile_Movement_UbgradeBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

void UVehile_Movement_UbgradeBPLibrary::Vehile_Movement_Ubgrade_Set_Max_RPM(float Speed, UWheeledVehicleMovementComponent* Component_1)
{
	//Component_1->DragArea;
	//Component->MaxRPM = Speed;
}

void UVehile_Movement_UbgradeBPLibrary::Vehile_Movement_Ubgrade_Set_Torcue_Curve(UCurveFloat* Curve, UWheeledVehicleMovementComponent* Component_1)
{
	//Component->TorqueCurve = Curve;
}
