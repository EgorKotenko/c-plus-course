// hw2¹4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"

bool isReducible (int x, int y)
{
	bool flag = true;
	int i = 2; 
	while ((i <= x) && (flag))
	{
		if (y % i == 0)
			flag = false;
		i++;
	}
	
	return flag;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int d = 0;
	printf("Put in your denominator\n");
	scanf("%d", &d);

	printf("All irreducible fractions:\n");

	for (int i = 1; i < d; i++)
		for (int j = i+1; j <= d; j++)
			if (isReducible(i,j))
				printf("%d/%d  ", i, j);

	scanf("%*s");
}

