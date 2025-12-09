#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]) {
	
	int total = 0;

	for (int i = 1; i < argc; i++) {
		int n = atoi(argv[i]);
		if (n % 2 == 0) {
			printf("%d - %d\n", i - 1, n);
			total++;
		}
	}

	if (!total) {
		printf("Not found!\n");
	}

	exit(0);
}
