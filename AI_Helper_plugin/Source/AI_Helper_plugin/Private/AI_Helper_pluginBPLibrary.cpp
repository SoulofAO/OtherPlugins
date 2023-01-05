// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI_Helper_pluginBPLibrary.h"
#include "AI_Helper_plugin.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "BehaviorTree/BTFunctionLibrary.h"

UAI_Helper_pluginBPLibrary::UAI_Helper_pluginBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

FVector UAI_Helper_pluginBPLibrary::AI_Helper_GetActorOrLocaltion(UBTNode* NodeOwner, const FBlackboardKeySelector& Key)
{
	UBlackboardComponent* BlackboardComp = UBTFunctionLibrary::GetOwnersBlackboard(NodeOwner);
	UObject* Object = BlackboardComp->GetValueAsObject(Key.SelectedKeyName);
	if (Object) 
	{
		return (Cast<AActor>(Object)->GetActorLocation());
	}
	else {
		return BlackboardComp->GetValueAsVector(Key.SelectedKeyName);
	}


	//BlackboardKey.AddVectorFilter();
	return{};
	
}

