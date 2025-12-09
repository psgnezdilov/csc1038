/*
Author: Pavel Soshenko Gnezdilov
Date: 16/10/2025
The program reads countries from the argument line and outputs
the formatted and sorted by population table
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Struct prototypes
typedef struct Country Country;

// Function prototypes
void readCountries(int, char**, Country*);
void sortCountries(int, Country*); // Here we could display them as we sort them
void dispCountries(int, Country*); // For the sake of readability we'll do it in another function

struct Country
{
	char country[50];
	char capital[50];
	float pop;
	int size;
};

int main(int argc, char* argv[])
{
	int n = argc / 4; // We know that for each country there are 4 entries
	Country countries[50]; // Array to store up to 50 countries
	
	readCountries(argc, argv, countries);
	sortCountries(n, countries); // Sorts countries and outputs a table

	return 0;
}

void readCountries(int argc, char** argv, Country* countries)
{
	int count = 0;
	for (int i = 0; i < argc - 1; i += 4)
	{
		strcpy(countries[count].country, argv[i + 1]);
		strcpy(countries[count].capital, argv[i + 2]);
		countries[count].pop = atof(argv[i + 3]);
		countries[count].size = atoi(argv[i + 4]);
		count++;
	}
}

void sortCountries(int n, Country* countries) // Selection sort
{
	for (int i = 0; i < n; i++)
	{
		int max_i = i;

		for (int j = i + 1; j < n; j++)
		{
			if (countries[j].pop > countries[max_i].pop)
			{
				max_i = j;
			}
		}
		Country tmp = countries[max_i];
		countries[max_i] = countries[i];
		countries[i] = tmp;
	}

	dispCountries(n, countries);
}

void dispCountries(int n, Country* countries)
{
	printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
	for (int i = 0; i < n; i++)
	{
		char* country = countries[i].country;
		char* capital = countries[i].capital;
		float pop = countries[i].pop;
		int size = countries[i].size;
		
		printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", country, capital, size, pop);
	}
}
