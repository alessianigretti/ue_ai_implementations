// Fill out your copyright notice in the Description page of Project Settings.


#include "AStarSearch.h"
#include "PathGraph.h"

// Sets default values for this component's properties
UAStarSearch::UAStarSearch()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UAStarSearch::BeginPlay()
{
	Super::BeginPlay();

	UPathGraph* graph = NewObject<UPathGraph>();
	graph->Build();

	for (FPathEdge* edge : graph->GetPath())
	{
		UE_LOG(LogTemp, Warning, TEXT("Edge %s %s"), *edge->FromNode->Name);
	}
}


// Called every frame
void UAStarSearch::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

