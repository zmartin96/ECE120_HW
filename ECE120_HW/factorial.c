/*
 *
 * Factorial!: Computes the factorial of a positive integer
 *
 */
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int factorial(int n, int m)
{
	int fact;
	
	// 0!==1
	if (m==0) fact=1;
	else fact=m;
	
	if((pow(2,31)-1)/n<m) fact=-1; // will result in overflow
	else if (n>0)
	{
		fact*=n;
		fact=factorial(n-1,fact);
	}
	return fact;
};


int main2(void)
{
	/* Initialization */
	int fact, // user input
	result; // calculated output
	bool notAcceptable=0; // initialized to false (acceptable)
	
	do{
		printf("Please enter a number: ");
		scanf("%d", &fact);
		
		result=factorial(fact-1,fact);
		
		if (result<1) // factorial should not be 0 or negative
		{
			notAcceptable=1;
			printf("The input is not acceptable, please try again.\n");
		}
		else notAcceptable=0;
		printf("%d", result);
		
	} while (notAcceptable==1); // while notAcceptable is true
	
	printf("\n%d! = %d\n\n", fact, result);
	
	return 0;
}





// if the input is negative, this version makes the input positive and returns -(fact!) ie -5! = -120
int main1(void)
{
	/* Initialization */
	int fact, // user input
	result; // calculated output
	bool neg=0, // initialized to false (not negative)
	overflow=0; // initialized to false (no overflow)
	do{
		printf("Please enter a number: ");
		scanf("%d", &fact);
		
		
		if (fact<0)
		{
			fact*=-1;
			neg=1;
		}
		
		result=factorial(fact-1,fact);
		
		if (result<1)
		{
			overflow=1;
			printf("The input is not acceptable, please try again.\n");
		}
		else overflow=0;
		
	} while (overflow==1); // while overflow is true
	
	printf("%d! = %d\n", (int) pow(-1,neg)*fact, (int) pow(-1,neg)*result);
	
	return 0;
}
