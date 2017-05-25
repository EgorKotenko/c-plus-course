// ¹9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"

int raiseToPower(int a, int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return a;
	else
	{
		int s=a;
		while (n >= 2)
		{
			s *= a;
			n--;
		}
		return s;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int x = 0;
	int n = 0;

	printf("Put in your number\n");			
	scanf("%d", &x);

	printf("Put in the power\n");			
	scanf("%d", &n);
	int a = raiseToPower(x,n);
	printf("a ^ n = %d", a);	

	getch();
}

