// ¹5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include "string.h"


int _tmain(int argc, _TCHAR* argv[])
{
	char str[20];
	printf("Put in your sequence of brackets \n");
	scanf("%s", &str);
	int k=0;
	int i=0;
	while ((i<strlen(str))&&(k>=0))
	{
			if (str[i]=='(') 
				k++;
			if (str[i]==')')
				k--;
			i++;
	}
	if (k==0) printf("Your sequence is correct");
	else printf("Your sequence is incorrect");
	
	getch();
}

