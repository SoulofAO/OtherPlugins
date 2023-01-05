// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Inline_Value.generated.h"

/**
 * 
 */

UCLASS(Abstract, EditInlineNew, Blueprintable, meta = (ShowWorldContextPin))

class AI_HELPER_PLUGIN_API UInline_Value : public UObject
{
	GENERATED_BODY()

	virtual UWorld* GetWorld() const override;
};


USTRUCT(BlueprintType)
struct FInline_Value_Struct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
	UInline_Value* InlineValue;
};