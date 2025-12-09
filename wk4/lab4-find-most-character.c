/* 
Author: Pavel Soshenko Gnezdilov
Date: 02/10/2025
The program finds the most recurring character in a given string as an argument
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototypes
char most_char(char **pstr);

int main(int argc, char* argv[])
{
	char **pstr = &(*(argv + 1)); // Address of the first element of the first argument
	
	char result = most_char(pstr);
	printf("%c\n", result);

	return 0;
}

char most_char(char **pstr)
{
	int count[256] = {0}; // An array that will store all the occurences of values in ASCII decimal position
	for (int i = 0; *(*pstr + i) != '\0'; i++) // Fill the frequency of each character
	{
		if (*(*pstr + i) != ' ')
		{
			int ascii = *(*pstr + i); // Convert a char to a ASCII decimal
			count[ascii]++;
		}
	}

	char maxChar;
	int maxCount = 0;
	for (int i = 0; i < 256; i++)
	{
		if (*(count + i) > maxCount)
		{
			maxCount = *(count + i);
			maxChar = i;
		}
	}

	return maxChar;
}
