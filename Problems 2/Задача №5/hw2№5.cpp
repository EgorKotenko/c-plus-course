// hw2¹5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"

void moveDown(int first, int last, int heap[])
{
	int lChild = 2 * first;
	int rChild = 2 * first + 1;
	int max = 0;
	if ((lChild <= last) && (heap[first] < heap[lChild]))
		max = lChild;
	else
		max = first;
	if ((rChild <= last) && (heap[max] < heap[rChild]))
		max = rChild;
	if (max != first) 
	{
		int temp = heap[max];
		heap[max] = heap[first];
		heap[first] = temp;
		moveDown(max, last, heap);
	}
}

void heapSort(int heap[], int last)
{
	int temp = last;
	for(int i = last / 2; i > 0; i--)
		moveDown(i, last, heap);
	for(int i = last; i > 1; i--)
	{
		int temp1 =heap[1];
		heap[1] = heap[i];
		heap[i] = temp1;
		temp--;
		moveDown(1, temp, heap);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[20];
	printf("Put in the length of your array\n");
	int n = 0;
	scanf("%d", &n);
	
	printf("Put in your array\n");
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	heapSort(a, n);

	for(int i = 1; i <= n; i++)
		printf("%d ", a[i]);

	printf("\n");
	scanf("%*s");
}