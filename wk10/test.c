#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *pfile = NULL;
  char *filename = "testfile.txt";
  pfile = fopen(filename, "w");

  if (!pfile) {
    printf("Unable to to open %s.\n", filename);
  }

  printf("%p\n", pfile);
  fputc('a', pfile);
  printf("%p\n", pfile);
  fputc('b', pfile);
  printf("%p\n", pfile);

  fclose(pfile);
  pfile = NULL;

  return 0;
}
