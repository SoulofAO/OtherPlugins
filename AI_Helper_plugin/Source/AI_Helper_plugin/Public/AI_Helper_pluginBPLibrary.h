// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType.h"
#include "AI_Helper_pluginBPLibrary.generated.h"

UCLASS()
class UAI_Helper_pluginBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

		UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetBlackbordKeyVector", Keywords = "GetBlackbordKeyVector"), Category = "AI_Helper_pluginTesting")
		FVector AI_Helper_GetActorOrLocaltion(UBTNode* NodeOwner, const FBlackboardKeySelector& Key);
};
