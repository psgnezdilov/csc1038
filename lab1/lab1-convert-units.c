#include <stdio.h>
#include <stdlib.h>

#define CM_IN_INCH 2.54

int main(int argc, char *argv[]) {
	float result = 0;
	
	result = atoi(argv[1]) / CM_IN_INCH;
	printf("%.2f\n", result);

	return(0);
}
