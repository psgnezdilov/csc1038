/*
Author: Pavel Soshenko Gnezdilov
Date: 16/10/2025
The program reads 3 cities for each country from the argument line and outputs
the largest one for each country.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structs
typedef struct Country Country;

struct Country {
	char name[50];
	struct City {
		char city[50];
		int size;
	} cities[3];

};

// Function prototypes
void readInput(int, char**, Country*);
char* biggestCity(int, struct City*);
void dispCities(int, Country*);

int main(int argc, char* argv[])
{
	Country countries[50];
	int n = argc / 7;

	readInput(argc, argv, countries);
	dispCities(n, countries);

	return 0;
}

void readInput(int argc, char** argv, Country* countries)
{
	int count = 0;
	for (int i = 0; i < argc - 1; i += 7)
	{
		strcpy(countries[count].name, argv[i + 1]);
		strcpy(countries[count].cities[0].city, argv[i + 2]);
		countries[count].cities[0].size = atof(argv[i + 3]);
		strcpy(countries[count].cities[1].city, argv[i + 4]);
		countries[count].cities[1].size = atof(argv[i + 5]);
		strcpy(countries[count].cities[2].city, argv[i + 6]);
		countries[count].cities[2].size = atof(argv[i + 7]);
		count++;
	}
}

void dispCities(int n, Country* countries)
{
	for (int i = 0; i < n; i++)
	{
		char* city = biggestCity(3, countries[i].cities);
		printf("%s: %s\n", countries[i].name, city);
	}

}
char* biggestCity(int n, struct City* cities)
{
	int max_i = 0;
	for (int i = 1; i < n; i++)
		if (cities[i].size > cities[max_i].size)
		{
			max_i = i;
		}

	return cities[max_i].city;
}
