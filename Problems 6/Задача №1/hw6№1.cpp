// hw6№1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include <iostream>

using namespace std;

struct Node    
{
	int value;
	Node *left;
	Node *right;
};

void create(Node *&node, int x)  // создание узла со значением x в корне и пустыми "детьми"
{
	Node *t = new Node();
	t->left = NULL;
	t->right = NULL;
	t->value = x;
	node = t;
}

void add(Node *&node, int x)  // добавление узла в дерево
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

Node *find(Node *node, int x) // возвращает новое дерево с корнем в узле исходного дерева со значением х, иди возвращает NULL, если в исходном дереве не было узла со значением х
{
	Node *t = node;
	bool flag = true;
	while (flag)
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
	if (t->value == x)
		flag = false;
	if (flag)
	{
		return NULL;
	}
	else
		return t;
}

Node* remove(Node *&node, int x) // возвращает дерево без узла со значением х
{ 
	Node *t;  
	if (node == NULL) return 0;
	if (x == node->value)   
	{ 
		if (node->left == NULL)
		{ 
			t = node->right;	   
			delete node;    
			return t;  
		}     
		t = node->left;
		while(t->right) 
			t = t->right;
		t->right = node->right;       
		return node->left;     
	}
	if (x < node->value)     
		node->left = remove(node->left, x);
	else   
		node->right = remove(node->right, x);
	return node;
}

void ascendingOrder(Node *node) // выводит значения в узлах дерева по возрастанию
{
	if (node == NULL)
		return;
	ascendingOrder(node->left);
	cout << "  " << node->value;
	ascendingOrder(node->right);
}

void descendingOrder(Node *node) // выводит значения в узлах дерева по убыванию
{
	if (node == NULL)
		return;
	descendingOrder(node->right);
	cout << "  " << node->value;
	ascendingOrder(node->left);
}

void deleteTree(Node *&node) // удаление дерева
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
	printf("\n Available options:\n\n  0  -  Exit\n  1  -  Add value to the set\n  2  -  Remove value from the set\n  3  -  Find value in the set \n  4  -  Print the set in ascending ordering\n  5  -  Print the set in descending order\n");
	printf(" ______________________________________________________________________________\n");
	
	Node *t = NULL;

	int c = 4;

	while (c != 0)
	{
		printf("\n Put in the number of an option, please:  ");
		scanf("%d", &c);
		printf("\n");

		if (c == 0)
		{
			printf(" Thank you for using our service!\n");
		}
		else if (c == 1)
		{

			int x = 0;
			printf(" Put in your value, please: ");
			scanf("%d", &x);
			printf("\n");
			add(t, x);
			printf(" Operation completed\n");
			
		}
		else if (c == 2)
		{	
			if (t == NULL)
			{
				printf(" There are no elements to remove, the set is empty\n");
			}
			else
			{
				int x = 0;
				printf(" Put in your value, please: ");
				scanf("%d", &x);
				printf("\n");
				Node *t1 = remove(t, x);
				t = t1;
				printf(" Operation completed\n");
			}
			
		}
		else if (c == 3)
		{
			if (t == NULL)
			{
				printf(" There are no elements to find, the set is empty\n");
			}
			else
			{
				int x = 0;
				printf(" Put in your value, please: ");
				scanf("%d", &x);
				printf("\n");
				if (find(t, x))
					printf(" An element with your value exists in the set\n");
				else
					printf (" There is no element with your value in the set\n");
			}

		}
		else if (c == 4)
		{
			if (t == NULL)
				printf(" Your set is empty\n");
			else
			{
				printf(" Your set:\n\n");
				ascendingOrder(t);
				printf("\n");
			}
		}
		else if (c == 5)
		{
			deleteTree(t);
			if (t == NULL)
				printf(" Your set is empty\n");
			else
			{
				printf(" Your set:\n\n");
				descendingOrder(t);
				printf("\n");
			}
			
		}
		else 
		{
			printf(" Error: there is no option with this number\n");
		}

		printf(" ______________________________________________________________________________\n");
	}



	deleteTree(t);

	printf("\n");
	
	scanf("%*s");
}

