#include <stdio.h>
#include <stdlib.h>

#define CM_IN_INCH 2.54

int main(void) {
	float result = 0; int count = 1;

	for (int cm = 30; cm < 50; cm++) {
		
		result = cm / CM_IN_INCH;

		if (count < 5) {
			printf("%.2f ", result);
			count++;
		}

		else if (count == 5) {
			printf("%.2f\n", result);
			count = 1;
		}
	}

	return(0);

}
