// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CheckBattleStep.generated.h"



UENUM(BlueprintType)
enum class Bool_Operation_Apply : uint8
{
	OR UMETA(DisplayName = OR),
	AND UMETA(DisplayName = AND)
};



USTRUCT(BlueprintType)
struct FStructCheckBattleStep
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
	UCheckBattleStep* CheckBattleStep;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		Bool_Operation_Apply Bool_Operation;

};

UCLASS(Abstract, EditInlineNew, Blueprintable, meta = (ShowWorldContextPin))
class AI_HELPER_PLUGIN_API UCheckBattleStep : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Check_Battle_Step")
		bool Check(AActor* Caller);
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Check_Battle_Step")
		void Start_Recive(AActor* BattleManager);
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Check_Battle_Step")
		void End_Recive(AActor* BattleManager);
	virtual UWorld* GetWorld() const override;


};
