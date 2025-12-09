/*
Author: Pavel Soshenko Gnezdilov
Date: 07/11/2025
The program reads floats and stores them in order into a doubly linked list.
Afterwards, it prints them out to stdout in the reversed order
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

// Function prototypes
/* For this solution, we have to return both first and last element in the linked list.
To do this, the NULL pointers will be created in the main function and passed to the function as arguments.
Inside this function the pointers will be assigned with respective value.
*/
void readFloats(int*, char**, Node**, Node**);
void dispFloatsRev(Node*);

// structs
struct Node 
{
	float n;
	Node* prev;
	Node* next;
};

// main function
int main(int argc, char* argv[])
{
	int n = atoi(argv[1]);
	Node *first, *last;

	readFloats(&n, argv, &first, &last);
	dispFloatsRev(last);

	return 0;
}

void readFloats(int* n, char** argv, Node** first, Node** last)
{
	Node *curr;
	if (*n > 0)
	{
		*first = (Node*)calloc(1, sizeof(Node));
		(*first) -> prev = NULL;
		(*first) -> n = atof(argv[2]);
		curr = *first;
	}

	for (int i = 1; i < *n; i++)
	{
		curr -> next = (Node*)calloc(1, sizeof(Node));
		curr -> next -> prev = curr;
		curr = curr -> next;
		curr -> n = atof(argv[2 + i]);
	}
	curr -> next = NULL;
	*last = curr;
}

void dispFloatsRev(Node* last)
{
	Node* curr = last;
	while (curr != NULL)
	{
		printf("%.2f\n", curr -> n);
		curr = curr -> prev;
	}
}
