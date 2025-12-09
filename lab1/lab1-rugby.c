#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	int result = 0;

	result = atoi(argv[1]) * 5 + atoi(argv[2]) * 2 + atoi(argv[3]) * 3 + atoi(argv[4]) * 3;

	printf("%d\n", result);

	return(0);
}
