// hw3¹1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"


int quickSort(int a[20], int l, int r)			
{
	int p =(l + r) / 2;						
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

	bool flag = true;
	int i = n-1;
	while ((i > 0) && (flag))
	{
		if(a[i] == a[i-1])
		{
			printf("Maximal not sole element = %d\n", a[i]);
			flag = false;
		}
		i--;
	}
	if (flag)
		printf ("All elements in your massive are sole");

	scanf("%*s");
}

