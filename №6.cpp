// ¹6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include "string.h"

int _tmain(int argc, _TCHAR* argv[])
{
	char str1[20];
	char str2[20];
	printf("Put in the first string\n");
	scanf("%s", &str1);
	printf("Put in the second string\n");
	scanf("%s", &str2);

	int k = 0;
	for (int i = 0;i <= strlen(str1)-strlen(str2); i++)
	{
		if (str1[i] == str2[0])
		{
			bool flag = true;
			int j = 1;
			while ((j < strlen(str2))&&(flag))
			{
				if (str2[j] != str1[i+j])
					flag = false;
				j++;
			}
			if (flag == true)
				k++;
		}
	}

	printf("The number of entries = %d", k);

	getch();
}

