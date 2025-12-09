/*
Author: Pavel Soshenko Gnezdilov
Date: 03/10/2025
The program multiplies two valid matrices of n1xm1 and m1xn2 dimensions.
The program takes the following arguments from the command-line:
	1. The dimensions of the first matrix n1, m1
	2. The dimensions of the first matrix n2, m2
	3. The elements of the two matrices, in order. The populate the first and the second matrix respectively.
*/

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void fill_m(int*, int, char**);
void m_mul(int* mat1, int* mat2, int* r_mat, int n1, int m1, int n2, int m2);
void fill_result(int *res, int dim); // Auxiliary function to fill the result matrix with zeros

int main(int argc, char** argv)
{
	int n1 = atoi(*(argv + 1));
	int m1 = atoi(*(argv + 2));
	int n2 = atoi(*(argv + 3));
	int m2 = atoi(*(argv + 4));
	int matrix1[n1][m1];
	int matrix2[n2][m2];
	int result_m[n1][m2];

	// Fill the result_m with zeros
	fill_result(&(**result_m), n1 * m2);

	// Populate the first matrix and the second matrix
	fill_m(&(**matrix1), n1 * m1, argv + 5);
	fill_m(&(**matrix2), n2 * m2, argv + 5 + n2 * m2);

	// Multiply two matrices
	m_mul(&(**matrix1), &(**matrix2), &(**result_m), n1, m1, n2, m2);

	return 0;
}

void fill_m(int* matrix, int dim, char** first_e)
{
	for (int i = 0; i < dim; i++)
	{
		*(matrix + i) = atoi(*(first_e + i));
	}
}

void fill_result(int* result_m, int dim)
{
	for (int i = 0; i < dim; i++)
	{
		*(result_m + i) = 0;
	}
}

void m_mul(int *mat1, int* mat2, int* r_mat, int n1, int m1, int n2, int m2)
{
      for (int i = 0; i < n1 * m2; i++)
	   {
		for (int j = 0; j < m1; j++)
		{
			for (int k = 0; k < n1; k++)
			{
				*(r_mat + ) += 
			}
		}
	   }
}
