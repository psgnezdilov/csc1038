/*
Author: Pavel Soshenko Gnezdilov
Date: 29/10/2025
The program reads an input string from argv and checks whether it is symmetric or not and prints
out a simple yes or no.
*/

#include <stdio.h>
#include <string.h>

// Function prototypes
// Here we will need one function that will loop through the given string
// both ways at the same time, from start to end and vice versa
// If it doesn't reach the end, the string is not symmetric
void isSymmetric(char*, char**, int);

// main function
int main(int argc, char* argv[])
{
	char result[4];
	isSymmetric(result, argv, argc); // The function will assign the result (yes or no)

	printf("%s\n", result); // Print the result
	
	return 0;
}

void isSymmetric(char* result, char** argv, int argc)
{
	char* word = argv[1];
	int length = strlen(word);
	int i = 0;

	while (i < length && word[i] == word[length - i - 1])
	{
		i++;
	}

	if (i == length) { strcpy(result, "yes"); }
	else { strcpy(result, "no"); }
}
