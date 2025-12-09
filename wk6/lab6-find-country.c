/*
Author: Pavel Soshenko Gnezdilov
Date: 16/10/2025
The program reads a list of countries and outputs the ones that have
a size of less than 100.000km^2
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Struct prototypes
typedef struct Country Country;

// Function prototypes
void readCountries(int, char**, Country*);
void dispCountries(int, Country*);

// Structs
struct Country {
	char country[50];
	char capital[50];
	float pop;
	int size;
};

int main(int argc, char* argv[])
{
	int n = argc / 4;
	Country countries[50];

	readCountries(argc, argv, countries);

	dispCountries(n, countries);

	return 0;
}

void readCountries(int argc, char** argv, Country* countries)
{
	int count = 0;
	for (int i = 0; i < argc - 1; i = i + 4)
	{
		strcpy(countries[count].country, argv[i + 1]);
		strcpy(countries[count].capital, argv[i + 2]);
		countries[count].pop = atof(argv[i + 3]);
		countries[count].size = atoi(argv[i + 4]);
		count++;
	}
}

void dispCountries(int n, Country* countries)
{
	printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
	for (int i = 0; i < n; i++)
	{
		if (countries[i].size < 100000)
		{
			char* country = countries[i].country;
			char* capital = countries[i].capital;
			float pop = countries[i].pop;
			int size = countries[i].size;
			printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", country, capital, size, pop);
		}
	}
}
