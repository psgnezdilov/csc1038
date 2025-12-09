#include <stdio.h>
#include <stdlib.h>

int main (int argc, char*argv[]) {
	int length = atoi(argv[1]);
	int height = atoi(argv[2]);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < length; j++) {
			if (i == 0 || i == height - 1 &&)
			printf("*");
		}
		printf("\n");
	}
}
