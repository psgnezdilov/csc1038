// Find the nth Fibonacci Series using Dynamic Programming
#include <stdio.h>

int fibonacci(int n) {
  /* an array to store Fibonacci numbers. */
  int fib[n + 2]; // 1 extra to handle case, n = 0
  int i;

  /* we know the first two solutions*/
  fib[0] = 0;
  fib[1] = 1;

  for (i = 2; i <= n; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }

  return fib[n];
}

int main() {
  int n = 10;
  printf("%d", fibonacci(n));
  return 0;
}
