// hw4№2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
void printPart()
{
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 0;
	printf("Put in the odd length of the array\n\n");
	scanf("%d", &n);

	printf("\n");

	srand(time(NULL));
	
	int a[11][11];

	for(int i = 0; i < n; i++)							// заполняем матрицу рандомными цифрами
		for(int j = 0; j < n; j++)
			a[i][j] = rand()%10;
	
	printf("Initial matrix:\n\n");

	for(int i = 0; i < n; i++)							// выводим получившуюся матрицу
	{
		for(int j = 0; j < n; j++)
			printf(" %d ", a[i][j]);
		printf("\n\n");
	}

	printf("Elements of the array in an anticlockwise spiral:\n\n");

	int a1[121];   // дополнительный массив. Я буду бежать спиралью по матрице (только не из центра, а из нулевого элемента и по часовой стрелке) и записывать текущие элементы матрицы подряд в доп. массив.
	int i = 0;		// счётчик строк
	int j = 0;		// счётчик столбцов
	int tempN = n;		// некоторый счётчик. на каждом шаге цикла while, я иду по новой спирали - каждая следующая спираль находится в нутри предыдущей, этот некоторый счётчик и показывает границы моей текущей спирали для i и j на текущем шаге цикла while.
	int k = 0;		// счётчик, бегающий по моему дополнительному массиву a.

	while(i < tempN) 
	{
		
		j = n - tempN;

		while (j < tempN)		// пробегаем верхнюю линию спирали текущей (слева-направо)
		{
			a1[k] = a[i][j];
			k++;
			j++;
		}
		j--;
		i++;

		while (i < tempN)		// пробегаем правую боковую линию текущей спирали (сверху-вниз)
		{
			a1[k] = a[i][j];
			k++;
			i++;
		}
		i--;
		j--;

		while(j >= n - tempN)		// пробегаем нижнюю линию текущей спирали (справа-налево)
		{
			a1[k] = a[i][j];
			k++;
			j--;
		}
		j++;
		i--;

		while (i > n - tempN)		// пробегаем левую боковую линию текущей спирали (снизу-вверх)
		{
			a1[k] = a[i][j];
			k++;
			i--;
		}
		i++;

		tempN--;
	}

	for(i = n * n - 1; i >= 0; i--)		// вывожу мой дополнительный массив с конца, так как по условию необходимо выводить элементы спиралью из центра, а не с нулевого элемента
		printf(" %d ", a1[i]);
 
	printf("\n\n");       

	scanf("%*s");
}

