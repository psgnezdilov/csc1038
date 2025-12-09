
#include <stdio.h>
#include <string.h>

int main(void) {
  FILE *f = fopen("test.bin", "wb");
  if (!f)
    return 1;

  const char *name = "Pasha";
  int name_len = strlen(name);

  const char *college = "DCU";
  int college_len = strlen(college);

  int age = 20;
  float grade = 92.5f;

  fwrite(&name_len, sizeof(int), 1, f);
  fwrite(name, sizeof(char), name_len, f);

  fwrite(&college_len, sizeof(int), 1, f);
  fwrite(college, sizeof(char), college_len, f);

  fwrite(&age, sizeof(int), 1, f);
  fwrite(&grade, sizeof(float), 1, f);

  fclose(f);
  return 0;
}
