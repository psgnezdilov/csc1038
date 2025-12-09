#include <stdlib.h>
#include <stdio.h>

int main(int argc, char*argv[]) {
	int total = 0;
	for (int i = 1; i < argc; i++) {
		int n = atoi(argv[i]);

		if (! (n % 2 == 0) ) {
			total++;
		}
	}
	printf("%d\n", total);
	
	exit(0);
}
