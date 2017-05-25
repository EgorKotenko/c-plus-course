// hw11_1.cpp : Defines the entry point for the console application.
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

bool isNumberCorrect(char s[], int n) // разбор корректности числа с плавающей точкой
{
	state pos = init;
	char curr;
	char temp;
	bool flag = true;
	int i = 0;
	while (flag && i < n)
	{
		curr = s[i];
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
				flag = false;
				break;
			case end1:			
				break;
		}
		i++;
	}
	if (pos == error)
		flag =false;
	return flag;
}

void isSignCorrect(char c) // разбор корректности знака
{
	// it's correct
} 

int _tmain(int argc, _TCHAR* argv[])
{
	fstream file("input.txt");
	char curr;
	cout << endl << " Your expression: ";
	bool flag = true;
	while (!file.eof() && flag)
	{
		file >> noskipws >> curr;
		cout << curr;
		
		if (curr >= '0' && curr <= '9')
		{
			char temp = ' ';
			char str[100];
			str[0] = curr;
			int i = 1;
			while ((temp != '+' && temp != '-' && temp != '*' && temp != '/') && (!file.eof()))
			{
				file >> noskipws >> temp;
				if (temp != '+' && temp != '-')
					cout << temp;
				else
				{
					char c;
					file.unget();
					file.unget();
					file >> noskipws >> c;
					if (c =='E' || c =='e')
						cout << temp;
					file >> noskipws >> c;
				}

				if (temp == '+' || temp == '-')
				{
					file.unget();
					file.unget();
					file >> noskipws >> temp;
					if (temp != 'e' && temp != 'E')
						break;
					else
					{
						file >> noskipws >> temp;
						str[i] = temp;
						i++;
					}
				}
				else if (temp == '/' || temp == '*')
					break;
				else
				{
					str[i] = temp;
					i++;
				}

			}
			if (!isNumberCorrect(str, i))
			{
				flag = false;
				break;
			}
		}


		else if (curr == '*' || curr == '/' || curr == '+' || curr == '-')
		{
			isSignCorrect(curr);
		}

		else 
		{
			flag = false;
			break;
		}
	}
	
	if (flag)
		cout << endl << " Your expression is correct";
	else
		cout << " ...!!!" << endl << endl << " ERROR: your expression is not correct";
	file.close();
	cout << endl << endl;
	scanf("%*s");
}

