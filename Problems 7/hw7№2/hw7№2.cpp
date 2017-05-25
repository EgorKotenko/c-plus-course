// hw7¹2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "iostream"
#include "fstream"
#include "string.h"
#include "iomanip"

using namespace std;

const int n = 8111;

struct List
{
	int value;
	char *str;
	List *next;
};

void addToList(List *&input, char *s, int x)
{
	if (input == NULL)
	{
		List *l = new List();
		l->next = NULL;
		l->str = strdup(s);
		l->value = x;
		input = l;
	}
	else
	{
		List *l = new List();
		l->next = NULL;
		l->str = strdup(s);
		l->value = x;
		List *temp = input;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = l;
	}
}

void printList(List *&input)
{
	cout.fill (' ');
	if (input->next == NULL)
	{
		cout << "  " << input->str << setw(40 - strlen(input->str)) << input->value << endl;
	}
	else
	{
		List *index = input->next;
		while (index->next != NULL)
		{
			cout << "  " << index->str << setw(40 - strlen(index->str)) << index->value << endl;
			index = index->next;
		}
		cout << "  " << index->str << setw(40 - strlen(index->str)) << index->value << endl;
	}
}

void deleteList(List *&input)
{
	List *index = input->next;
	if (index)
		deleteList(index);
	delete (index);

}

int hashString(char s[])
{
	int temp = 0;
	int k = 31;
	int t = 11;
	for (int i = 0; i < strlen(s); i++)
	{
		temp += ((s[i] - 'a' + 1) * k) % t;
		k *= 31;
		t*= 11;
	}
	if (temp % n < 0)
		return (-1)*(temp % n);
	else
		return temp % n;
}

int _tmain(int argc, _TCHAR* argv[])
{
	fstream file("hw7_2.txt");
	
	

	List *a[8112] = {NULL};
	
	while (!file.eof())
	{
		char s[50];

		file >> s;

		int index = hashString(s);
		
		if (a[index] == NULL)
			addToList(a[index], s, 1);
		else
		{
			List *l = a[index];

			bool flag = true;

			while ((l) && (flag))
			{
				if (strcmp(s, l->str) == 0)
				{
					l->value += 1;
					flag = false;
				}
				l = l->next;
			}
		
			if (flag)
				addToList(a[index], s, 1);
		}
	}

	int num = 0;
	int collision = 0;
	for (int i = 1; i < 8112 ; i++)
	{
		if (a[i] != NULL)
		{
			num += a[i]->value;
			List *p = a[i];
			while (p)
			{

				if ((p->next))
					collision ++;
				p = p->next;
			}
		}
	}

	int max = 0;
	for (int i = 1; i < 8112; i++)
	{
		if (a[i])
		{
			List *p = a[i];
			int k = 1;
			while (p->next)
			{
				k ++;
				p = p->next;
			}
			if (k > max)
				max = k;
		}
	}

	cout.fill (' ');

	cout << endl << " Stastics:" << endl << endl;
	cout << "  Load factor:" << setw(44 - strlen("Load factor:")) << (double) num / n << endl;
	cout << "  Number of collisions:" << setw(40 - strlen("Number of collisions:")) << collision << endl;
	cout << "  Maximal list length:" << setw(40 - strlen("Maximal list length:")) << max << endl << endl;

	cout << " Word:" << setw(44 - strlen("Word:")) << "Times:" << endl << endl;;

	for (int i = 1; i < 8112 ; i++)
	{
		if (a[i] != NULL)
			printList(a[i]);
	}
	
	for(int i = 1; i < 8112; i++)
		if (a[i])
			deleteList(a[i]);

	cout << "\n";
	scanf("%*s");
}

