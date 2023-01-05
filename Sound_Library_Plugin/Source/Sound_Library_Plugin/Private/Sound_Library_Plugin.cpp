// Copyright Epic Games, Inc. All Rights Reserved.

#include "Sound_Library_Plugin.h"

#define LOCTEXT_NAMESPACE "FSound_Library_PluginModule"

void FSound_Library_PluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
}

void FSound_Library_PluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSound_Library_PluginModule, Sound_Library_Plugin)