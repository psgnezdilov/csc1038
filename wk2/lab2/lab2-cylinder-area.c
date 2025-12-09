#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415

int main(int argc, char*argv[]) {
	if (argc == 1) {
		printf("No input given!\n");
	}
	else if (argc == 2) {
		printf("Two arguments needed!\n");
	}
	else if (atoi(argv[1]) < 0 || atoi(argv[2]) < 0) {
		printf("The radius or height cannot be negative!\n");
	}
	else {
		int radius = atoi(argv[1]);
		int height = atoi(argv[2]);
		float area = 2 * PI * radius * height + 2 * PI * radius * radius;
		printf("%.2f\n", area);
	}
}
