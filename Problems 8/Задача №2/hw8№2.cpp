// hw8№2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "iostream"
#include "fstream"

using namespace std;

int nearestCity(int index, int a1[], bool temp[], int n, int m, int lenFromFirst[]) // возвращает ближайший город к городу index
{
	int a[20][20];
	int k = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			a[i][j] = a1[k];
			k++;
		}

	int dist[20];
	for (int i = 0; i < n; i++)
		dist[i] = 0;

	int len = 0;
	int len2 = 0;
	int opt = 0;
	for (int i = 0; i < m; i++)
	{
		
		if (a[i][index])
		{
			bool t = true;
			int l = 0;
			while (t)
			{
				if ((a[i][l] == a[i][index]) && (l != index))
					t = false;
				else
					l++;
			}
			if (temp[l] == true)
			{
				dist[len] = a[i][l];
				len++;
			}
			else 
			{
				opt = l;
				len2++;
			}
		}
	}

	if ((len2 == 1) && (len == 0))
	{
		temp[index] = false;
		return nearestCity(opt, a1, temp, n, m, lenFromFirst);
	}
	else
	{
		int s = 0;
		for (int i = 0; i < len; i++)
		{
			s += dist[i];
		}

		if (s == 0)
			return 0;
		else
		{

			int min = dist[0];
			for (int i = 0; i < len; i++)
			{
				if (dist[i] < min)
					min = dist[i];
			}
		
			bool f = true;
			int x = 0;
			int l = 0;
			while (f)
			{
				if (a[x][index] == min) 
				{
					int l1 = 0;
					bool t1 = true;
					while (t1)
					{
						if ((a[x][l1] == min) && (l1 != index))
							t1 = false;
						else
							l1++;
					}
					x++;
					l = l1;
					if (temp[l1] == true)
					{
						f = false;
						x--;
					}
					
				}
				else
					x++;
			}

		
		//	int l = 0;
		/*	bool t = true;
			while (t)
			{
				if ((a[x][l] == a[x][index]) && (l != index))
					t = false;
				else
					l++;
			}
			*/
			for (int i = 0; i < m; i++)
			{
		
				if (a[i][index])
				{
					bool t = true;
					int l1 = 0;
					while (t)
					{
						if ((a[i][l1] == a[i][index]) && (l1 != index))
							t = false;
						else
							l1++;
					}
					
					int lenTemp = lenFromFirst[index] + a[i][l1];
					if (lenTemp < lenFromFirst[l1])
						lenFromFirst[l1] = lenTemp;
				}
			}
			

			//lenFromFirst[l] += lenFromFirst[index] + a[x][l];

			return l;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	fstream file("input.txt");

	int a[20][20];
	int lenFromFirst[20];
	int n = 0;
	int m = 0;
	file >> n;
	file >> m;

	
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = 0;

	int i = 0;
	int j = 0;
	int len = 0;
	int k = 0;
	while (!file.eof())
	{
		file >> i;
		file >> j;
		file >> len;
		a[k][i - 1] = len;
		a[k][j - 1] = len;
		k++;
	}
	
	lenFromFirst[0] = 0;
	for (int i = 1; i < n; i++)
		lenFromFirst[i] = 100500;

	int a1[1000];
	k = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			a1[k] = a[i][j];
			k++;
		}

	cout << "Captured cities:" << endl << endl;
	cout << " 1" << endl;
	bool temp[20];
	for (int i = 0; i < n; i++)
		temp[i] = true;
		
	int index = 0;

	bool flag = true;
	while (flag)
	{
		int l = nearestCity(index, a1, temp, n, m, lenFromFirst);

		if (l == 0)
		{
			flag = false;
			temp[index] = false;
		}
		else
		{
			cout << " " << l + 1 << endl;
			temp[index] = false;
			index = l;
		}
		
	}

	cout << endl << "Number of city: " << "  Distance from the first city: " << endl;
	for (int i = 0; i < n; i++) 
	{
		if (lenFromFirst[i] == 100500)
			cout << " " << i + 1 << "                  -" << endl;
		else
			cout << " " << i + 1 << "                  " << lenFromFirst[i] << endl;
	}
		
	
	file.close();
	cout << endl;
	scanf("%*s");
}
