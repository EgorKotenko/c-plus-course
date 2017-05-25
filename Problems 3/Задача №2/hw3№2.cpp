// hw3�2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"

struct List   
{
	int value;
	List *next;
};

void createList(List *&newList, int n) // ������ ������ �� n ��������, ��������� �������� ������� �������� - ��� ��� ���������� �����
{
	List *l = new List();
	newList = l;

	List *index = l;  // ��������� ���������, ������� �� ������
	index->value = 1;

	for (int i = 1; i < n; i++)
	{		
		List *temp = new List();
		index->next = temp;
		index = temp;
		index->value = i + 1;
	}

	index->next = newList;  // ������������ ������
}

void deleteElement(List *&index, int x) // �������� �������� � ���������� ������� x
{
	int i = 1;
	while(i < x - 1)
	{
		index = index->next;
		i++;
	}


	List *temp = index;
	temp = temp->next;
	index->next = temp->next;
	index = temp->next;
	delete(temp);

	//printf("%d\n", index->value);
	
}

void deleteList(List *&list, int length, int step) // �������� ������
{
	List *temp = list->next;
	if ((list) && (step < length))	
		deleteList(temp, length, step + 1);
	delete(list);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 0;
	int lastElement = 0;
	printf("Put in the length of cyclic list\n");
	scanf("%d", &n);
	printf("Put in the element which has to 'survive'\n");
	scanf("%d", &lastElement);
	printf("\n");
	List *list = NULL;
	createList(list,n);
	List *index = list;

	

	bool flag = true;
	for (int k = 2; k <= n; k++) // ���������� ��� ���� - �� �������� ������� ������� �� ������� n-���� (������ ������ �� �������������)
	{
		while (index->next != index) // ������� ������ k-��� �������, ���� � ������ �� ��������� ������ ����
			deleteElement(index, k);

		if (index->value == lastElement) // ���� ������� ����������� �������� � ��������� ������ - ��������� � �������� ��� ��������, �� ������� ������� ��� k
		{
			printf("Right value of 'k' = %d\n", k);
			flag = false;
		}

		deleteElement(index, 1); // ������� �������, ���������� ����� �������� ������� k-��� ��������

		createList(list, n); // ��������������� �������� ������
		index = list;
	}
	if (flag) 
		printf("This element will always go out\n");
	deleteList(list, n, 1); // ������� ������


	scanf("%*s");	
}

