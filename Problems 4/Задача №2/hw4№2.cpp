// hw4�2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
void printPart()
{
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 0;
	printf("Put in the odd length of the array\n\n");
	scanf("%d", &n);

	printf("\n");

	srand(time(NULL));
	
	int a[11][11];

	for(int i = 0; i < n; i++)							// ��������� ������� ���������� �������
		for(int j = 0; j < n; j++)
			a[i][j] = rand()%10;
	
	printf("Initial matrix:\n\n");

	for(int i = 0; i < n; i++)							// ������� ������������ �������
	{
		for(int j = 0; j < n; j++)
			printf(" %d ", a[i][j]);
		printf("\n\n");
	}

	printf("Elements of the array in an anticlockwise spiral:\n\n");

	int a1[121];   // �������������� ������. � ���� ������ �������� �� ������� (������ �� �� ������, � �� �������� �������� � �� ������� �������) � ���������� ������� �������� ������� ������ � ���. ������.
	int i = 0;		// ������� �����
	int j = 0;		// ������� ��������
	int tempN = n;		// ��������� �������. �� ������ ���� ����� while, � ��� �� ����� ������� - ������ ��������� ������� ��������� � ����� ����������, ���� ��������� ������� � ���������� ������� ���� ������� ������� ��� i � j �� ������� ���� ����� while.
	int k = 0;		// �������, �������� �� ����� ��������������� ������� a.

	while(i < tempN) 
	{
		
		j = n - tempN;

		while (j < tempN)		// ��������� ������� ����� ������� ������� (�����-�������)
		{
			a1[k] = a[i][j];
			k++;
			j++;
		}
		j--;
		i++;

		while (i < tempN)		// ��������� ������ ������� ����� ������� ������� (������-����)
		{
			a1[k] = a[i][j];
			k++;
			i++;
		}
		i--;
		j--;

		while(j >= n - tempN)		// ��������� ������ ����� ������� ������� (������-������)
		{
			a1[k] = a[i][j];
			k++;
			j--;
		}
		j++;
		i--;

		while (i > n - tempN)		// ��������� ����� ������� ����� ������� ������� (�����-�����)
		{
			a1[k] = a[i][j];
			k++;
			i--;
		}
		i++;

		tempN--;
	}

	for(i = n * n - 1; i >= 0; i--)		// ������ ��� �������������� ������ � �����, ��� ��� �� ������� ���������� �������� �������� �������� �� ������, � �� � �������� ��������
		printf(" %d ", a1[i]);
 
	printf("\n\n");       

	scanf("%*s");
}

