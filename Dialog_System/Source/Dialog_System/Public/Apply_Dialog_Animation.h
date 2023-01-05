// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Apply_Dialog_Object_Main.h"
#include "Apply_Dialog_Animation.generated.h"

/**
 * 
 */
UCLASS()
class DIALOG_SYSTEM_API UApply_Dialog_Animation : public UApply_Dialog_Object_Main
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UAnimMontage* AnimMontage;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	uint8 EnumAnimation;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool Loop;

};
