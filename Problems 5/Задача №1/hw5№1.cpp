// hw5¹1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "iostream"
#include "fstream"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	fstream file("hw5.txt");
	
	char c;
	bool a[129];
	int i = 0;
	while (!file.eof())
	{
		for (int i = 1; i <= 128; i++)
			a[i] = 0;
		file >> noskipws >> c;
		while ((c != ' ') && (!file.eof()))
		{
			if (a[c] == 0)
			{
				printf("%c", c);
				a[c] = 1;
			}
			file >> noskipws >> c;
		}
		
		cout << " ";
		
	}

	cout << "\n";
	scanf("%*s");
}

