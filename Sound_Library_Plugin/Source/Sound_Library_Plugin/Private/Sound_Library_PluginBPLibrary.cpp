// Copyright Epic Games, Inc. All Rights Reserved.

#include "Sound_Library_PluginBPLibrary.h"
#include "Sound/SoundBase.h"
#include "Sound_Library_Plugin.h"

USound_Library_PluginBPLibrary::USound_Library_PluginBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float USound_Library_PluginBPLibrary::Get_Sound_Duration(USoundBase* Sound)
{

	return Sound->Duration;
}
