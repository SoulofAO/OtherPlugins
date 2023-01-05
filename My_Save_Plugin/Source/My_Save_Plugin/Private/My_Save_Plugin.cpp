// Copyright Epic Games, Inc. All Rights Reserved.

#include "My_Save_Plugin.h"

#define LOCTEXT_NAMESPACE "FMy_Save_PluginModule"

void FMy_Save_PluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
}

void FMy_Save_PluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMy_Save_PluginModule, My_Save_Plugin)