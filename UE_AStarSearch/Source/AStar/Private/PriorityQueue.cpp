// Fill out your copyright notice in the Description page of Project Settings.


#include "PriorityQueue.h"
#include "PathGraph.h"

void UPriorityQueue::Insert(FPathNodeRecord* elementToAdd, float priority)
{
	FElement t, *q;
	t.priority = priority;
	t.data = elementToAdd;

	if (element == nullptr || priority < element->priority)
	{
		t.next = element;
		element = &t;
	}
	else
	{
		q = element;
		while (q->next != nullptr && q->next->priority <= priority)
		{
			q = q->next;
		}
		t.next = q->next;
		q->next = &t;
	}
	count++;
}

bool UPriorityQueue::Delete(FPathNodeRecord* elementToDelete)
{
	FElement* e = element;
	if (element == nullptr)
	{
		return false;
	}

	if (e->data->Node->Name == elementToDelete->Node->Name)
	{
		e = e->next;
		return true;
	}

	while (e->next != nullptr)
	{
		if (e->next->data->Node->Name == elementToDelete->Node->Name)
		{
			e->next = e->next->next;
			return true;
		}
		else
		{
			e = e->next;
		}
	}

	return false;
}

FPathNodeRecord* UPriorityQueue::GetSmallestElement()
{
	return element->data;
}

bool UPriorityQueue::Contains(FString name)
{
	FElement* e = element;
	if (e->data->Node->Name == name)
	{
		return true;
	}

	while (e->next != nullptr)
	{
		if (e->next->data->Node->Name == name)
		{
			return true;
		}
		else
		{
			e = e->next;
		}
	}

	return false;
}

FPathNodeRecord* UPriorityQueue::Find(FString name)
{
	FElement* e = element;
	if (element == nullptr)
	{
		return nullptr;
	}

	if (e->data->Node->Name == name)
	{
		return e->data;
	}

	while (e->next != nullptr)
	{
		if (e->next->data->Node->Name == name)
		{
			return e->next->data;
		}
		else
		{
			e = e->next;
		}
	}

	return nullptr;
}

int UPriorityQueue::Count()
{
	return count;
}