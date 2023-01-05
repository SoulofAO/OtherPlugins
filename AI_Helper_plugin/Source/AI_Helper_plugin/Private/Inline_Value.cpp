// Fill out your copyright notice in the Description page of Project Settings.


#include "Inline_Value.h"

UWorld* UInline_Value::GetWorld() const
{
	// Возвращаем ссылку на мир из владельца объекта, если не работаем редакторе.
	if (GIsEditor && !GIsPlayInEditorWorld) return nullptr;
	else if (GetOuter()) return GetOuter()->GetWorld();
	else return nullptr;
}