/*
Author: Pavel Soshenko Gnezdilov
Date: 10/10/2025
The program reads 4 string arguments from a command-line with information about some city and outputs
a formatted result
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct City City;

struct City
{
	char country[30];
	char city[30];
	float pop;
	int size;
};

// Function prototypes
void displayCity(City);

int main(int argc, char* argv[])
{
	City dublin;

	strcpy(dublin.country, argv[1]);
	strcpy(dublin.city, argv[2]);
	dublin.pop = atof(argv[3]);
	dublin.size = atoi(argv[4]);

	displayCity(dublin);
}

void displayCity(City city)
{
	printf("%s\n", city.country);
	printf("%s\n", city.city);
	printf("%.2f million people\n", city.pop);
	printf("%d km2\n", city.size);
}
