#include <stdio.h>

int main(void) {
	char name[20];
	fgets(name, sizeof(name), stdin);
	printf("%s\n", name);
	printf("%lu\n", sizeof(name));
}
