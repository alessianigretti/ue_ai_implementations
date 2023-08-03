// Fill out your copyright notice in the Description page of Project Settings.


#include "BT_TreeBuilder.h"
#include "BT_FloatDecision.h"
#include "BT_AttackAction.h"
#include "BT_MoveAction.h"

void UBT_TreeBuilder::BuildTree(float input)
{
	// UE_LOG(LogTemp, Warning, TEXT("Building"));

	UBT_FloatDecision* floatDecision = NewObject<UBT_FloatDecision>();
	UBT_AttackAction* attackAction = NewObject<UBT_AttackAction>();
	UBT_MoveAction* moveAction = NewObject<UBT_MoveAction>();

	floatDecision->testValue = input;
	floatDecision->minValue = 0.5f;
	floatDecision->maxValue = 1.0f;
	floatDecision->trueNode = attackAction;
	floatDecision->falseNode = moveAction;

	nodes.push_back(floatDecision);
}

void UBT_TreeBuilder::Run()
{
	// UE_LOG(LogTemp, Warning, TEXT("Running"));

	nodes.at(0)->MakeDecision();
}