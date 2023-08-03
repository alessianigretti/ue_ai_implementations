// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PriorityQueue.generated.h"

class UPathGraph;
struct FPathNodeRecord;
struct FPathNode;
struct FPathEdge;

USTRUCT()
struct FElement
{
	GENERATED_BODY()

	float priority;
	FPathNodeRecord* data;
	FElement* next = nullptr;
};

/**
 * 
 */
UCLASS()
class ASTAR_API UPriorityQueue : public UObject
{
	GENERATED_BODY()

public:
	void Insert(FPathNodeRecord* elementToAdd, float priority);
	bool Delete(FPathNodeRecord* elementToDelete);
	FPathNodeRecord* GetSmallestElement();
	bool Contains(FString name);
	FPathNodeRecord* Find(FString name);
	int Count();

private:
	FElement* element = nullptr;
	int count;
};
