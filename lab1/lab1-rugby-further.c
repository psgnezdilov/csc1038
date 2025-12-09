#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int result = 0;
	int values[4];
	int value = 0;

	printf("Enter tries, conversions, penalties, and drop-goals on 4 separate lines:\n");
	
	for (int i = 0; i < 4; i++) {

		// If a value is negative or invalid, count it as a zero
		if (scanf("%d", &value) != 1) {
			scanf("%*s");
			value = 0;
		}
		else if (value < 0) {
			value = 0;
		}

		values[i] = value;
	}
	
	// int n = sizeof(values)/sizeof(values[0]);
	// for (int i = 0; i < n; i++) {
	// 	printf("%d\n", values[i]);
	// }

	result = values[0] * 5 + values[1] * 2 + values[2] * 3 + values[3] * 3;
	printf("%d\n", result);

	return(0);
}
