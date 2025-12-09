/*
Author: Pavel Soshenko Gnezdilov
Date: 10/10/2025
The program stores the data of countries from the command-line and
displays a formatted table with population average below
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct city city;

struct city
{
	char country[50];
	char capital[50];
	float pop;
	int size;
};

// Function prototypes
void readCities(int, char**, city*);
void dispCities(int, city*);
float popAvg(int, city*);

int main(int argc, char* argv[])
{
	int n = argc / 4;
	city cities[50];

	readCities(argc, argv, cities);
	dispCities(n, cities);

	return 0;
}

void readCities(int argc, char** argv, city* cities)
{
	int count = 0;
	for (int i = 1; i < argc; i = i + 4)
	{
		strcpy(cities[count].country, argv[i]);
		strcpy(cities[count].capital, argv[i + 1]);
		cities[count].pop = atof(argv[i + 2]);
		cities[count].size = atoi(argv[i + 3]);
		count++;
	}
}

void dispCities(int n, city* cities)
{
	printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
	for (int i = 0; i < n; i++)
	{
		char* country = cities[i].country;
		char* capital = cities[i].capital;
		int size = cities[i].size;
		float pop = cities[i].pop;

		printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", country, capital, size, pop);

	}
	float avg = popAvg(n, cities);
	printf("Population average: %.2f\n", avg);
}

float popAvg(int n, city* cities)
{
	float total = 0;
	for (int i = 0; i < n; i++)
	{
		total = total + cities[i].pop;
	}

	return total / n;
}
