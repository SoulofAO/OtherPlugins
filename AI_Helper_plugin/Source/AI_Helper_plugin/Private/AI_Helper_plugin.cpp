// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI_Helper_plugin.h"

#define LOCTEXT_NAMESPACE "FAI_Helper_pluginModule"

void FAI_Helper_pluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
}

void FAI_Helper_pluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	

}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAI_Helper_pluginModule, AI_Helper_plugin)