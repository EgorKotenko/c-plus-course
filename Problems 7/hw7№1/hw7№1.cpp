// hw7¹1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include <iostream>
#include "fstream"
#include "string.h"

using namespace std;

fstream file("hw7.txt");

struct Node    
{
	int value;
	Node *left;
	Node *right;
};

void create(Node *&node, int x)  
{
	Node *t = new Node();
	t->left = NULL;
	t->right = NULL;
	t->value = x;
	node = t;
}

void add(Node *&node, int x)  
{
	if (node == NULL)
		create(node, x);
	else
	{
		if (node->value < x)
			add(node->right, x);
		if (node->value > x)
			add(node->left, x);
	}
}

Node *find(Node *node, int x)  
{
	Node *t = node;
	bool flag = true;
	while ((flag) && (t))
	{
		if (t->value == x)
		{
			flag = false;
		}
		if (t->value < x)
		{
			if ((t->left == NULL) && (t->right == NULL))
				break;
			t = t->right;
		}
		if (t->value > x)
		{
			if ((t->left == NULL) && (t->right == NULL))
				break;
			t = t->left;
		}
	}
	if ((t) && (t->value == x))
		flag = false;
	if (flag)
	{
		return NULL;
	}
	else
		return t;
}

void deleteTree(Node *&node) 
{
	if (node == NULL)
		return;
	else
	{
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
		node = NULL;
		return;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	Node *node1 = NULL;
	Node *node2 = NULL;
	Node *node3 = NULL;

	int a[20];
	int c2;
	int i = 0;
	while (!file.eof())
	{
		file >> a[i];
		file >> c2;
		if (c2 == 1)
			add(node1, a[i]);
		else if (c2 == 2)
			add(node2, a[i]);
		else if (c2 == 3)
			add(node3, a[i]);
		else
		{
			if ((node1) && (find(node1, c2)))
				add(node1, a[i]);
			if ((node2) && (find(node2, c2)))
				add(node2, a[i]);
			if ((node3) && (find(node3, c2)))
				add(node3, a[i]);
		}
		i++;
	}

	

	cout << "Students who hadn't done homework themselves: \n \n";
	
	for (int j = 0; j < i; j++)
	{
		if ((node1) && (find(node1, a[j])))
			cout << "Student #" << a[j] << " cribbed from the first  (1) student\n";
		if ((node2) && (find(node2, a[j])))
			cout << "Student #" << a[j] << " cribbed from the second (2) student\n";
		if ((node3) && (find(node3, a[j])))
			cout << "Student #" << a[j] << " cribbed from the third  (3) student\n";
	}
	

	deleteTree(node1);
	deleteTree(node2);
	deleteTree(node3);

	scanf("%*s");
}

