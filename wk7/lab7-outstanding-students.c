/*
Author: Pavel Soshenko Gnezdilov
Date: 26/10/2025
The program reads the student data from the argv, calculates the avg
and then outputs the students that are above avg and the avg itself
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student Student;

struct Student 
{
	char name[20];
	char course[20];
	float grade;
};

// Function prototypes
void read(int, char**, Student**, int*, float*);
Student* realM(Student**, int*);
void dispAll(int, Student*, float);

int main(int argc, char* argv[])
{
	float total = 0;
	int capacity = 2;
	Student* students = calloc(capacity, sizeof(Student));
	if (!students)
	{
		printf("Failed to allocate memory\n");
		free(students);
		students = NULL;
		exit(1);
	}
	read(argc, argv, &students, &capacity, &total);
	dispAll(argc, students, total);

	return 0;
}

void read(int argc, char** argv, Student** students, int* capacity, float* total)
{
	int count = 0;
	for (int i = 1; i < argc; i += 3)
	{
		if (i > *capacity)
		{
			*students = realM(students, capacity);
		}
		strcpy((*students)[count].name, argv[i]);
		strcpy((*students)[count].course, argv[i + 1]);
		(*students)[count].grade = atof(argv[i + 2]);
		(*total) += (*students)[count].grade;
		count++;
	}
}

Student* realM(Student** students, int* capacity)
{
	Student* tmp = realloc(*students, ((*capacity) + 2) * sizeof(Student));
	if (!tmp)
	{
		printf("Failed to reallocate memory\n");
		free(tmp);
		students = NULL;
		exit(1);
	}
	(*capacity) += 2;
	*students = tmp;

	return *students;
}

void dispAll(int argc, Student* students, float total)
{
	float avg = total / (argc / 3);
	for (int i = 0; i < argc / 3; i++)
	{
		if (students[i].grade > avg && strcmp(students[i].course, "CSCE") == 0)
		{
			printf("%s, %.2f\n", students[i].name, students[i].grade);
		}
	}
	printf("Average grade: %.2f\n", avg);
}
