// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OptimalTargetAlgorithm.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FOptimalTargetAlgorithmReturn
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AActor*> Enemenys;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* CallerActor;
};

UCLASS(Abstract, EditInlineNew, Blueprintable, meta = (ShowWorldContextPin))

class AI_HELPER_PLUGIN_API UOptimalTargetAlgorithm : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Target")
	void BattleStart();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Target")
	void Clear();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Target")
	TArray<AActor*> GetOptimalTargetAlgorithmActors(FOptimalTargetAlgorithmReturn Enemenys);

public:

	//UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Target")
	//TArray<AActor*> GetOptimalTargetActors(TArray<AActor*> CorrectEnemys, AActor* Caller);

	virtual UWorld* GetWorld() const override;
	
};

USTRUCT(BlueprintType)
struct FOptimalTargetAlgorithmStruct
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
		UOptimalTargetAlgorithm* OptimalTargetAlgorithm;
};