// Fill out your copyright notice in the Description page of Project Settings.


#include "Apply_Dialog_Object_Main.h"

UWorld* UApply_Dialog_Object_Main::GetWorld() const
{
	// ���������� ������ �� ��� �� ��������� �������, ���� �� �������� ���������.
	if (GIsEditor && !GIsPlayInEditorWorld) return nullptr;
	else if (GetOuter()) return GetOuter()->GetWorld();
	else return nullptr;
}
