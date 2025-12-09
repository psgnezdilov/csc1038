/*
Author: Pavel Soshenko Gnezdilov
Date: 13/11/2025
The program reads the binary input from a file and stores it into a struct
printing it afterwards to the stdout.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student Student;

// function prototypes
int readData(Student *, char *);
void dispData(Student *, int);

struct Student {
  char name[50];
  char college[50];
  int age;
  float grade;
};

int main() {
  char *filename = "test.bin";
  Student students[50];

  int count = readData(students, filename);
  dispData(students, count);

  return 0;
}

int readData(Student *students, char *filename) {
  int count = 0;
  FILE *pfile = NULL;
  pfile = fopen(filename, "rb");

  if (!pfile) {
    printf("Unable to open the file %s\n", filename);
    exit(1);
  }
  int length;
  while (fread(&length, sizeof(int), 1, pfile) > 0) {
    fread(students[count].name, sizeof(char), length, pfile);
    fread(&length, sizeof(int), 1, pfile);
    fread(students[count].college, sizeof(char), length, pfile);
    fread(&students[count].age, sizeof(int), 1, pfile);
    fread(&students[count].grade, sizeof(float), 1, pfile);
    count++;
  }
  fclose(pfile);
  pfile = NULL;
  return count;
}

void dispData(Student *students, int count) {
  for (int i = 0; i < count; i++) {
    printf("Name: %s\n", students[i].name);
    printf("College: %s\n", students[i].college);
    printf("Age: %d\n", students[i].age);
    printf("Grade: %.2f\n", students[i].grade);
  }
}
