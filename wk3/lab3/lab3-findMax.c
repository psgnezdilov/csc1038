#include<stdio.h>
#include<stdlib.h>

int findmax(int array[], int size);

int main(int argc, char* argv[])
{
      int integers[argc - 1];
	for (int i = 1; i < argc; i++)
      {
	integers[i - 1] = atoi(argv[i]);
      }

	int result = findmax(integers, argc - 1);
	printf("%d\n", result);

	return 0;
}

int findmax(int array[], int size)
{
	int biggest = -1;

	for (int i = 0; i < size; i++)
	{
		if (biggest < array[i]) {
			biggest = array[i];
		}
	}
	return biggest;
}
