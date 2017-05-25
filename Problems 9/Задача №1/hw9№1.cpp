// hw9¹1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "iostream"
#include "fstream"
#include "string.h"
#include "iomanip"

using namespace std;

struct List
{
	char *value;
	List *next;
};

void addToList(List *&input, char *x)
{
	List *l = new List();
	l->next = NULL;
	l->value = strdup(x);
	if (input == NULL)
		input = l;
	else
	{
		List *temp = input;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = l;
	}
}

void deleteList(List *&input)
{
	List *index = input->next;
	if (index)
		deleteList(index);
	delete (index);

}

bool doesExist(List *l, char *s, int length)
{
	bool flag = false;
	int i = 0;
	List *p = l;
	while ((!flag) && (i < length))
	{
		if (strcmp(p->value, s) == 0)
		{
			flag = true;
		}
		i++;
		p = p->next;
	}
	return flag;
}

int _tmain(int argc, _TCHAR* argv[])
{
	fstream f1("input1.txt", fstream::in);
	fstream f2("input2.txt", fstream::in);
	fstream f3("output.txt", fstream::out);

	List *l = NULL;
	char *temp;
	char s[256];
	int i = 0;
	while (!f1.eof())
	{
		f1.getline(s, 256);
		addToList(l, s);
		i++;
	}
	while (!f2.eof())
	{
		f2.getline(s, 256);
		if (doesExist(l, s, i))
			f3 << s << endl;
	}

	cout << "Operation complete, check your output file." << endl;

	deleteList(l);
	f1.close();
	f2.close();
	f3.close();

	scanf("%*s");
}

