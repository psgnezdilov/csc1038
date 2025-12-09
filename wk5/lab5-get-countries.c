/*
Author: Pavel Soshenko Gnezdilov
Date: 10/10/2025
The program takes multiple cities from the commands line and prints them in a structured way
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct City City;

struct City
{
	char country[50];
	char city[50];
	float pop;
	int size;
};

// Function prototypes
void readCities(int*, char**, City*);
void displayCities(int*, City*);

int main(int argc, char* argv[])
{
	int n = argc / 4;
	City cities[50];

	readCities(&argc, argv, cities);
	displayCities(&n, cities);

	return 0;
}

void readCities(int* argc, char** args, City* cities_arr)
{
	int count = 0;
	for (int i = 1; i < *argc; i = i + 4)
	{
		strcpy(cities_arr[count].country, args[i]);
		strcpy(cities_arr[count].city, args[i + 1]);
		cities_arr[count].pop = atof(args[i + 2]);
		cities_arr[count].size = atoi(args[i + 3]);
		count++;
	}
}

void displayCities(int* n, City* cities_arr)
{
	printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");

	for (int i = 0; i < *n; i++)
	{
		char country[50];
		char city[50];
		strcpy(country, cities_arr[i].country);
		strcpy(city, cities_arr[i].city);
		int size = cities_arr[i].size;
		float pop = cities_arr[i].pop;
		printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", country, city, size, pop);
	}
}
