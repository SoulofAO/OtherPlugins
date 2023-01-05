// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Apply_Dialog_Object_Main.h"
#include "Apply_Dialog_Open_Level.generated.h"

/**
 * 
 */
UCLASS()
class DIALOG_SYSTEM_API UApply_Dialog_Open_Level : public UApply_Dialog_Object_Main
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly);
	FName Name;
};
