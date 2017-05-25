// hw11¹1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "iostream"
#include "time.h"

using namespace std;

void existInNumber(int number, int digit, int position, int &bulls, int &cows)
{
	int num[4];
	num[0] = number / 1000;
	num[1] = (number / 100) % 10;
	num[2] = (number % 100) / 10;
	num[3] = number % 10;

	for (int i = 0; i < 4; i++)
	{
		if (num[i] == digit && position == i+1)
			bulls++;
		else if (num[i] == digit)
			cows++;
	}
}

bool error(int number)
{
	int num[4];
	num[0] = number / 1000;
	num[1] = (number / 100) % 10;
	num[2] = (number % 100) / 10;
	num[3] = number % 10;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (num[i] == num[j] && i != j)
				return true;
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << endl << "Welcome to the 'Bulls & Cows' game! If you want to quit game put in '0' symbol. Let's start!" << endl << endl;
	int variant = 0;
	srand(time(NULL));
	int number = 1000 + rand()%10000;
	while(error(number))
		number = 1000 + rand()%10000;
	//cout << endl << number << endl << endl;
	int cows = 0;
	int bulls = 0;

	bool flag = true;
	while (flag)
	{
		cout << endl << " Your variant: ";
		cin >> variant;
		cows = 0;
		bulls = 0;
		if (variant == 0)
			break;
		else if (error(variant))
			cout << endl << " Error: the are same digits in your variant! Put in another variant." << endl;
		else if (variant < 1000 || variant > 9999)
			cout << endl << " Error: your variant isn't four-digit number! Put in another variant." << endl;
		else if (variant == number)
			flag = false;
		else
		{
			existInNumber(number, variant / 1000, 1, bulls, cows);
			existInNumber(number, (variant / 100) % 10, 2, bulls, cows);
			existInNumber(number, (variant % 100) / 10, 3, bulls, cows);
			existInNumber(number, variant % 10, 4, bulls, cows);
			
			cout << endl << " Cows: " << cows << ", Bulls: " << bulls << endl;
		}
	}
	if (variant == 0)
		cout << endl << " Thank you for trying!" << endl << endl;
	else
		cout << endl << " You win! Number = " << number << endl << endl;

	scanf("%*s");
}

