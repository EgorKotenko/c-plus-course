// hw3№2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"

struct List   
{
	int value;
	List *next;
};

void createList(List *&newList, int n) // создаём список из n элеметов, численное значение каждого элемента - это его порядковый номер
{
	List *l = new List();
	newList = l;

	List *index = l;  // временный указатель, бегущий по списку
	index->value = 1;

	for (int i = 1; i < n; i++)
	{		
		List *temp = new List();
		index->next = temp;
		index = temp;
		index->value = i + 1;
	}

	index->next = newList;  // зацикливание списка
}

void deleteElement(List *&index, int x) // удаление элемента с порядковым номером x
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

void deleteList(List *&list, int length, int step) // удаление списка
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
	for (int k = 2; k <= n; k++) // перебираем все шаги - от удаления каждого второго до каждого n-ного (каждый первый не рассматриваем)
	{
		while (index->next != index) // удаляем каждый k-тый элемент, пока в списке не останется только один
			deleteElement(index, k);

		if (index->value == lastElement) // если позиция оставшегося элемента в начальном списке - совпадает с заданной нам позицией, то выводим текущий шаг k
		{
			printf("Right value of 'k' = %d\n", k);
			flag = false;
		}

		deleteElement(index, 1); // удаляем элемент, оставшийся после удалений каждого k-ого элемента

		createList(list, n); // восстанавливаем исходный список
		index = list;
	}
	if (flag) 
		printf("This element will always go out\n");
	deleteList(list, n, 1); // удаляем список


	scanf("%*s");	
}

