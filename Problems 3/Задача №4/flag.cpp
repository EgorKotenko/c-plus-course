// flag.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "iostream"
#include "list.h"
#include "list.cpp"

using namespace std;

void merge(int a[], int b[], int l, int m, int r)
{
	int k1 = l;
	int k2 = m + 1;
	int i = l;
	while ((k1 < m + 1) && (k2 < r))
	{
		if (a[k1] <= a[k2])
		{
			b[i] = a[k1];
			k1++;
			i++;
		}
		else
		{
			b[i] = a[k2];
			k2++;
			i++;
		}
		
	}
	if (k1 == m + 1)
	{
		for (int j = k1; j < r; j++)
		{
			b[i] = a[j];
			j++;
		}
	}
	if (k2 == r)
	{
		for (int j = k1; j < m+1; j++)
		{
			b[i] = a[j];
			i++;
		}
	}
}

void mergeSort(int a[], int l, int r)
{
	if (l == r - 1) 
		return; 

	if (r - l == 2)
	{
		if (a[l] > a[r-1])
		{
			int temp = a[l];
			a[l] = a[r-1];
			a[r-1] = temp;
		}
		return;
	}

    int m = (l + r) / 2;

    mergeSort(a, l, m+1); 
    mergeSort(a, m+1, r); 

    int b[20]; 

    merge(a, b, l, m, r); 


    for (int i = l; i < r; i++) 
		a[i] = b[i];
}


int _tmain(int argc, _TCHAR* argv[])
{
	List *l = NULL;
	createList(l);

	int n = 0;
	cout << "Put in the number of elements to sort:  ";
	cin >> n;
	cout << "\n";



	int a[20];
	for (int i = 0; i < n; i++)
	{
		cout << "Put in an element:\n";
		cin >> a[i];
	}


	mergeSort(a, 0, n);
	for (int i = 0; i < n; i++)
		addToUnsortedList(l, a[i]);
	cout << "\n";
	cout << "Your sorted list:\n";
	printList(l);
	//for (int i = 0; i < n; i++)
	//	cout << " " << a[i];
	cout << "\n";

	scanf("%*s");
}
