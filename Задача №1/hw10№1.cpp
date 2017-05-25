// hw10¹1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "iostream"
#include "math.h"
#include "modul_10_1.h"
#include "modul_10_1.cpp"

using namespace std;

bool equals(List *p, List *q)
{
	bool flag = false;
	List *l1 = p;
	List *l2 = q;
	while (l1)
	{
		l2 = q;
		flag = false;
		while (l2)
		{
			if ((l2->power == l1->power) && (l2->coef == l1->coef))
			{
				flag = true;
				break;
			}
			l2 = l2->next;
		}
		if ((!l2) && (!flag))
			return false;
		l1 = l1->next;
	}
	return true;
}

int raiseToPower(int n, int p)
{
	int res = 1;
	for (int i = 1; i <= p; i++)
		res *= n;
	return res;
}

int value(List *input, int x) 
{
	int s = 0;
	List *l = input;
	while (l)
	{
		s += l->coef * raiseToPower(x, l->power);  
		l = l->next;
	}
	return s;
}

int maxPower(List *input)
{
	List *l = input->next;
	int max = input->power;
	while (l)
	{
		if (l->power > max)
			max = l->power;
		l = l->next;
	}
	return max;
}

void add(List *&p, List *&q, List *&r)
{
	int max = 0;
	if (maxPower(p) > maxPower(q))
		max = maxPower(p);
	else
		max = maxPower(q);
	List *l1 = p;
	List *l2 = q;
	int coeff = 0;
	bool flag = true;
	for (int i = max; i >= 0; i--)
	{
		coeff = 0;
		l1 = p;
		l2 = q;
		flag = false;
		while (l1)
		{
			if (l1->power == i)
			{
				coeff += l1->coef;
				flag = true;
			}
			l1 = l1->next;
		}
		while (l2)
		{
			if (l2->power == i)
			{
				coeff += l2->coef;
				flag = true;
			}
			l2 = l2->next;
		}
		if ((flag) && (coeff))
			addToList(r, coeff, i);
	}
}

void fillTheList(List *&p, int &ch, bool &f)
{
	char c1;
	int c2 = 0;
	f = true;
	ch = 0;
	while (1)
	{
		cout << " Put in the coefficient and the power:  ";
		cin >> c1;
		if (c1 == '!')
			break;
		else
		{
			cin >> c2;
			if (c1 != '0')
			{
				addToList(p, c1 - '0', c2);
				ch++;
			}
			if (c2 < 0)
			{
				f = false;
				break;
			}
		}
		cout << endl;
	}
	if (!ch)
	{
		cout << endl << " ERROR: there is no polinomial!" << endl << endl << " Try again!" << endl;
		cout << " ______________________________________________________________________________" << endl;
	}
	else if (!f)
	{
		cout << endl << " ERROR: the power is negative!" << endl << endl << " Try again!" << endl;
		cout << " ______________________________________________________________________________" << endl;
	}
	else
	{
		cout << endl << "The polynomial:   ";
		printPolynomial(p);
		cout << endl << endl;
	}
}

void menu(List *p, List *q)
{
	cout << endl << "Available options:" << endl << endl << "  0  -  Exit" << endl << "  1  -  Equality operation" << endl;
			cout << "  2  -  Evaluation of polynomial" << endl << "  3  -  Polynomials summ computation" << endl;
			cout << " ______________________________________________________________________________" << endl;

			int c = 4;
			while (c != 0)
			{
				cout << endl << " Put in the number of an option, please:  ";
				cin >> c;
				cout << endl;

				if (c == 0)
				{
					cout << " Thank you for using our service!" << endl;
				}
				else if (c == 1)
				{
					if (equals(p, q))
						cout << " Your polynomials are equal" << endl;
					else 
						cout << " Your polynomials are not equal" << endl;
				}
				else if (c == 2)
				{	
					int t = 0;
					int x = 0;
					cout << " Choose a polynomial to evaluate: " << endl << endl << "   1 - The first polynomial" << endl << "   2 - The second polynomial" << endl;
					cout << "   3 - Both polynomials" << endl << endl << "   Your choice:  ";
					cin >> t;
					cout << endl << " Put in the value of a variable: ";
					cin >> x;
					cout << endl;
					if (t == 1)
						cout << endl << " The value of the first polynomial = " << value(p, x) << endl;
					else if (t == 2)
						cout << endl << " The value of the second polynomial = " << value(q, x) << endl;
					else if (t == 3)
					{
						cout << endl << " The value of the first polynomial = " << value(p, x) << endl;
						cout << endl << " The value of the second polynomial = " << value(q, x) << endl;
					}
				}
				else if (c == 3)
				{		
					int t = 0;
					int x = 0;
					List *sum = NULL;
					add(p, q, sum);
					cout << " The sum-polynomial: ";
					printPolynomial(sum);
					cout << endl;
					cout << " If you want to evoluate the sum-polynomial, put in '1', else put in '0': ";
					cin >> t;
					if (t == 1)
					{
						cout << endl << " Put in the value of a variable:   ";
						cin >> x;
						cout << endl << " The value of the sum-polynomial =   " << value(sum, x) << endl;
					}
					else
						cout << endl;
				}
				else 
				{
					cout <<" ERROR: there is no option with this number" << endl;
				}

				cout << " ______________________________________________________________________________" << endl;
			}
}

int _tmain(int argc, _TCHAR* argv[])
{
	List *p = NULL;
	List *q = NULL;
	
	int ch = 0;
	bool f = true;
	cout << endl << "Put in the first polynomial (only positive powers)," << " if your polynomial is over  put in the '!' symbol" << endl << endl;
	fillTheList(p, ch, f);
	if ((ch) && (f))
	{
		ch = 0;
		f = true;
		cout << "Put in the second polynomial (only positive powers)," << " if your polynomial is over  put in the '!' symbol" << endl << endl;
		fillTheList(q, ch, f);
		if ((ch) && (f))
		{
			menu(p, q);
	
			if (p)
				deleteList(p);
			else
				delete p;
			if (q)
				deleteList(q);
			else
				delete q;

		}
	}
	cout << endl;
	scanf("%*s");
}

