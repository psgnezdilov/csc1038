/*
Author: Pavel Soshenko Gnezdilov
Date: 09/10/2025
The makes various arithmetical operations with two command-line arguments
and prints out the results
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
float sum(float*, float*);
float diff(float*, float*);
float prod(float*, float*);
float my_div(float*, float*);
float pwr(float*, float*);
float nat_log(float*, float*);

int main(int argc, char* argv[])
{
	float a = atof(argv[1]);
	float b = atof(argv[2]);
	float (*operations[])(float*, float*) = {sum, diff, prod, my_div, pwr, nat_log}; // Read-only array of function pointers

	printf("sizeof %lu, sizeof/sizeof %lu\n", sizeof(operations), sizeof(operations)/sizeof(operations[0]));
	for (int i = 0; i < sizeof(operations)/sizeof(operations[0]); i++)
	{
		printf("%.2f\n", operations[i](&a, &b));
	}

	return 0;
}

float sum(float* a, float* b)
{
	return *a + *b;
}

float diff(float* a, float* b)
{
	return *a - *b;
}

float prod(float* a, float* b)
{
	return *a * *b;
}

float my_div(float* a, float* b)
{
	return *a / *b;
}

float pwr(float* a, float* b)
{
	return pow(*a, *b);
}

float nat_log(float* a, float* b)
{
	return log(*a) + log(*b);
}
