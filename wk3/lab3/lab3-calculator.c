#include<stdio.h>
#include<string.h>
#include<stdlib.h>

float multiply(float x, float y);
float divide(float x, float y);

int main(int argc, char*argv[]){
	float x = atof(argv[2]);
	float y = atof(argv[3]);

	if (strcmp(argv[1], "multiply") == 0)
	{
		float result = multiply(x, y);
		printf("%f\n", result);
	}

	else if (strcmp(argv[1], "divide") == 0 && y != 0)
	{
		float result = divide(x, y);
		printf("%f\n", result);
	}

	else {
		printf("invalid\n");
	}

	return 0;
	
}

float multiply(float x, float y){
	float result;

	result = x * y;
	return result;
}

float divide(float x, float y){
	float result;

	result = x / y;
	return result;
}
