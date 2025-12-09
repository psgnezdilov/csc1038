/*
Author: Pavel Soshenko Gnezdilov
Date: 09/10/2025
The program takes n integers based on the first argument and performs
ascending or descending sort of the array based on the last argument
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void ascSort(int*, int*);
void descSort(int*, int*);
void arrDisplay(int*, int*);

int main(int argc, char* argv[])
{
	int n = atoi(argv[1]);
	int nums[n];
	char* sorting = *(argv + argc - 1);
	void (*pointer)(int*, int*);

	// fill the array
	for (int i = 2; i < argc - 1; i++)
	{
		*(nums + i - 2) = atoi(*(argv + i));
	}

	if (strcmp(sorting, "asc") == 0)
		{
		pointer = ascSort;
	}
	else { pointer = descSort; }

	pointer(&n, nums); // Call the necessary sorting variation
	arrDisplay(&n, nums);

	return 0;
}

void ascSort(int* n, int* array)
{
	for (int i = 0; i < *n; i++)
	{
		int min = i;
		for (int j = i + 1; j < *n; j++)
		{
			if (*(array + j) < *(array + min))
			{
				min = j;
			}
		}
		int tmp = *(array + min);
		*(array + min) = *(array + i);
		*(array + i) = tmp;
	}
}

void descSort(int* n, int* array)
{

	for (int i = 0; i < *n; i++)
	{
		int max = i;
		for (int j = i + 1; j < *n; j++)
		{
			if (*(array + j) > *(array + max))
			{
				max = j;
			}
		}
		int tmp = *(array + max);
		*(array + max) = *(array + i);
		*(array + i) = tmp;
	}
}

void arrDisplay(int* n, int* array)
{
	printf("Sorted numbers:");
	for (int i = 0; i < *n; i++)
	{
		printf(" %d", *(array + i));
	}
	printf("\n");
}
