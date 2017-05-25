// hw8¹1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "iostream"

using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void bubbleSort(int a[], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - 1; j++)
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Put in the number of elements: ";
	int n = 0;
	cin >> n;
	cout << "\n";
	int a[20];
	for (int i = 0; i < n; i++)
	{
		cout << "Put in the element: ";
		cin >> a[i];
		cout << "\n";
	}
	
	bubbleSort(a, n);

	for (int i = 0; i < n; i++)
		cout << " " << a[i];

	cout << "\n\n";

	scanf("%*s");
}

