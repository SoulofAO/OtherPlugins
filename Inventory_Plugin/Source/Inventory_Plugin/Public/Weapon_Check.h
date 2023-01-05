// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Weapon_Check.generated.h"

/**
 * 
 */


UCLASS(Abstract, EditInlineNew, Blueprintable, meta = (ShowWorldContextPin))
class INVENTORY_PLUGIN_API UWeapon_Check : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Serialize")
	bool Check();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Serialize")
	void Start();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Serialize")
	void Apply(bool Sucsess);

public:

	virtual UWorld* GetWorld() const override;
};


USTRUCT(BlueprintType)
struct FCheckWeaponStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
	UWeapon_Check* WeaponCheckObject;
};