/*
Author: Pavel Soshenko Gnezdilov
Date: 09/12/2025
The program reads patient's info from argv, creating a queue using
structs, and the it outputs the queue to the stdout. Last line
contains the count of high priority patients.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Patient Patient;

/*
Function prototypes
For this program we will need the following functions:
    1. The funciton to read all the patients
    2. Auxiliary function to allocate memory to a struct
    3. Function that outputs the queue
*/

Patient *readPatients(int, char **);
Patient *allocateMemory();
void displayPatients(Patient *);

struct Patient {
  int id;
  char name[50];
  int priority;
  Patient *next;
};

// main function
int main(int argc, char *argv[]) {
  Patient *first = readPatients(argc, argv);
  displayPatients(first);

  return 0;
}

Patient *readPatients(int argc, char **argv) {
  Patient *first = allocateMemory();
  Patient *patient = first;
  int count = 2;

  patient->id = 1;
  strcpy(patient->name, argv[2]);
  patient->priority = atoi(argv[3]);

  for (int i = 4; i < argc; i += 2) {
    patient->next = allocateMemory();
    patient = patient->next;

    patient->id = count;
    strcpy(patient->name, argv[i]);
    patient->priority = atoi(argv[i + 1]);

    count++;
  }

  return first;
}

Patient *allocateMemory() {
  Patient *patient = calloc(1, sizeof(Patient));

  if (!patient) {
    printf("Unable to allocate memory\n");
    exit(0);
  }

  patient->next = NULL;

  return patient;
}

void displayPatients(Patient *first) {
  Patient *current = first;
  int priority_count = 0;

  while (current) {
    int id = current->id;
    char *name = current->name;
    int priority = current->priority;

    if (priority >= 4) {
      priority_count++;
    }

    printf("ID: %d, Name: %s, Priority: %d\n", id, name, priority);
    current = current->next;
  }
  printf("High priority count: %d\n", priority_count);
}
