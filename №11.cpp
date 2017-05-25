// №11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"

int quickSort(int a[20], int l, int r)			// a - рассматриваемый массив(часть массива), l - левая граница, r - правай граница
{
	int p =(l + r) / 2;							// p - индекс опорного элемента
	int i = l;
	int j = r;
	while (i <= j) 
	{
		while (a[i] < a[p]) 
			i++;
		while (a[j] > a[p])
			j--;
		if (i <= j)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	if (l < j)									 
		quickSort(a, l, j);
	if (i < r) 
		quickSort(a, i, r);
	return 1;
}

int _tmain(int argc, _TCHAR* argv[])
{

	int a[20];
	int n = 0;
	printf("Put in the length of your array\n");
	scanf("%d", &n);
	printf("Put in your array\n");
	for( int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	quickSort(a, 0, n-1);

	printf("Your 'quicksorted' array:\n");
	for( int i = 0; i < n; i++)
		printf("%d ", a[i]);

	getch();
}

