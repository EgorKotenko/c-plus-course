// hw6�2.cpp : Defines the entry point for the console application.
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
	char operation;  // ��� �������� ����� �������� (���� � ���� ����� ����� �����, �� ������ ����� ����� '0')
	int number;		 // ��� �������� ����� (���� � ���� ����� ����� ���� ��������, �� ������ ����� ����� '101010')
	Node *left;
	Node *right;
};

void addToTree(Node *&node, char c)
{
	if ((c == '(') || (c == ')')) // ���� ��������� ��������, �� ������ �� ������, ������ ��������� ����. ������ � ���������� ��� � ������
	{
		file >> c;
		addToTree(node, c);
		return;
	}
	else if ((c >= '0') && (c <= '9')) // ���� ��������� �����, �� ������������ �� ������ �����, ��������� �����
	{								   // ������ ��������� ������ � ������� ������ � ��������� ������ � �����
		file.unget();				   // ����� ��������� ������ ��������� � ����� ������
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
		if (c == '-')					// ���� ������� ���� �����, �� �������� ��� �������: ��� ���� �������� 
		{								// ��� ���� ���������� �������������� �����
			file >> noskipws >> c;
			if (c == ' ')				// ���� ��� ���� ��������, �� ������ ��������� ������, � ������ ����� ���� ����� 
			{							// ����� ��������� ��������� ������ � �������� 
				Node *t = new Node;     // ��������� ��������� ������ � ���������� ��������� �������� � ������ � ������� ������ �������� ����
				t->number = 101010;
				t->operation = '-';
				node = t;
				file >> skipws >> c;					
				addToTree(node->left, c);
				file >> skipws >> c;
				addToTree(node->right, c);
				return;
			}
			else								// ���� ��� ���� �����, �� ��������� �� ��, ��� ������,
			{									// ����� ������������� ������� ���������� �����
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
		else									// ���� ������� ���� ��������, �� ������ ��, ��� ������ � ������ � ������� 
		{										// (����� ����� ��� ������ �������� � �� �����. �����)
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


int operation(int a, int b, char c)				// �� ���� ��������� (a, b) � �������� (c) ��������� �������� ��� ����� ������ ����������
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

int computeTree(Node *node)			// ������� �������� ������������� � ������ ���������
{
	if (node->operation == '0')
		return node->number;
	else
		return operation(computeTree(node->left), computeTree(node->right), node->operation);
}

void printTree(Node *node)         // �������� ������
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

void deleteTree(Node *&node)      // ������� ������
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

