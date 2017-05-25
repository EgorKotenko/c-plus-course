// hw6№2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include <iostream>
#include "fstream"
#include "string.h"

using namespace std;

fstream file("hw6.txt");

struct Node    
{
	char operation;  // для хранения знака операции (если в узле будет лежть число, то вместо знака будет '0')
	int number;		 // для хранения числа (если в узле будет лежть знак операции, то вместо числа будет '101010')
	Node *left;
	Node *right;
};

void addToTree(Node *&node, char c)
{
	if ((c == '(') || (c == ')')) // если встретили скобочки, то ничего не делаем, просто считываем след. символ и записываем его в дерево
	{
		file >> c;
		addToTree(node, c);
		return;
	}
	else if ((c >= '0') && (c <= '9')) // если встретили цифру, то откатываемся на символ назад, считываем число
	{								   // создаём временное дерево с пустыми детьми и считанным числом в корне
		file.unget();				   // затем временное дерево вписываем в общее дерево
		int temp = 0;
		file >> temp;
		Node *t = new Node();
		t->left = NULL;
		t->right = NULL;
		t->number = temp;
		t->operation = '0';
		node = t;
		return;
	}
	else 
	{
		if (c == '-')					// если считали знак минус, то возможно два вариант: это знак операции 
		{								// или знак некоторого отрицательного числа
			file >> noskipws >> c;
			if (c == ' ')				// если это знак операции, то создаём временное дерево, в корень кладём знак минус 
			{							// затем добавляем временное дерево в основное 
				Node *t = new Node;     // считываем следующий символ и рекурсивно добавляем элементы в левого и правого ребёнка текущего узла
				t->number = 101010;
				t->operation = '-';
				node = t;
				file >> skipws >> c;					
				addToTree(node->left, c);
				file >> skipws >> c;
				addToTree(node->right, c);
				return;
			}
			else								// если это знак числа, то повторяем всё то, что делали,
			{									// когда рассматривали вариант считывания числа
				file.unget();
				file.unget();
				int temp = 0;
				file >> temp;
				Node *t = new Node();
				t->left = NULL;
				t->right = NULL;
				t->number = temp;
				t->operation = '0';
				node = t;
				return;
			}
		}
		else									// если считали знак операции, то делаем то, что делали в случае с минусом 
		{										// (когда минус был знаком операции а не отриц. числа)
			Node *t = new Node;
			t->number = 101010;
			t->operation = c;
			node = t;
			file >> skipws >> c;
			addToTree(node->left, c);
			file >> skipws >> c;
			addToTree(node->right, c);
			return;
		}
	}
}


int operation(int a, int b, char c)				// по двум операндам (a, b) и операции (c) выполняет операцию над этими самыми операндами
{
	if (c == '+')
		return a + b;
	if (c == '-')
		return a - b;
	if (c == '*')
		return a * b;
	if (c == '/') 
		return a / b;
}

int computeTree(Node *node)			// считаем значение содержащегося в дереве выражения
{
	if (node->operation == '0')
		return node->number;
	else
		return operation(computeTree(node->left), computeTree(node->right), node->operation);
}

void printTree(Node *node)         // печатаем дерево
{
	if (node->operation != '0')
	{
		cout << "(" << node->operation << " "; 
		printTree(node->left);
		cout << " ";
		printTree(node->right);
		cout << ") ";
	}
	else
		cout << node->number;
}

void deleteTree(Node *&node)      // удаляем дерево
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
	Node *node = NULL;
	
	char c;
	file >> c;
	
	addToTree(node, c);
	
	cout << "Created tree: \n ";
	printTree(node);
	cout << "\n" << "\n";

	cout << "The value of expression: \n ";
	int x = computeTree(node);
	cout << x << "\n";

	deleteTree(node);
	
	scanf("%*s");
}

