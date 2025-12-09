#include <stdio.h>
#include <stdlib.h>

int sort(int array[], int size);

int main(int argc, char* argv[])
{
	int size = argc - 1;
	int array[size];

	// Put all the integers into they array
	for (int i = 1; i < argc; i++)
	{
		array[i - 1] = atoi(argv[i]);
	}

	// Call the sort function
	sort(array, size);

	return(0);
}

int sort(int array[], int size)
{
	int count = 1;

	while (count != 0){
		count = 0;

		for (int i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				int tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				count++;

			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		printf("%d\n", array[i]);
	}

	return(0);
}
