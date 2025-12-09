#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]) {
      int height = atoi(argv[1]);
	for(int n = 0; n < height; n++) {
		if (n == 0 || n == height - 1) {
			for(int n = 0; n < height; n++) {
				printf("*");
			}
			printf("\n");
			}
		else {
			for(int i = 0; i < height; i++) {
				if (i == 0 || i == height - 1) {
					printf("*");
				}
				else {
					printf(" ");
				}
			}
			printf("\n");
		}
	}
	exit(0);
}
