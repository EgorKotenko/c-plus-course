// hw2№3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"

void sum(int &x, int n[])									
{
	int s = n[x];
	int i = x - 1;
	while ( (i > 1) && (n[i - 1] <= n[i]) )
	{
      s += n[i];
      i--;
	}
    n[i]++;
    x = i + s - 1;
    for (int j = i + 1; j <= x; j++)
      n[j] = 1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int x = 0;
	printf("Put in your number\n");
	scanf("%d", &x);

	printf("All decompositions of your number:\n");

	int n[100];						
    for (int i = 1; i <= x; i++)							//выписываем представление данного числа через все единицы
	{
		n[i] = 1;
		printf("%d ", n[i]);
	}      
    printf("\n");


    while (x != 1)											//выписываем все остальные представления данного числа
	{
		sum(x, n);
        for (int i = 1; i <= x; i++)
			printf("%d ", n[i]);
		printf("\n");
	}

	scanf("%*s");
}

