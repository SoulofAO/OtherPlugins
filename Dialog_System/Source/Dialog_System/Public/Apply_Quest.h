// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Apply_Dialog_Object_Main.h"
#include "Apply_Quest.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FApply_Quest_Struct 
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
	UApply_Quest* Apply_Dialog;
};

UCLASS()
class DIALOG_SYSTEM_API UApply_Quest : public UApply_Dialog_Object_Main
{
	GENERATED_BODY()
	
};
