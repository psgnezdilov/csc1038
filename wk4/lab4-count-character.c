/*
Author: Pavel Soshenko Gnezdilov
Date: 2/10/2025
Given two arguments, the program counts the amount of character appearances
specified in the first argument in the string given in the second argument
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int counter(char* pchar, char** pstr);

// Main function
int main(int argc, char* argv[])
{
	char* pchar = &(**(argv + 1)); // Points to the character in the first argument
	char** pstr = &(*(argv + 2)); // Points to the first char of the second argument string
	counter(pchar, pstr);

	return 0;
}

int counter(char* pchar, char** pstr)
{
	int count = 0;

	// Go through chars in the given string and count the occurences of a char
	for (int i = 0; *(*pstr + i) != '\0'; i++)
      {
	if (*(*pstr + i) == *pchar)
		{
			count++;
		}
	}

	printf("%d\n", count);

	return 0;
}
