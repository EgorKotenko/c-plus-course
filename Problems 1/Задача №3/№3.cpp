// �3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"



int _tmain(int argc, _TCHAR* argv[])
{
	int m=0;
	int n=0;
	int a[50];

	printf("Put in the length of the first section of your array\n");			//�������� ����� ������� "�������" �������
	scanf("%d", &m);

	printf("Put in the length of the second section of your array\n");			//�������� ����� ������� "�������" �������
	scanf("%d", &n);

	printf("Put in your array\n");												//�������� ��������������� ������
	for (int i=0;i<m+n;i++)
		scanf("%d", &a[i]);
	
	int temp=0;

	for (int i=0;i<m;i++)														//"��������������" ������ "�������" �������
	{
		temp=a[i];
		a[i]=a[m-i-1];
		a[m-i-1]=temp;
	}

	for (int i=m;i<m+n;i++)														//"��������������" ������ "�������" �������
	{
		temp=a[i];
		a[i]=a[m+n-i-1];
		a[m+n-i-1]=temp;
	}

	printf("Reversed array: ");													//������� "�����������" ������ �������
	for (int i=0;i<n+m;i++)
		printf(" %d", a[i]);

	getch();
}

