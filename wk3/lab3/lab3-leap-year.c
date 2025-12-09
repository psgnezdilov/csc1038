#include <stdio.h>
#include <stdlib.h>

void leap_year(char* argv[]);

int main(int argc, char* argv[])
{

	leap_year(argv);

	return 0;
}

void leap_year(char* argv[])
{
	int start = atoi(argv[1]);
	int finish = atoi(argv[2]);

	for (; start <= finish; start++)
	{
		if (start >= 100 && start % 100 == 0 && start % 400 == 0)
		{
			printf("%d\n", start);
		}
		else if (start % 100 != 0 && start % 4 == 0) {
			printf("%d\n", start);
		}
	}
}
