// ¹10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include "string.h"

bool IsPalindrom(char str[50])
{
	int temp=1;
	int i=0;
	while ((i<strlen(str)/2)&&(temp==1))
	{
		if (str[i]!=str[strlen(str)-i-1])
			temp=0;
		i++;
	}
	if (temp) 
		return true;
	else
		return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char str[50];
	printf("Put in your string\n");			
	scanf("%s", &str); 
	


	if (IsPalindrom(str)==1)
		printf("Your string is a 'palindrom' ");
	else
		printf("Your string is not a 'palindrom' ");

	

	getch();
}

