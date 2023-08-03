// Fill out your copyright notice in the Description page of Project Settings.


#include "BT_MultiDecision.h"

UBT_Node* UBT_MultiDecision::GetBranch()
{
	return &daughterNodes[testValue];
}