// hw3є3.cpp : Defines the entry point for the console application.
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

Stack *createStack(Stack *&s) // создание стека
{
	s = new Stack();
	s->top = new List();
	s->top->next = NULL;
	return s;
}

void push(Stack *&s, char c) // добаление элемента в стек
{
	List *p = new List();
	p->next = s->top->next;
	s->top->next = p;
	p->sign = c;
}

char pop(Stack *&s) // выводим верхний элемент стека, удал€€ его из стека
{
	List *p = s->top->next;
	s->top->next = p->next;
	char temp = p->sign;
	delete p;
	return temp;
}

void printStack(Stack *&s) // вывод всего стека
{
	while (s->top->next != NULL)
		printf("%c", pop(s));
}

void printStackWhile(Stack *&s, char c) // вывод стека до определЄнного элемента
{
	while (s->top->next->sign != c)
		printf("%c", pop(s));
	
}

bool isMorePriority(char a, char b) // определение, чей приоритет выше - символа a или симаола b
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
		if ((str[i] >= '0') && (str[i] <= '9'))  // если считали цифру, то выводим еЄ на экран
			printf("%c", str[i]);

		else // если считанный элемент не цифра (символ)
		{
			if (s->top->next == NULL) // если стек ещЄ пуст, то просто записываем в стек
				push(s, str[i]);
			else
			{
				if (str[i] == '(') // если считали ( то просто добавл€ем этот символ в стек
					push(s, str[i]);
				if (str[i] == ')') // если считали ) то выводим весь стек до элемента (, затем удал€ем этот самый элемент (
				{
					printStackWhile(s, '(');
					char temp = pop(s);
				}
				if ((str[i] != '(') && (str[i] != ')')) // если считали не цифру и не скобочки, то значит это знак операции
				{
					if (isMorePriority(str[i], s->top->next->sign)) // если приоритет считанного знака выше, чем приоритет символа сто€щего на вершине стека, то записываем считанный символ в стек
						push(s, str[i]);
					else  // если приоритет ниже, то выводим вершинный элемент, а на его место записываем считанный
					{
						printf("%c", pop(s)); 
						push(s, str[i]);
					}
				}
			}
		}
		i++;
	}
	printStack(s); // выводим весь оставшийс€ список

	printf("\n");

	scanf("%*s");
}

