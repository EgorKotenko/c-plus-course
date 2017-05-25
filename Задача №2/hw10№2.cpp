// hw10¹2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string.h"
#include "fstream"

using namespace std;

enum state
{
	init, sign1, number1, dot, number2, expa, sign2, number3, error, end1
};

bool isSign(char c)
{
	if (c == '+' || c == '-')
		return true; 
	return false;
}

bool isDigit(char c)
{
	if (c >= '0' && c <= '9')
		return true; 
	return false;
}

bool isDot(char c)
{
	if (c == '.')
		return true; 
	return false;
}

bool isExp(char c)
{
	if (c == 'e' || c == 'E')
		return true; 
	return false;
}

bool isEnd(char c)
{
	if (c == '\n')
		return true; 
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//cout << "Put in your number" << endl << endl << " ";
	//char s[100];
	//cin >> s;
	fstream file("input.txt");
	state pos = init;
	char curr;
	char temp;
	bool flag = true;
	cout << endl << " Your number: ";
	while (flag)
	{
		file >> noskipws >> curr;
		cout << curr;
		switch (pos)
		{
			case init:
				if (isSign(curr))
					pos = sign1;
				else if (isDigit(curr))
					pos = number1;
				else 
				{
					pos = error;
					temp = curr;
				}
				break;
			case sign1:
				if (isDigit(curr))
					pos = number1;
				else 
				{
					pos = error;
					temp = curr;
				}
				break;
			case number1:
				if (isDot(curr))
					pos = dot;
				else if (isDigit(curr))
					pos = number1;
				else if (isEnd(curr))
					pos = end1;
				else 
				{
					pos = error;
					temp = curr;
				}
				break;
			case dot:
				if (isDigit(curr))
					pos = number2;
				else 
				{
					pos = error;
					temp = curr;
				}
				break;
			case number2:
				if (isExp(curr))
					pos = expa;
				else if (isDigit(curr))
					pos = number2;
				else if (isEnd(curr))
					pos = end1;
				else 
				{
					pos = error;
					temp = curr;
				}
				break;
			case expa:
				if (isSign(curr))
					pos = sign2;
				else if (isDigit(curr))
					pos = number3;
				else 
				{
					pos = error;
					temp = curr;
				}
				break;
			case sign2:
				if (isDigit(curr))
					pos = number3;
				else if (isEnd(curr))
					pos = end1;
				else 
				{
					pos = error;
					temp = curr;
				}
				break;
			case number3:
				if (isDigit(curr))
					pos = number3;
				else if (isEnd(curr))
					pos = end1;
				else 
				{
					pos = error;
					temp = curr;
				}
				break;
			case error:
				cout << endl << endl << " Error: mistake in symbol '" << temp << "'" << endl;
				flag = false;
				break;
			case end1:
				cout << " Your number is correct!" << endl;
				flag = false;
				break;
		}
	}
	file.close();
	cout << endl;
	scanf("%*s");
}

