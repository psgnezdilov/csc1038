/*
Author: Pavel Soshenko Gnezdilov
Date: 20/11/2025
The program takes at most 8 binary digits and converts them to a decimal number
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
The program will require the follwing functions:
    1. The function that will perform the conversion
*/
// prototypes
void binToDec(int *, char **, int);

// main function
int main(int argc, char *argv[]) {
  int digits = argc - 1;
  int result = 0;

  // Check whether it's 8 digits at most
  if (digits > 8) {
    printf("Too many binary digits entered.\n");
    return 0;
  }

  binToDec(&result, argv, digits);
  printf("%d\n", result);

  return 0;
}

void binToDec(int *result, char **argv, int digits) {
  int j = 0;
  for (int i = digits; i > 0; i--) {
    if (!(strcmp(argv[i], "0") == 0 || strcmp(argv[i], "1") == 0)) {
      printf("Only digits 1 and 0 are permitted.\n");
      exit(0);
    }
    int digit = atoi(argv[i]);

    *result = *result + digit * (1 << j);
    j++;
  }
}
