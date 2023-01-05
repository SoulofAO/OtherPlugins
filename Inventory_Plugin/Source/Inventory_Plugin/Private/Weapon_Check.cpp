// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon_Check.h"

UWorld* UWeapon_Check::GetWorld() const
{
	if (GIsEditor && !GIsPlayInEditorWorld) return nullptr;
	else if (GetOuter()) return GetOuter()->GetWorld();
	else return nullptr;
}
