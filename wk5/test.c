#include <stdio.h>
#include <stdlib.h>

typedef struct Player Player;

struct Player {
	char name[5];
	char pos[2];
	int goals;
	float price;
};

int main()
{
	char name[5];
	scanf("%s", name);
	printf("%lu\n", sizeof(name));
}

