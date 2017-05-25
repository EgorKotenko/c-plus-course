// ¹2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int a=0;
	int b=0;
	printf("Put in the first number\n");
	scanf("%d", &a); 
	printf("Put in the second number\n");
	scanf("%d", &b); 

	if (a<b)
		printf("a<b => incomplete quotient = 0");
	else
	{
		int i=0;
		while(a-b>=0)
		{
			a-=b;
			i++;
		}

		printf("Incomplete quotient = %d", i);
	}

	getch();
}

