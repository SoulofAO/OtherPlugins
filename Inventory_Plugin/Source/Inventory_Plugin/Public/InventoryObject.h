// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "InventoryObject.generated.h"

/**
 * 
 */


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FChangePlaceDelegate, const FGameplayTag&, GameplayTag);
UCLASS(Abstract, EditInlineNew, Blueprintable, meta = (ShowWorldContextPin))
class INVENTORY_PLUGIN_API UInventoryObject : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Serialize")
	void Serialize();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Serialize")
	void Deserialize();

	UPROPERTY(BlueprintAssignable);
	FChangePlaceDelegate ChangePlaceDelegate;
public:

	virtual UWorld* GetWorld() const override;
};

USTRUCT(BlueprintType)
struct FInventoryObjectStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
	UInventoryObject* InventoryObject;
};