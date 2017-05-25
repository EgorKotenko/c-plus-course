// hw3�3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"

struct List
{
	char sign;
	List *next;
};

struct Stack
{
	List *top;
};

Stack *createStack(Stack *&s) // �������� �����
{
	s = new Stack();
	s->top = new List();
	s->top->next = NULL;
	return s;
}

void push(Stack *&s, char c) // ��������� �������� � ����
{
	List *p = new List();
	p->next = s->top->next;
	s->top->next = p;
	p->sign = c;
}

char pop(Stack *&s) // ������� ������� ������� �����, ������ ��� �� �����
{
	List *p = s->top->next;
	s->top->next = p->next;
	char temp = p->sign;
	delete p;
	return temp;
}

void printStack(Stack *&s) // ����� ����� �����
{
	while (s->top->next != NULL)
		printf("%c", pop(s));
}

void printStackWhile(Stack *&s, char c) // ����� ����� �� ������������ ��������
{
	while (s->top->next->sign != c)
		printf("%c", pop(s));
	
}

bool isMorePriority(char a, char b) // �����������, ��� ��������� ���� - ������� a ��� ������� b
{
	if (((a == '+') || (a == '-')) && (b != '('))
		return false;
	if (((a == '*') || (a == '/')) && ((b == '+') || (b == '-')))
		return true;
	if (((a == '*') || (a == '/')) && ((b == '*') || (b == '/')))
		return false;
	if (b == '(')
		return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char str[20];
	printf("Put in your infix expression\n");
	scanf("%s", &str);
	printf("Your postfix expression:\n");

	Stack *s = createStack(s);
	int i = 0;
	while(i <= strlen(str))
	{
		if ((str[i] >= '0') && (str[i] <= '9'))  // ���� ������� �����, �� ������� � �� �����
			printf("%c", str[i]);

		else // ���� ��������� ������� �� ����� (������)
		{
			if (s->top->next == NULL) // ���� ���� ��� ����, �� ������ ���������� � ����
				push(s, str[i]);
			else
			{
				if (str[i] == '(') // ���� ������� ( �� ������ ��������� ���� ������ � ����
					push(s, str[i]);
				if (str[i] == ')') // ���� ������� ) �� ������� ���� ���� �� �������� (, ����� ������� ���� ����� ������� (
				{
					printStackWhile(s, '(');
					char temp = pop(s);
				}
				if ((str[i] != '(') && (str[i] != ')')) // ���� ������� �� ����� � �� ��������, �� ������ ��� ���� ��������
				{
					if (isMorePriority(str[i], s->top->next->sign)) // ���� ��������� ���������� ����� ����, ��� ��������� ������� �������� �� ������� �����, �� ���������� ��������� ������ � ����
						push(s, str[i]);
					else  // ���� ��������� ����, �� ������� ��������� �������, � �� ��� ����� ���������� ���������
					{
						printf("%c", pop(s)); 
						push(s, str[i]);
					}
				}
			}
		}
		i++;
	}
	printStack(s); // ������� ���� ���������� ������

	printf("\n");

	scanf("%*s");
}

