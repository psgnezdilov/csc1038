/*
Author: Pavel Soshenko Gnezdilov
Date: 26/11/2025
The program takes the number of n stairs we have to climb and outputs
the total number of ways of reaching it by stepping 1 or 2 stairs at a time
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int a = 1;
  int b = 1;
  int result = 0;
  int n = atoi(argv[1]);

  if (n == 1) {
    printf("%d\n", 1);
  } else if (n == 0) {
    printf("%d\n", 0);
  } else {
    for (int i = 2; i <= n; i++) {
      result = a + b;
      a = b;
      b = result;
    }
    printf("%d\n", result);
  }

  return 0;
}
