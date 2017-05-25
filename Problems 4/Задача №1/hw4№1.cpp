// hw4¹1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"

int _tmain(int argc, _TCHAR* argv[])
{
	char s1[20];
	char s2[20];
	printf("Put in the first string\n");
	scanf("%s", &s1);
	printf("Put in the second string\n");
	scanf("%s", &s2);

	int a[20];
	int b[20];
	for (int i = 0; i < strlen(s2); i++)
	{
		a[i] = 0;
		b[i] = 0;
		}
	
	
	for (int i = 0; i < strlen(s2); i++)
	{
		int j = 0;
		bool flag = true;
		while ((j < strlen(s1)) && (flag))
		{
			if ((s2[i] == s1[j]) && (b[j] == 0))
			{
				a[i]++;
				b[j]++;
				flag = false;
			}
			j++;
		}
	}

	bool flag = true;

	int i = 0;
	while ((flag) && (i < strlen(s2)))
	{
		if (a[i] == 0)
		{
			flag = false;
			printf("It is impossible to make the second string from the first one\n");
		}
		i++;
	}

	if (flag) 
		printf("It is possible to make the second string from the first one\n");
		
	

	scanf("%*s");
}

