// hw5№2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include <iostream>
#include "math.h"

using namespace std;

int power(int a, int b)  // возведение целого числа a в степень b (для неотрицательных целых)
{
	if (b == 0) return 1;
	else
	{
		int k = a;
		int c = a;
		for (int i = 1; i < b; i++)
			c *= k;
		return c;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	double d = 0;
	cout << "Put in your number:\n";
	cin >> d;

	cout << "\n";

	unsigned char *c = (unsigned char *)&d + 7;
	int x = *c;

	int i = 0;
	int a[64];

	for (int pointer = 7; pointer >= 0; pointer-- )  // записываем весь двоичный код в массив
	{
		c = (unsigned char *)&d + pointer;
		x = *c;
		
		for (int j = 128; j >= 1; j = j / 2)
		{
			if ((bool)(x & j))
			{
				a[i] = 1;
				i++;
			}
			else
			{
				a[i]= 0;
				i++;
			}
		}

	}


	if (a[0] == 1)  // проверяем положительное ли итоговое число или нет
		cout << "-";  // выводим знак

	
	double m = 0;     // находим мантиссу
	double j = -52;
	for (int i = 63; i > 11; i--)
	{
		m+= a[i]*pow(2,j);
		j++;
	}
	m += 1;
	cout << m;     //выводим мантиссу


	int p = 0;    // находим показатель степени
	int k = 0;
	for (int i = 11; i >= 1; i--)
	{
		p+= a[i]*power(2,k);
		k++;
	}
	p -= 1023; 
	cout << " * 2^(" << p << ")"; // выводим двойку в нужной степени


	 






	cout << "\n";
	scanf("%*s");
}
