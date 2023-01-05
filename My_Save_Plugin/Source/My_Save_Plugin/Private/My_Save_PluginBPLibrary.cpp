// Copyright Epic Games, Inc. All Rights Reserved.

#include "My_Save_PluginBPLibrary.h"
#include "My_Save_Plugin.h"
#include "UObject/Object.h"
#include "UObject/UObjectHash.h"

void UMy_Save_PluginBPLibrary::FL_SERIALIZE__Serialize(UPARAM(DisplayName = "Object") UObject* const object_reference, UPARAM(DisplayName = "Data") TArray<uint8>& serialization_data)
{
    FMemoryWriter MemoryWriter(serialization_data, true);
    FSaveGameArchive arc(MemoryWriter);
    object_reference->Serialize(arc);
   
}
void UMy_Save_PluginBPLibrary::FL_SERIALIZE__DeSerialize(UPARAM(DisplayName = "Object") UObject* const object_reference, UPARAM(ref, DisplayName = "Data") TArray<uint8>& serialization_data)
{
    FMemoryReader MemoryReader(serialization_data, true);
    FSaveGameArchive arc(MemoryReader);
    object_reference->Serialize(arc);
}

TArray<UObject*> UMy_Save_PluginBPLibrary::GetAllUObjectByObjectClass(TSubclassOf<UObject> ObjectClass)
{
    TArray<UObject*> ObjectArray;
    for (TObjectIterator<UClass> Object; Object; ++Object)
    {
        if (Object->GetClass()->IsChildOf(ObjectClass))
        {
            ObjectArray.Add(Object->GetDefaultObject());
        }
    }
    return ObjectArray;
}


TArray<FPropertyReference> UMy_Save_PluginBPLibrary::GetAllReferenceToUObject(UObject* ReferenceObject)
{
    TArray<FPropertyReference> PropertyReferenceArray;

    for (TObjectIterator<UClass> Object; Object; ++Object)
    {
        if (UBlueprintGeneratedClass* BPGC = Cast<UBlueprintGeneratedClass>(Object->GetDefaultObject()->GetClass()))
        {
            for (TFieldIterator<FObjectProperty> Prop(BPGC, EFieldIteratorFlags::IncludeSuper); Prop; ++Prop) {
                FName Name = FName((Prop->GetName()));
                UObject* Reference = Prop->GetObjectPropertyValue(ReferenceObject);
                if (Reference == ReferenceObject)
                {
                    FPropertyReference PropertyReference;
                    PropertyReference.VariableLink = Reference;
                    PropertyReference.VariableName = Name;
                    PropertyReference.ObjectName = GetObjectNameLink(ReferenceObject);
                    PropertyReference.ObjectLink = ReferenceObject;
                    PropertyReferenceArray.Add(PropertyReference);
                }
            }
        }
    }
    return PropertyReferenceArray;
}

FName UMy_Save_PluginBPLibrary::GetObjectNameLink(UObject* Object)
{
    FName Name;
    if (AActor* Actor = Cast<AActor>(Object))
    {
        Name = FName(Actor->GetName());
        return Name;
    }
    if (UActorComponent* Component = Cast<UActorComponent>(Object))
    {
        FString ActorName = Component->GetOwner()->GetName();
        Name = FName(ActorName+"."+Component->GetName());
        return Name;
    }
    
    if (UObject* LocalObject = Cast<UObject>(Object))
    {
        if (AActor* Actor = Cast<AActor>(LocalObject->GetOuter()))
        {
            Name = FName(Actor->GetName() + "." + LocalObject->GetName());
        }
        if (UActorComponent* Component = Cast<UActorComponent>(LocalObject->GetOuter()))
        {
            FString Actor = Component->GetOwner()->GetName();
            Name = FName(Actor+"."+Component->GetName() +"."+ LocalObject->GetName());
        }
    }
    return Name;
}

void UMy_Save_PluginBPLibrary::ParseObjectLink(FName ObjectNameLink, FString& ActorName, FString ComponentName, FString& ObjectName)
{
  
}

TArray<UObject*> UMy_Save_PluginBPLibrary::GetAllReferencese(UObject* Object)
{
    TArray<UObject*> Array;
    return Array;
}

