#include <stdlib.h>
#include <stdio.h>

int main()
{
	char** pointer = calloc(3, sizeof(char*));
	printf("%p\n", &pointer);
	printf("%p\n", &pointer[1]);
}
