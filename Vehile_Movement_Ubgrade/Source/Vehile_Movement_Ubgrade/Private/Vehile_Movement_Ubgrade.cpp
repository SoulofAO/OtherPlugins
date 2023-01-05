// Copyright Epic Games, Inc. All Rights Reserved.

#include "Vehile_Movement_Ubgrade.h"

#define LOCTEXT_NAMESPACE "FVehile_Movement_UbgradeModule"

void FVehile_Movement_UbgradeModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
}

void FVehile_Movement_UbgradeModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FVehile_Movement_UbgradeModule, Vehile_Movement_Ubgrade)