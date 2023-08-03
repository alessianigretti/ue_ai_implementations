// Fill out your copyright notice in the Description page of Project Settings.


#include "BT_MoveAction.h"

UBT_Node* UBT_MoveAction::MakeDecision()
{
	UE_LOG(LogTemp, Warning, TEXT("Move"));

	UBT_Node* node = this;

	return node;
}