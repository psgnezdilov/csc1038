/*
Author: Pavel Soshenko Gnezdilov
Date: 27/11/2025
The program accepts a string as an argument and reverses it using
pointers
*/

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
char *lastPointer(char *);
void reverse(char *, char *);

int main(int argc, char *argv[]) {
  char *string = argv[1];
  char *last = lastPointer(string);

  reverse(string, last);
  printf("%s\n", string);
  printf("%p\n", last);

  return 0;
}

char *lastPointer(char *string) {
  char *curr = string;
  if (*curr == '\0')
    return curr;
  while (*(curr + 1) != '\0') {
    curr++;
  }
  return curr;
}

void reverse(char *front, char *end) {
  while (front < end) {
    char tmp = *end;
    *end = *front;
    *front = tmp;
    front++;
    end--;
  }
}
