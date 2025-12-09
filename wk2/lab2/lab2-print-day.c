#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]) {
	int n = atoi(argv[1]);
	char*days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
			"Friday", "Saturday"};
	
	printf("%s\n", days[n - 1]);
	
	exit(0);
}
