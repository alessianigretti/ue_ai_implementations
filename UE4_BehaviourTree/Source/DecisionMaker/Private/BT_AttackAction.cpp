// Fill out your copyright notice in the Description page of Project Settings.


#include "BT_AttackAction.h"

UBT_Node* UBT_AttackAction::MakeDecision()
{
	UE_LOG(LogTemp, Warning, TEXT("Attack"));

	UBT_Node* node = this;

	return node;
}