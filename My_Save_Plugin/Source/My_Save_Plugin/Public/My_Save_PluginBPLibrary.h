// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Serialization/ObjectAndNameAsStringProxyArchive.h"
#include "My_Save_PluginBPLibrary.generated.h"

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/
class FSaveGameArchive : public FObjectAndNameAsStringProxyArchive
{
public:
    FSaveGameArchive(FArchive& InInnerArchive)
        : FObjectAndNameAsStringProxyArchive(InInnerArchive, true)
    {
        ArIsSaveGame = true;
        ArNoDelta = true;
    }
};

USTRUCT(BlueprintType)
struct FPropertyReference
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
        FName VariableName;

    UPROPERTY(BlueprintReadWrite)
        FName ObjectName;

    UPROPERTY(BlueprintReadWrite)
        UObject* ObjectLink;

    UPROPERTY(BlueprintReadWrite)
        UObject* VariableLink;

};

UCLASS()
class UMy_Save_PluginBPLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, meta = (CallableWithoutWorldContext, ToolTip = "Forming an array of bytes of serialization", DisplayName = "Serialize", KeyWords = "Serialize"))
    static void FL_SERIALIZE__Serialize(UPARAM(DisplayName = "Object") UObject* const object_reference, UPARAM(DisplayName = "Data") TArray<uint8>& serialization_data);

    UFUNCTION(BlueprintCallable, meta = (CallableWithoutWorldContext, ToolTip = "Restore from an array of bytes of serialization", DisplayName = "De Serialize", KeyWords = "Serialize"))
    static void FL_SERIALIZE__DeSerialize(UPARAM(DisplayName = "Object") UObject* const object_reference, UPARAM(ref, DisplayName = "Data") TArray<uint8>& serialization_data);

    UFUNCTION(BlueprintCallable, meta = (DeterminesOutputType = ObjectClasss))
    static TArray<UObject*> GetAllUObjectByObjectClass(TSubclassOf<UObject> ObjectClass);

    UFUNCTION(BlueprintCallable)
    static TArray<FPropertyReference> GetAllReferenceToUObject(UObject* Object);

    UFUNCTION(BlueprintCallable)
    static FName GetObjectNameLink(UObject* ObjectClass);

    UFUNCTION(BlueprintCallable)
    static void ParseObjectLink(FName ObjectNameLink, FString& ActorName, FString ComponentName, FString& ObjectName);

    UFUNCTION(BlueprintCallable)
    static TArray<UObject*> GetAllReferencese(UObject* Object);
};





USTRUCT(BlueprintType)
struct FSaveUObject
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    UObject* Object;

    UPROPERTY(BlueprintReadWrite)
    FName ObjectName;
};

USTRUCT(BlueprintType)
struct FSaveActorComponent
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    UActorComponent* ActorComponent;

    UPROPERTY(BlueprintReadWrite)
    FName ObjectName;

    UPROPERTY(BlueprintReadWrite)
    TSubclassOf<UActorComponent> ActorComponentClass;

    UPROPERTY(BlueprintReadWrite)
    FTransform Transform;

    UPROPERTY(BlueprintReadWrite)
    TArray<uint8> SerializationData;
};

USTRUCT(BlueprintType)
struct FSaveActor
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    AActor* Actor;

    UPROPERTY(BlueprintReadWrite)
    FName ObjectName;

    UPROPERTY(BlueprintReadWrite)
    TSubclassOf<AActor> ActorClass;

    UPROPERTY(BlueprintReadWrite)
        FTransform Transform;
    UPROPERTY(BlueprintReadWrite)
        TArray<uint8> SerializationData;
    UPROPERTY(BlueprintReadWrite)
        TArray<FSaveActorComponent> ActorComponents;
};
