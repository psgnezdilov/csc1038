#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int str_rev(char* string);

int main(int argc, char* argv[])
{
	str_rev(argv[1]);

	return 0;
}

int str_rev(char* string)
{
	for (int i = strlen(string) - 1; i >= 0; i--)
      {
	printf("%c", string[i]);
	}
	printf("\n");
	return 0;
}
