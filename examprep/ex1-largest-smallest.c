/*
Author: Pavel Soshenko Gnezdilov
Date: 29/10/2025
The program reads floats from the argv, depending on the first argument
it either finds the largest or the smallest float and outputs it
with 2 digits after the decimal point
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function prototypes
/*
For this program we will need two functions, one that finds the largest,
and another that finds the smallest number. We will call either function depending on the first
argument. Also, we will have a function which checks what other function we have to call.
*/
void chooseFunction(float(**pfun)(char**, int), char**);
float largest(char**, int);
float smallest(char**, int);

// main function
int main(int argc, char* argv[])
{
	float result;
	float (*pf)(char**, int) = NULL;

	// Call a function that will assign the funciton to execute
	chooseFunction(&pf, argv);
	// Run a function to find the result
	result = pf(argv, argc);
	printf("%.2f\n", result);

	return 0;
}

void chooseFunction(float(**pfun)(char**, int), char** argv)
{
	if (strcmp(argv[1], "largest") == 0)
	{
		*pfun = largest;
	} else { *pfun = smallest; }
}

float largest(char** argv, int argc)
{
	float largest = atof(argv[2]);
	for (int i = 3; i < argc; i++)
	{
		if (atof(argv[i]) > largest)
		{
			largest = atof(argv[i]);
		}
	}

	return largest;
}

float smallest(char** argv, int argc)
{
	float smallest = atof(argv[2]);
	for (int i = 3; i < argc; i++)
	{
		float curr = atof(argv[i]);
		if (smallest > curr) { smallest = curr; }
	}

	return smallest;
}
