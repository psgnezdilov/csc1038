/*
Author: Pavel Soshenko Gnezdilov
Date: 24/10/2025
The program takes two vector of n size and performs
dot product calculation
*/

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
/* We will need three functions, first to allocate memory
and check if the allocation is successful, secondn to read the
vectors, and the last to calculate the dot product
*/
void allocateM(int, int**, int**);
void readVectors(int, int, char**, int*, int*);
int dotProduct(int, int*, int*);

// Main function
int main(int argc, char* argv[])
{
	int n = atoi(argv[1]);
	int* v1;
	int* v2;

	allocateM(n, &v1, &v2);
	readVectors(n, argc, argv, v1, v2);
	int result = dotProduct(n, v1, v2);

	printf("%d\n", result);

	free(v1);
	free(v2);
	v1 = NULL;
	v2 = NULL;

	return 0;
}

void allocateM(int n, int** v1, int** v2)
{
	*v1 = calloc(n, sizeof(int));
	*v2 = calloc(n, sizeof(int));
	if (!v1 || !v2)
	{
		printf("Not enough memory!\n");
		exit(0);
	}
}

void readVectors(int n, int argc, char** argv, int* v1, int* v2)
{
	for (int i = 0; i < n; i++)
	{
		*(v1 + i) = atoi(argv[i + 2]);
	}
	for (int i = 0; i < n; i++)
	{
		v2[i] = atoi(argv[i + n + 2]);
	}
}

int dotProduct(int n, int* v1, int* v2)
{
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		result += v1[i] * v2[i];
	}

	return result;
}
