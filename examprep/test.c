#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
char matrix[3][3] = {
	                   {1,2,3},
	                   {4,5,6},
	                   {7,8,9}
	                 };
printf("value of matrix[0][0]        : %d\n", matrix[0][0]); /* the normal way */
printf("address of *matrix[0]  : %d\n", *matrix[0]); /* pointer and array */
printf("value of **matrix       : %d\n", **matrix); /* using pointer only */
return 0;
}
