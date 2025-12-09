#include <stdio.h>

int main(int argc, char* argv[])
{
	FILE *pfile = fopen("t.txt", "r");
	if (!pfile) {
		return 1;
	}
	fclose(pfile);
	pfile = NULL;
}
