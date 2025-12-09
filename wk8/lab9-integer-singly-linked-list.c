/*
Author: Pavel Soshenko Gnezdilov
Date: 07/11/2025
The program reads integers from the argv and stores them into a singly linked list
and then prints them out
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

// Function prototypes
Node* readInts(int*, char**);
void displayList(Node*);

struct Node {
	int n;
	Node* next;
};

// Main function
int main(int argc, char* argv[])
{
	int n = atoi(argv[1]);
	Node* first = NULL;

	first = readInts(&n, argv);
	displayList(first);

	return 0;
}

Node* readInts(int* n, char** argv)
{
	Node *first, *curr;
	if (*n > 0)
	{
		first = (Node*)calloc(1, sizeof(Node));
		first -> n = atoi(argv[2]);
		curr = first;
	}



	for (int i = 1; i < *n; i++)
	{
		curr -> next = (Node*)calloc(1, sizeof(Node));
		curr = curr -> next;
		curr -> n = atoi(argv[2 + i]);
	}
	curr -> next = NULL;

	return first;
}

void displayList(Node* curr)
{
	while (curr != NULL)
	{
		printf("%d\n", curr -> n);
		curr = curr -> next;
	}
}
