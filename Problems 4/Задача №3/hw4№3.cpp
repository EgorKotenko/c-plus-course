// hw4¹3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "List.h"
#include "list.cpp"


int _tmain(int argc, _TCHAR* argv[])
{
	
	printf("\n Available options:\n\n  0  -  Exit\n  1  -  Add value to sorted list\n  2  -  Remove value from list\n  3  -  Print list\n");
	printf(" ______________________________________________________________________________\n");
	

	int c = 4;
	List *l;
	createList(l);
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
			addElementToList(l, x);
			printf(" Operation completed\n");
			
			
		}
		else if (c == 2)
		{	
			
			if (l->next == NULL)
			{
				printf(" There are no elements to remove, the list is empty\n");
			}
			else
			{
				int x = 0;
				printf(" Put in your value, please: ");
				scanf("%d", &x);
				printf("\n");
				removeElementFromList(l, x);
				printf(" Operation completed\n");
			}
			
		}
		else if (c == 3)
		{
			if (l->next == NULL)
				printf(" Your list is empty\n");
			else
			{
				printf(" Your list:\n\n");
				printList(l);
				printf("\n");
			}
			
		}
		else 
		{
			printf(" Error: there is no option with this number\n");
		}

		printf(" ______________________________________________________________________________\n");
	}

	deleteList(l);

	printf("\n");

	scanf("%*s");
}

