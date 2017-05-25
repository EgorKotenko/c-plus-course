// ¹1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int x=0;
	printf("Put in your number \n");
	scanf("%d", &x);
	int temp=x*x;
	int f=(temp+x)*(temp+1);
	printf("f(x) = %d \n", f);
	getch();
}

