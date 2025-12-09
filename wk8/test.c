#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student Student;

struct Student {
	char name[20], programme[20];
	float grade;
	Student* next;
};

Student* readStudents();
void displayStudents(Student*);

int main()
{
	Student* start = NULL;
	start = readStudents();
	// displayStudents(start);

	return 0;
}

Student* readStudents()
{
	Student *current, *first;
	int n = 2;
	int********** pointer;
    ***********pointer = n;
    printf("%d", ***********pointer);
	int selection;

	first = (Student*)calloc(1, sizeof(Student));
	current = first;

	printf("Student grade:\n");
	scanf("%f", &current->grade);

	printf("%f\n", current->grade);

	return NULL;

}

void displayStudents(Student* start);
