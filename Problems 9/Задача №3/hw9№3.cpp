// hw9¹3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "iostream"
#include "fstream"

using namespace std;

struct road 
{
	int cityFrom, cityTo, length;
};
 
const int veryBigNumber = 1000000;

void printRoads(int minLengths[], int n)
{
	for (int i = 2; i <= n; i++)
		if (minLengths[i] != veryBigNumber)
			cout << endl << " ..to "<< i << " city = "<< minLengths[i] << endl;
		else 
			cout <<  endl << " ..to "<< i << " city = ERROR: there is no information about this city in the input file" << endl;
}

void BellmanFord(int n, int m, int x, int minLengths[], road roads[]) 
{
	for (int i = 1; i <= n; i++)
		minLengths[i] = veryBigNumber;
	minLengths[x] = 0;
	for (int i = 1; i < n; i++)
		for (int j = 1; j <= m; j++)
			//if (minLengths[roads[j].cityFrom] < veryBigNumber)
			if (minLengths[roads[j].cityTo] > minLengths[roads[j].cityFrom] + roads[j].length)
				minLengths[roads[j].cityTo] = minLengths[roads[j].cityFrom] + roads[j].length;
	printRoads(minLengths, n);
}

int _tmain(int argc, _TCHAR* argv[])
{
	fstream file("input.txt");
	int n = 0;
	int m = 0;
	file >> n;
	file >> m;
	
	int x = 1;
	int minLengths[20];
	road roads[20];
	for (int i = 1; i <= m; i++)
	{	
		roads[i].cityFrom = 1;
		roads[i].cityTo = i;
		roads[i].length = 0;
	}
	int i = 1;
	while (!file.eof())
	{
		file >> roads[i].cityFrom;
		file >> roads[i].cityTo;
		file >> roads[i].length;
		i++;
	}

	cout << endl << "The distance from 1 city.. "<< endl;
	BellmanFord(n, m, x, minLengths, roads);

	file.close();
	cout << endl;
	scanf("%*s");
}

