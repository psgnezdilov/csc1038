/*
Author: Pavel Soshenko Gnezdilov
Date: 03/10/2025
This program sums all the given elements of the n x n matrix. The dimensions are provided with the first argument n,
and all the elements with arguments 2 + i.
*/

#include <stdlib.h>
#include <stdio.h>

// Function prototypes
int mSum(int *pMatrix, int*pn); // Sums the matrix diagonal
// NOTE: Matrix can be directly filled without using Array
// TODO: Remove the array and fill the Matrix directly
int main(int argc, char **argv)
{
	int n = atoi(*(argv + 1));
	int matrix[n][n];
	int *pn = &n;
	int *pMatrix = &(**matrix);

	// Convert arguments to ints and fill it in the matrix
	for (int i = 2; i < argc; i++)
	{
		*(pMatrix + i - 2)= atoi(*(argv + i));
	}

	int result = mSum(pMatrix, pn);

	printf("%d\n", result);

	return 0;

}


int mSum(int *pMatrix, int *pn)
{
	int sum = 0;

	for (int i = 0; i < *pn; i++)
	{
		for (int j = 0; j < *pn; j++)
		{
			if (i == j)
			{
				sum += *(pMatrix + i * (*pn) + j);
			}
		}
	}

	return sum;
}
