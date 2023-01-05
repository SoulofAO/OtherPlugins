// Fill out your copyright notice in the Description page of Project Settings.


#include "OptimalTargetAlgorithm.h"

UWorld* UOptimalTargetAlgorithm::GetWorld() const
{
	// Возвращаем ссылку на мир из владельца объекта, если не работаем редакторе.
	if (GIsEditor && !GIsPlayInEditorWorld) return nullptr;
	else if (GetOuter()) return GetOuter()->GetWorld();
	else return nullptr;
}