// Fill out your copyright notice in the Description page of Project Settings.


#include "BT_FloatDecision.h"

UBT_Node* UBT_FloatDecision::GetBranch()
{
	if (maxValue >= testValue && testValue >= minValue)
	{
		return trueNode;
	}
	else
	{
		return falseNode;
	}
}

UBT_Node* UBT_FloatDecision::MakeDecision()
{
	return GetBranch()->MakeDecision();
}
