#include "stdafx.h"
#include "stdio.h"
#include "iostream"
#include "math.h"

using namespace std;

struct List
{
	int coef;
	int power;
	List *next;
};

void addToList(List *&input, int k, int p)
{
	if (!input)
	{
		input = new List();
		input->next = NULL;
		input->coef = k;
		input->power = p;
	}
	else
	{
		List *temp = input;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = new List();
		temp->next->next = NULL;
		temp->next->coef = k;
		temp->next->power = p;
	}
}

void printPolynomial(List *&input)
{
	List *index = input;
	int k = 0;
	while (index != NULL)
	{
		if (!k)
		{
			if (index->coef == 1) 
			{
				if (!index->power)
					cout << "1";
				else if (index->power == 1)
					cout << "x";
				else 
					cout << "x^" << index->power;
			}
			else if (index->coef == -1) 
			{
				if (!index->power)
					cout << "- 1";
				else if (index->power == 1)
					cout << " - x";
				else 
					cout << " - x^" << index->power;
			} 
			else
			{
				if (!index->power)
					cout << index->coef;
				else if (index->power == 1)
					cout << index->coef << "*x";
				else 
					cout << index->coef << "*(x^" << index->power << ")";
			}
		}
			
		else
		{
			if (index->coef == 1) 
			{
				if (!index->power)
					cout << " + 1";
				else if (index->power == 1)
					cout << " + x";
				else 
					cout << " + x^" << index->power;
			}
			else if (index->coef == -1) 
			{
				if (!index->power)
					cout << " - 1";
				else if (index->power == 1)
					cout << " - x";
				else 
					cout << " - x^" << index->power;
			} 
			else
			{
				if (index->coef > 0)
				{
					if (!index->power)
						cout << " + " << index->coef;
					else if (index->power == 1)
						cout << " + " << index->coef << "*x";
					else 
					cout << " + " << index->coef << "*(x^" << index->power << ")";
				}
				else
				{
					if (!index->power)
						cout << " - " << -index->coef;
					else if (index->power == 1)
						cout << " - " << -index->coef << "*x";
					else 
						cout << " - " << -index->coef << "*(x^" << index->power << ")";
				}
			}
		}
		k++;
		index = index->next;
	}
	cout << endl;

}

void deleteList(List *&input)
{
	List *index = input->next;
	if (index)
		deleteList(index);
	delete (index);
}