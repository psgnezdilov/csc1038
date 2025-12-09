/*
Author: Pavel Soshenko Gnezdilov
Date: 24/10/2025
The program reads multiple floats and finds the second largest one
*/

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
// We will need two functions, one that allocates memory and
// one function that goes through the array and finds the second largest number
void allocateM(int, float**); // Here we need to pass the pointer of the pointer due to pass by value
float secondLg(int n, float* nums);

// Main function
int main(int argc, char* argv[])
{
	int n = argc - 1;
	float* nums;

	allocateM(n, &nums);

	// Fill the array
	for (int i = 0; i < n; i++)
	{
		nums[i] = atof(argv[i + 1]);
	}
	float result = secondLg(n, nums);

	printf("%.1f\n", result);

	free(nums);
	nums = NULL;

	return 0;
}

void allocateM(int n, float** nums)
{
	*nums = calloc(n, sizeof(float));

	if (!*nums)
	{
		printf("Unable to allocate memory\n");
		exit(1);
	}
}

float secondLg(int n, float* nums)
{
	float lg;
	float sLg;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			lg = nums[i];
		}
		if (i == 1)
		{
			sLg = nums[i];
			if (sLg > lg)
			{
				float tmp = sLg;
				sLg = lg;
				lg = tmp;
			}
		}
      else if (nums[i] > lg)
		{
			float tmp = lg;
			lg = nums[i];
			sLg = tmp;
		}
      else if (nums[i] > sLg && nums[i] < lg)
		{
			sLg = nums[i];
		}
	}
	return sLg;
}
