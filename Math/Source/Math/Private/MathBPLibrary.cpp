// Copyright Epic Games, Inc. All Rights Reserved.

#include "MathBPLibrary.h"
#include "Math.h"
#include <math.h>

UMathBPLibrary::UMathBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float UMathBPLibrary::MathAtan(float AtangValue)
{
	return atan(AtangValue);
}

float UMathBPLibrary::MathAtanInDegrees(float AtangValue)
{
	return atan(AtangValue)/3.14*180;
}

