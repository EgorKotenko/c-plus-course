// hw2№1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"

int recFibonachchi(int x)												//рекурсивный подсчёт числа фибоначчи
{
	if ((x == 1) || (x == 2))
		return 1;
	else 
		return recFibonachchi(x-1) + recFibonachchi(x-2);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 0;
	printf("Put in your number of the Fibonschchi row\n");
	scanf("%d", &n);
	if ((n == 1) || (n == 2))											//итеративный подсчёт числа фибоначчи
		printf("Your Fibonachchi number = 1\n");
	else
	{
		int a[20];
		a[0] = 1;
		a[1] = 1;
		int i = 2;
		while (i < n)
		{
			a[i] = a[i - 1] + a[i - 2];
			i++;
		}
		printf("Your Fibonachchi number = %d\n", a[i - 1]);
	}
	
	//printf("Your Fibonachchi number = %d\n", recFibonachchi(n));        

	scanf("%*s");
}

