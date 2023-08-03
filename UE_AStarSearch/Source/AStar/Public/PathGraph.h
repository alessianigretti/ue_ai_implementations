// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PriorityQueue.h"
#include "UObject/NoExportTypes.h"
#include "PathGraph.generated.h"

UENUM()
enum ENodeStateType
{
	Unvisited,
	Visited,
	Closed
};

USTRUCT()
struct FPathEdge
{
	GENERATED_BODY()

	FPathNode* FromNode;
	FPathNode* ToNode;

	UPROPERTY()
	float TraversalCost;
};

USTRUCT()
struct FPathNode
{
	GENERATED_BODY()

	UPROPERTY()
	FString Name;

	TArray<FPathEdge*> Edges;
};

USTRUCT()
struct FPathNodeRecord
{
	GENERATED_BODY()

	FPathNode* Node;

	UPROPERTY()
	float HeuristicValue;

	UPROPERTY()
	float CostSoFarValue;

	FPathEdge* Connection;

	UPROPERTY()
	float EstimatedTotalCost;

	UPROPERTY()
	TEnumAsByte<ENodeStateType> StateType;
};

/**
 * 
 */
UCLASS()
class ASTAR_API UPathGraph : public UObject
{
	GENERATED_BODY()

public:
	void Build();
	TArray<FPathEdge*> GetPath();

	UPROPERTY()
	TArray<FPathNode> Nodes;

private:
	float GetHeuristicValue(FPathNode* node);

	FPathNode* start;
	FPathNode* goal;

	UPriorityQueue* open;
	UPriorityQueue* closed;
};
