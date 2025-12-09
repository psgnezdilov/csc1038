/*
Author: Pavel Soshenko Gnezdilov
Date: 03/10/2025
The program checks whether a string provided in the second argument is the substring of a
string from the first argument. If true, prints the first and the last position of a substring.
*/

#include <stdlib.h>
#include <stdio.h>

// Function prototypes
int sub_s(char* array, char* subarray);


int main(int argc, char** argv)
{
	char* array = *(argv + 1);
	char* subarray = *(argv + 2);

	sub_s(array, subarray);

	return 0;
}

int sub_s(char* array, char* subarray)
{
	for (int i = 0; *(array + i) != '\0'; i++) // Go through all the characters in the array
	{
		if (*(array + i) == *(subarray))
		{
      			char *pArray = array + i; // Assign current address at index i
			for (int j = 0; (*(pArray + j) == *(subarray + j) || *(pArray + j) != '\0' ); j++)
			{
				if (*(subarray + j) == '\0') // If subarray reaches null character
				{
					printf("%d %d\n", i, i + j - 1); // Subarray found, print indices
					return 0; // Finish function
				}
			}
		}
	}
	return 0; // No substring found, end of function
}
