
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/DataTable.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Apply_Dialog_Object_Main.generated.h"


UENUM(BlueprintType)
enum class Dialog_Type : uint8
{
	None UMETA(DisplayName = None),
	Words UMETA(DisplayName = Words),
	Answer UMETA(DisplayName = Answer)
};


USTRUCT(BlueprintType )
struct FMain_Dialog_Struct : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
	UApply_Dialog_Object_Main* Apply_Dialog;
};

UCLASS(Abstract, EditInlineNew, Blueprintable, meta = (ShowWorldContextPin))
class DIALOG_SYSTEM_API UApply_Dialog_Object_Main : public UObject
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Apply_Dialog")
	int ApplyCommand(UObject* WorldContextObject, AActor* Caller);

	virtual UWorld* GetWorld() const override;
public:
	UFUNCTION(BlueprintPure)
		AActor* GetOwner() const { return Cast<AActor>(GetOuter()); };


};

/*UCLASS()
class UDialogSistemLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Dialog_System", meta = (BlueprintThreadSafe))
	static void BreakDialogStruct(const FMain_Dialog_Struct& Dialog_Struct, TArray<FText>& Text, Dialog_Type& Type, TArray<int>& Links, TArray<UApply_Dialog_Object_Main*>& Apply_Dialog)
	{
		Text = Dialog_Struct.Text;
		Type = Dialog_Struct.Type;
		Links = Dialog_Struct.Links;
		Apply_Dialog = Dialog_Struct.Apply_Dialog;
	}
	static FMain_Dialog_Struct MakeDialogStruct(TArray<FText> Text, Dialog_Type Type, TArray<int> Links, TArray<UApply_Dialog_Object_Main*> Apply_Dialog)
	{
		FMain_Dialog_Struct Dialog_Struct;
		Dialog_Struct.Text = Text;
		Dialog_Struct.Type = Type;
		Dialog_Struct.Links = Links;
		Dialog_Struct.Apply_Dialog = Apply_Dialog;
		return Dialog_Struct;

	}
};*/