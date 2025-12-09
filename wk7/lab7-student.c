/*
Author: Pavel Soshenko Gnezdilov
Date: 26/10/2025
The program takes student information, dynamically expanding memory allocated
for storing students. Outputs everyone at the end.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student Student;

struct Student {
	char name[20];
	char course[20];
	float grade;
};

// Function prototypes
/* We will need the following functions:
	1. To read the students
	2. To expand memory for students
	3. To display all the students
*/
void read(int, char**, Student*);
Student* expMemory(Student*, int);
void dispAll(Student*, int);

int main(int argc, char* argv[])
{
	Student* students = calloc(2, sizeof(Student));
	if (!students)
	{
		printf("Failed to allocate memory\n");
		exit(1);
	}
	
	if ((argc - 1) / 3 > 2) students = expMemory(students, argc);

	read(argc, argv, students);
	dispAll(students, argc);

	return 0;

}

void read(int argc, char** argv, Student* students)
{
	int count = 0;
	for (int i = 1; i < argc; i += 3)
	{
		strcpy(students[count].name, argv[i]);
		strcpy(students[count].course, argv[i + 1]);
		students[count].grade = atof(argv[i + 2]);
		count++;
	}
}

Student* expMemory(Student* students, int argc)
{
	Student* tmp = NULL;
	tmp = realloc(students, ((argc - 1) / 3) * sizeof(Student));
	if (!tmp)
	{
		printf("Failed to reallocate memory\n");
		free(tmp);
		students = NULL;
		exit(1);
	}
	students = tmp;

	return students;
}

void dispAll(Student* students, int argc)
{
	for (int i = 0; i < argc / 3; i++)
	{
		char* name = students[i].name;
		char* course = students[i].course;
		float grade = students[i].grade;
		printf("%s, %s, %.2f\n", name, course, grade);
	}
}
