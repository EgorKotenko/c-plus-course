// hw9№2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "iostream"
#include "fstream"
#include "string.h"
#include "iomanip"
#include "math.h"

using namespace std;

int power(int a, int b)
{
	int res = a;
	for (int i = 1; i < b; i++)
	{
		res *= a;
	}
	return res;
}

int hashString(char s[], int len)
{
	int temp = 0;
	int k = 7;
	for (int i = 0; i < len; i++)
	{
		temp += ((s[i] - ' ' + 1) * power(k, i + 1));
	}
	if (temp < 0)
		return (-1)*(temp);
	else
		return temp;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char s[256];
	char sub[256];
	int l = 0; // счётчик

	cout << "Put in your string:" << endl;
	cin.getline(s, 256);
	cout << endl << "Put in your substring:" << endl;
	cin.getline(sub, 256);
	int sLength = strlen(s);
	int subLength = strlen(sub);

	int k = 7;
	int k1 = power(k, subLength);
	
	char sconst[256];
	int hsub = hashString(sub, subLength);
	for (int i = 0; i < subLength; i++)
			sconst[i] = s[i];


	int hconst = hashString(sconst, subLength);
	if (hconst == hsub)
		{
			int p = 0;
			bool flag = true;
			while ((flag) && (p < subLength))
			{
				if (sub[p] != sconst[p])
					flag = false;
				p++;
			}
			if (flag)
				l++;
		}


	for (int j = 1; j < sLength - subLength + 1; j++)
	{
		char stemp[256];
		for (int i = 0; i < subLength; i++)
			stemp[i] = s[i+j];

		int htemp = hconst / k  - (s[j - 1] - ' ' + 1) + (s[j + subLength - 1] - ' ' + 1) * k1 ; // через hconst
		
		if (htemp > 0)
			hconst = htemp;
		else 
			hconst = (-1)*htemp;

		if (hconst == hsub)
		{
			int p = 0;
			bool flag = true;
			while ((flag) && (p < subLength))
			{
				if (sub[p] != stemp[p])
					flag = false;
				p++;
			}
			if (flag)
				l++;
		}
			
	}

	cout << endl << "The number of occurrences of your substring: " << l << endl << endl;

	scanf("%*s");
}

