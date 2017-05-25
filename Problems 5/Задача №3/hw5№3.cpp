// hw5¹3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "iostream"
#include "fstream"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	
	fstream file("hw5_3.txt");
	
	char s[50];
	char c;
	char a[5];
	int i = 0;
	while (!file.eof())
	{
		
	    i = 0;
		file >> noskipws >> c;
		while ((c != '/') && (!file.eof()))
		{
			//if (c == '\n')
				//cout << "\n";
			file >> noskipws >> c;
		}
		cout << c;
		
		while ((c != '\n') && (!file.eof()))
		{
			file >> c;
			cout << c;
		}

		
	}

	cout << "\n";
	scanf("%*s");
}

