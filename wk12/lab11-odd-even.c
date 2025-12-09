/*
Author: Pavel Soshenko Gnezdilov
Date: 20/11/2025
The program reads in a decimal number and check whether it's even or odd without
using modulus
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int n = atoi(argv[1]);
  int check = n - 1;
  n = n >> 1 << 1;

  if (n - check) {
    printf("Even\n");
  } else {
    printf("Odd\n");
  }

  return 0;
}
