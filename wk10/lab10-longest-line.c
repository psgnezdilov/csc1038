/*
Author: Pavel Soshenko Gnezdilov
Date: 15/11/2025
The program goes through the given file and finds the longest
line in the document. It prints the length (bytes) and the line itself
afterwards.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
FILE *openFile(char *);
char *arrRealloc(char *);
void findLongest(int *, char **, FILE *);

// main function
int main() {
  char *filename = "paragraph.txt";
  FILE *pfile = openFile(filename);
  int size;
  char *longest;
  findLongest(&size, &longest, pfile);

  fclose(pfile);
  pfile = NULL;

  printf("%d\n%s\n\n", size, longest);

  return 0;
}

FILE *openFile(char *filename) {

  FILE *pfile = fopen(filename, "r");

  if (!pfile) {
    printf("Unable to open the file %s\n", filename);
    return NULL;
  }

  return pfile;
}

char *arrRealloc(char *pArray) {
  free(pArray);
  pArray = calloc(200, sizeof(char));

  if (!pArray) {
    printf("Unable to reallocate the memory\n");
  }
  return pArray;
}

void findLongest(int *pSize, char **pLongest, FILE *pfile) {
  char *longest = calloc(200, sizeof(char));
  char *curr = calloc(200, sizeof(char));
  int size = 0;

  if (!curr || !longest) {
    printf("Unable to allocate memory\n");
    exit(1);
  }

  int curr_int = 0;
  char curr_ch;
  int i = 0;

  while (curr_int != -1) {
    curr_int = fgetc(pfile);
    curr_ch = curr_int;
    if (curr_ch == '\n') {
      curr[i] = '\0';
      if (i + 1 > size) {
        size = i + 1;
        longest = arrRealloc(longest);
        strcpy(longest, curr);
      }
      i = 0;
      curr = arrRealloc(curr);
    } else {
      curr[i] = curr_ch;
      i++;
    }
  }
  *pSize = size;
  *pLongest = longest;
}
