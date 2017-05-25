// №8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
					
int RecFactorial(int x)									//рекурсивный подсчёт факториала             
{
	if (x<=1)
		return 1;
	else return x*RecFactorial(x-1);
}

int IterFactorial(int x)								//итеративный подсчёт факториала
{
	int temp=1;
	for (int i=1;i<=x;i++)
		temp*=i;
	return temp;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int x=0;
	printf("Put in your number\n");			
	scanf("%d", &x);
	
	printf("x! = %d", RecFactorial(x));	
	//printf("x! = %d", IterFactorial(x));

	getch();
}

