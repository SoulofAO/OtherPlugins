// Copyright Epic Games, Inc. All Rights Reserved.

#include "GetMeshVertexBPLibrary.h"
#include "GetMeshVertex.h"

UGetMeshVertexBPLibrary::UGetMeshVertexBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

FVector UGetMeshVertexBPLibrary::GetVertexLocaltion(int Count, UStaticMeshComponent* StaticMeshComponent)
{

    if (StaticMeshComponent->GetStaticMesh()->RenderData->LODResources.Num() > 0)
    {
        FPositionVertexBuffer* VertexBuffer = &StaticMeshComponent->GetStaticMesh()->RenderData->LODResources[0].VertexBuffers.PositionVertexBuffer;
        if (VertexBuffer)
        {
            return VertexBuffer->VertexPosition(Count);
        }
    }
    return { 0,0,0 };
}

int32 UGetMeshVertexBPLibrary::GetVertexCount(UStaticMeshComponent* StaticMeshComponent)
{
    if (StaticMeshComponent->GetStaticMesh()->RenderData->LODResources.Num() > 0)
    {
        FPositionVertexBuffer* VertexBuffer = &StaticMeshComponent->GetStaticMesh()->RenderData->LODResources[0].VertexBuffers.PositionVertexBuffer;
        if (VertexBuffer)
        {
            return VertexBuffer->GetNumVertices();
        }
    }

    return 0;
}

TArray<FVector> UGetMeshVertexBPLibrary::Normalize_Vector_MeshVertex(TArray<FVector> StaticMeshArrayVertex)
{
    TArray<FVector> ArrayAnswer;
    for (const auto x : StaticMeshArrayVertex) 
    {
        bool SucsessFind = 0;
        for (const auto y : ArrayAnswer)
        {
            if (x == y) 
            {
                SucsessFind = 1;
                break;
            }
            else 
            {
                
            }
        }
        if (!SucsessFind)
        {
            ArrayAnswer.Add(x);
        }
    }
    return ArrayAnswer;
}

FColor UGetMeshVertexBPLibrary::GetVertexColor(int Count, UStaticMeshComponent* StaticMeshComponent)
{
    if (StaticMeshComponent->GetStaticMesh()->RenderData->LODResources.Num() > 0)
    {
        FColorVertexBuffer* VertexBuffer = &StaticMeshComponent->GetStaticMesh()->RenderData->LODResources[0].VertexBuffers.ColorVertexBuffer;
        if (VertexBuffer)
        {
            return VertexBuffer->VertexColor(Count);
        }
    }
    return { 0,0,0 };
}
