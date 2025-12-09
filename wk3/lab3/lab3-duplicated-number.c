#include<stdio.h>
#include<stdlib.h>

int duplicate(int array[], int size);

int main(int argc, char* argv[])
{
	int size = argc - 1;
	int array[size];
	int dup;

	// Put all the numbers from arguments in an array
	for (int i = 1; i < argc; i++)
	{
		array[i - 1] = atoi(argv[i]);
	}

	duplicate(array, size);

	return(0);
}

int duplicate(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (array[i] == array[j])
			{
				printf("%d\n", array[i]);
				return(0);
			}
		}
	}
	
	printf("no duplicated number\n");

	return(0);
}
