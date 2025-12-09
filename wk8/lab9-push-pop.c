/*
Author: Pavel Soshenko Gnezdilov
Date: 07/11/2025
The program reads n integers from argv, then it pops two of them, and reads two last integers in argv
After, it prints the list out to the stdout
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

// Function prototypes
void readInts(int, char**, Node**, Node**);
void popInts(Node**);
void readTwoLast(int, char**, Node**);
void dispList(Node*);

struct Node {
	int n;
	Node *prev;
	Node *next;
};

// main function
int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);
	Node *first = NULL;
	Node *last = NULL;

	readInts(n, argv, &first, &last);
	popInts(&last);
	readTwoLast(argc, argv, &last);
	dispList(first);

	return 0;
}

void readInts(int n, char** argv, Node **first, Node **last)
{
	Node *curr = NULL;
	if (n > 0)
	{
		*first = (Node*)calloc(1, sizeof(Node));
		(*first) -> n = atoi(argv[2]);
		(*first) -> prev = NULL;
		curr = *first;
	}

	for (int i = 1; i < n; i++)
	{
		curr->next = (Node*)calloc(1, sizeof(Node));
		curr->next->prev = curr;
		curr = curr->next;
		curr->n = atoi(argv[2 + i]);
	}
	curr->next = NULL;
	*last = curr;
}

void popInts(Node** last)
{
	Node *curr = *last;
	for (int i = 0; i < 2 && curr; i++)
	{
		Node *tmp = curr->prev;
		*last = curr->prev;
		curr->prev->next = NULL;
		free(curr);
		curr = tmp;
	}
}

void readTwoLast(int argc, char** argv, Node **last)
{
	Node* curr = *last;
	for (int i = argc - 2; i < argc; i++)
	{
		curr->next = (Node*)calloc(1, sizeof(Node));
		curr->next->prev = curr;
		curr = curr->next;
		curr->n = atoi(argv[i]);
	}
	curr->next = NULL;
	*last = curr;
}

void dispList(Node *curr)
{
	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
