// hw2¹2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"

int raiseToPower(int a, int n)
{  
	int temp = 1;  
	while (n > 0) 
	{    
		if (n % 2 == 0) 
		{      
			n = n / 2;      
			a *= a;      
		}    
		else 
		{      
			n--;      
			temp *= a;    
		}  
	}  
	return temp;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int x = 0;
	printf("Put in your number\n");			
	scanf("%d", &x);

	int n = 0;
	printf("Put in the power\n");			
	scanf("%d", &n);

	printf("a ^ n = %d\n", raiseToPower(x,n));

	scanf("%*s");
}

