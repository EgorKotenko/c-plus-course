#include "stdafx.h"
#include "stdio.h"

#pragma once

struct List;

void createList(List *&input);
void addElementToList(List *&input, int number);
void removeElementFromList(List *&input, int number);
void printList(List *&input);
void deleteList(List *&input); 
void addToUnsortedList(List *&input, int x);