/*
Author: Pavel Soshenko Gnezdilov
Date: 24/10/2025
The program reads integers from the argv, and checks whether there was a number that is
twice as bigger as the smallest one.
*/

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
/*
This program will need following functions
	1. Will alocate memory
	2. Fill in the array
	3. Will find the smallest and the largest numbers and check if the condition is met
*/
void allocateM(int, int**);
void fill(int, char**, int*);
int smLg(int, int*);

// Main function
int main(int argc, char* argv[])
{
	int n = argc - 1;
	int* nums;

	allocateM(n, &nums);
	fill(argc, argv, nums);
	int result = smLg(n, nums);

	printf("%d\n", result);
	free(nums);
	nums = NULL;

	return 0;
}

void allocateM(int n, int** nums)
{
	*nums = calloc(n, sizeof(int));
	if (!(*nums))
	{
		printf("Unable to allocate memory!\n");
		exit(1);
	}
}

void fill(int argc, char** argv, int* nums)
{
	for (int i = 0; i < argc - 1; i++)
	{
		nums[i] = atoi(argv[i + 1]);
	}
}

int smLg(int n, int* nums)
{
	int sm = nums[0];
	int lg = nums[0];

	for (int i = 1; i < n; i++)
	{
		int num = nums[i];
		if (num > lg)
		{
			lg = num;
		} else if (num < sm)
		{
			sm = nums[i];
		}
		
	}

	if (sm * 2 <= lg)
	{
		return lg;
	}
	return 0;
}
