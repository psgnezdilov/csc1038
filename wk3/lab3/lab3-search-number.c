#include<stdio.h>
#include<stdlib.h>

int search(int array[], int size, int n);

int main(int argc, char* argv[])
{
	int size = argc - 2;
	int numbers[size];
	for (int i = 2; i < argc; i++)
	{
		numbers[i - 2] = atoi(argv[i]);
	}

	search(numbers, size, atoi(argv[1]));
}

int search(int array[], int size, int n)
{
	for (int i = 0; i < size; i++)
        {
		if (n == array[i])
		{
		printf("Found %d at %d\n", n, i);
		return 0;
		}
	}
	printf("%d not found\n", n);
	return 0;
}
