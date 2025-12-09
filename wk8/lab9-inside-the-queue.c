/*
Author: Pavel Soshenko Gnezdilov
Date: 07/11/2025
The program takes two inputs from the argv, 1st being the number after which to insert and 2nd being the value
of the element to be inserted into a predefined linked list.
Afterwards, the whole list is displayed to stdout.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

// function prototypes
Node* createList(int*);
void linkedListInsert(int, int, Node**);
void dispList(Node*);

struct Node {
	int n;
	Node* next;
};

// main function
int main(int argc, char** argv)
{
	Node* first = NULL;
	int ints[10] = {8, 7, 3, 4, 5, 6, 9, 2, 14, 12};
	int findN = atoi(argv[1]);
	int insertN = atoi(argv[2]);

	first = createList(ints);
	linkedListInsert(findN, insertN, &first);
	dispList(first);

	return 0;
}

Node* createList(int* ints)
{
	Node* first = (Node*)calloc(1, sizeof(Node));
	first -> n = ints[0];
	first -> next = NULL;
	Node* curr = first;
	for (int i = 1; i < 10; i++)
	{
		curr->next = (Node*)calloc(1, sizeof(Node));
		curr = curr->next;
		curr->n = ints[i];
		curr->next = NULL;
	}

	return first;
}

void linkedListInsert(int findN, int insertN, Node** first)
{
	Node* curr = *first;
		while (curr->n != findN)
		{
			curr = curr->next;
		}
		Node* tmp = curr->next;
		curr->next = (Node*)calloc(1, sizeof(Node));
		curr->next->n = insertN;
		curr->next->next = tmp;
}

void dispList(Node* curr)
{
	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
