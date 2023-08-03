// Fill out your copyright notice in the Description page of Project Settings.


#include "BT_Decision.h"

UBT_Node* UBT_Decision::GetBranch()
{
	UE_LOG(LogTemp, Warning, TEXT("GetBranch"));

	UBT_Node* node = this;

	return node;
}

UBT_Node* UBT_Decision::MakeDecision()
{
	UE_LOG(LogTemp, Warning, TEXT("MakeDecision"));

	UBT_Node* node = this;

	return node;
}