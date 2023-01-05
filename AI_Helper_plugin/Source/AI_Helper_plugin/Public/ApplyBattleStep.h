// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ApplyBattleStep.generated.h"


USTRUCT(BlueprintType)
struct FStructBattleStep
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
	UApplyBattleStep* ApplyBattleStep;

};


UCLASS(Abstract, EditInlineNew, Blueprintable, meta = (ShowWorldContextPin))

class AI_HELPER_PLUGIN_API UApplyBattleStep : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Check_Battle_Step")
		void ApplyStep(AActor* Battle_Manager);
	virtual UWorld* GetWorld() const override;
	
};
