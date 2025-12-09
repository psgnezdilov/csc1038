/*
Author: Pavel Soshenko Gnezdilov
Date: 24/10/2025
The program reads an array of strings from argv
and prints out the longest string(s).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
/*
The program will need the functions that will do the following:
	1. Allocate memory for strings
	2. Allocate memory for array of ints
	3. Realocate memory for array of ints
	2. Find the longest string(s)
*/
void allocateMStr(int, int, char***);
void allocateMInt(int, int**);
void reallocateMInt(int, int**);
char** longest(int, char**, int*);

// Main function
int main(int argc, char* argv[])
{
	int n;
	char** result = longest(argc, argv, &n);

	for (int i = 0; i < n; i++)
	{
		printf("%s\n", result[i]);
	}

	if (n > 0) {free(result[0]); result[0] = NULL;}
	free(result);
	result = NULL;

	return 0;
}

char** longest(int argc, char** argv, int* n)
{
	int longest = 0;
	int count = 0;
	int* positions;
	char** result;
	allocateMInt(argc - 1, &positions);

	// Go through the argv and count the amount of the longest strings
	/* TODO: Remember the positions of the longest strings
		  and use them later to fill the result array of arrays
	*/
	for (int i = 1; i < argc; i++)
	{
		if (strlen(argv[i]) > longest)
		{
			longest = strlen(argv[i]);
			reallocateMInt(argc - i, &positions);
			positions[0] = i;
			count = 1;
		} else if (strlen(argv[i]) == longest)
		{
			positions[count] = i;
			count++;
		}
	}

	// Allocate the memory for the result and fill it with strings
	allocateMStr(count, longest, &result);
	for (int i = 0; i < count; i++)
	{
		strcpy(result[i], argv[positions[i]]);
	}

	*n = count;
	free(positions);
	positions = NULL;

	return result;
}

void allocateMInt(int size, int** arr)
{
	*arr = calloc(size, sizeof(int));
	if (!(*arr))
	{
		printf("Unable to allocate memory\n");
		exit(1);
	}
}

void reallocateMInt(int size, int** arr)
{
	free(*arr);
	*arr = NULL;
	*arr = calloc(size, sizeof(int));
	if (!(*arr))
	{
		printf("Unable to allocate memory\n");
		exit(1);
	}
}

void allocateMStr(int count, int longest, char*** arr)
{
	char* chars = calloc(count * (longest + 1), sizeof(char));
	*arr = calloc(count, sizeof(char*));
	if (!(*arr) || !(chars))
	{
		printf("Unable to allocate memory\n");
		exit(1);
	}
	for (int i = 0; i < count; i++)
	{
		*((*arr) + i) = chars + i * (longest + 1);
	}
}
