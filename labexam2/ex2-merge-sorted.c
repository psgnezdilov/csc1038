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
    5. Deallocate memory
*/
int *allocateMemory(int);
int *readIntegers(char **, int, int);
int *mergeArrays(int *, int *, int, int);
void outputArray(int, int *);
void deallocate(int **);

// main function
int main(int argc, char *argv[]) {
  int size_n = atoi(argv[1]);
  int size_m = atoi(argv[2 + size_n]);
  int *array1 = readIntegers(argv, 2, size_n);
  int *array2 = readIntegers(argv, 3 + size_n, size_m);

  int *mergedArray = mergeArrays(array1, array2, size_n, size_m);
  deallocate(&array1);
  deallocate(&array2);

  outputArray(size_n + size_m, mergedArray);
  deallocate(&mergedArray);

  return 0;
}

int *allocateMemory(int size) {
  int *array = calloc(size, sizeof(int));

  if (!array) {
    printf("Unable to allocate memory!\n");
    exit(0);
  }

  return array;
}

int *readIntegers(char **argv, int start, int size) {
  int count = 0;
  int finish = start + size;
  int *array = allocateMemory(size);

  for (int i = start; i < finish; i++) {
    *(array + count) = atoi(argv[i]);
    count++;
  }

  return array;
}

int *mergeArrays(int *array1, int *array2, int size1, int size2) {
  int *mergedArray = allocateMemory(size1 + size2);
  int i = 0;
  int j = 0;
  int k = 0;
  for (; j < size1 && k < size2; i++) {
    if (*(array1 + j) > *(array2 + k)) {
      *(mergedArray + i) = *(array2 + k);
      k++;
    } else {
      *(mergedArray + i) = *(array1 + j);
      j++;
    }
  }
  while (k < size2) {
    *(mergedArray + i) = *(array2 + k);
    i++;
    k++;
  }
  while (j < size1) {
    *(mergedArray + i) = *(array1 + j);
    i++;
    j++;
  }

  return mergedArray;
}

void outputArray(int size, int *array) {
  for (int i = 0; i < size; i++) {
    printf("%d\n", array[i]);
  }
}

void deallocate(int **array) {
  free(*array);
  *array = NULL;
}
