// ¹7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"

bool IsPrime(int x)
{
	int k=0;
	for(int i=2;i<x;i++)
		if (x%i==0) 
			k++;
	if (k==0) 
		return true;
	else
		return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int x=0;
	printf("Put in your number\n");			
	scanf("%d", &x);

	printf("All prime numbers from zero to your number:");	

	for(int i=1;i<=x;i++)
		if (IsPrime(i))
			printf(" %d", i);

	getch();
}

