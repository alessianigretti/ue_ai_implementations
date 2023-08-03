// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviourTree.h"
#include "BT_TreeBuilder.h"

// Sets default values for this component's properties
UBehaviourTree::UBehaviourTree()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UBehaviourTree::BeginPlay()
{
	Super::BeginPlay();

	RunTree();
}


// Called every frame
void UBehaviourTree::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

#if WITH_EDITOR
void UBehaviourTree::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	FName PropertyName = (PropertyChangedEvent.Property != NULL) ? PropertyChangedEvent.Property->GetFName() : NAME_None;

	if ((PropertyName == GET_MEMBER_NAME_CHECKED(UBehaviourTree, Input)) || (PropertyName == GET_MEMBER_NAME_CHECKED(UBehaviourTree, Input)))
	{
		RunTree();
	}
}
#endif

void UBehaviourTree::RunTree()
{
	UBT_TreeBuilder* tree = NewObject<UBT_TreeBuilder>();
	tree->BuildTree(Input);
	tree->Run();
}
