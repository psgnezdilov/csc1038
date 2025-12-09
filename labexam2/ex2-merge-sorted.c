/*
Author: Pavel Soshenko Gnezdilov
Date: 09/12/2025
The program reads two sequences of integers into dynamically allocated separate
arrays. After that the program merges two lists in a sorted manner and output
the result, an integer per line.
*/

#include <stdio.h>
#include <stdlib.h>

/*
Function prototypes
For this program we will need the functions that will do the following:
    1. Allocate memory for arrays given their size
    2. Read the integers into arrays
    3. Merge the arrays
    4. Output the result
*/
int *allocateMemory(int);
void readIntegers(int, char **, int *);
int *mergeArrays(int *, int *);
void outputArray(int, int *);

// main function
int main(int argc, char *argv[]) { return 0; }
