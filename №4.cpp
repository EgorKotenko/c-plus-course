// ¹4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
			
int _tmain(int argc, _TCHAR* argv[])
{
	int a[28];
	for(int i=0;i<=27;i++)
		a[i]=0;
	
	int s=0;
	for (int i=1;i<=999;i++)
	{
		s=(i/100)+(i%10)+(i%100)/10;
		a[s]++;
	}

	int n=0;
	for (int i=0;i<=27;i++)
		n+=a[i]*a[i];

	printf("The quantity of 'Lucky Tickets' = %d\n", n);


	getch();
}

