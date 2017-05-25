#include "stdafx.h"
#include "stdio.h"

struct List
{
	int value;
	List *next;
};

void createList(List *&input)
{
	List *l1 = new List();
	l1->next = NULL;
	l1->value = 0;
	input = l1;
}

void addElementToList(List *&input, int number)
{
	List* index = input;
	if (input->next == NULL)
	{
		List *temp = new List();
		index->next = temp;
		temp->next = NULL;
		temp->value = number;
	}
	else
	{

		bool flag = true;
		while ((flag) && (number < index->next->value))
		{
			index = index->next;
			if (index->next == NULL)
				flag = false;
		}
		List *temp = new List();
		if (flag)
		{
			temp->next = index->next;
			index->next = temp;
			temp->value = number;
		}
		else
		{
			index->next = temp;
			temp->next = NULL;
			temp->value = number;
		}
	}
}

void removeElementFromList(List *&input, int number)
{
	List* index = input;

	while (number != index->next->value)
		index = index->next;

	List *temp = index->next;
	index->next = temp->next;
	delete temp;
}

void printList(List *&input)
{
	List *index = input->next;
	while (index->next != NULL)
	{
		printf("  %d", index->value);
		index = index->next;
	}
	printf("  %d", index->value);
	printf("\n");
}

void deleteList(List *&input)
{
	List *index = input->next;
	if (index)
		deleteList(index);
	delete (index);

}

void addToUnsortedList(List *&input, int x)
{
	List *l = new List();
	l->next = NULL;
	l->value = x;
	List *temp = input;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = l;
}