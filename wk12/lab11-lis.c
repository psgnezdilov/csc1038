/*
Author: Pavel Soshenko Gnezdilov
Date: 20/11/2025
The program takes in an array of integers an searches for the longest incresing
sequence
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int findLIS(int *arr, int size) {
  int dp[MAX_SIZE];
  int maxLIS = 1;

  for (int i = 0; i < size; i++) {
    dp[i] = 1;
  }

  for (int i = 1; i < size; i++) {
    for (int j = 0; j < i; j++) {
      if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
        dp[i] = dp[j] + 1;
      }
    }

    if (dp[i] > maxLIS) {
      maxLIS = dp[i];
    }
  }

  return maxLIS;
}

int main(int argc, char *argv[]) {

  int size = argc - 1;
  int arr[MAX_SIZE];

  for (int i = 0; i < size; i++) {
    arr[i] = atoi(argv[i + 1]);
  }

  int result = findLIS(arr, size);
  printf("%d\n", result);

  return 0;
}
