// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryObject.h"


UWorld* UInventoryObject::GetWorld() const
{
	if (GIsEditor && !GIsPlayInEditorWorld) return nullptr;
	else if (GetOuter()) return GetOuter()->GetWorld();
	else return nullptr;
}
