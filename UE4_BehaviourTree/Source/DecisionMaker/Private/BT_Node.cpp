// Fill out your copyright notice in the Description page of Project Settings.


#include "BT_Node.h"

UBT_Node* UBT_Node::MakeDecision()
{
	UE_LOG(LogTemp, Warning, TEXT("Node"));

	UBT_Node* node = NewObject<UBT_Node>();

	return node;
}