/*
 *
 * power_of_five.c: Computes 5 to the power of a positive integer
 *
 */
#include <stdio.h>
#include <math.h>
int main(void)
{
	/* Declare variables */
	int counter; /* loop counter */
	int product; /* result, 5^N */
	int endCount; /* power N */
	/* Read value of N */
	printf("This program will compute 5^N; enter N: ");
	scanf("%d", &endCount);
	
	if (endCount<0)
	{
		// note that C does not have try/catch blocks
		printf("The operation is undefined for negative integers\n\n");
		return 0;
	}
	
	/* Compute 5^N */
	product = 1;
	for (counter = 1; counter <= endCount; counter++)
	{
		if ((pow(2,31)-1)/5<product) // same as 2147483647/5 if you don't want to include math lib
		{
			printf("The value exceeds the supported numerical range\n\n");
			return 0;
		}
		product = 5*product;
	}
	/* Print the answer */
	printf("%d\n\n", product);
	return 0;
}
