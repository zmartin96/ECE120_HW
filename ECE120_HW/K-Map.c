#include <stdio.h>

int main(void)
{
	unsigned int a, b, c, d;
	unsigned int f;
	/* Print header for K-map. */
	printf("\t\t  bc \n"); // I did change some of the spacing to make it look a little nicer
	printf("\t  00 01 11 10 \n");
	printf("\t _______________\n");
	/* row-printing loop */
	for (a = 0; 2 > a; a=a+1) {
		printf("a=%u | ", a);
		/* Loop over input variable b in binary order. */
		for (b = 0; 2 > b; b=b+1) {
			/* Loop over d in binary order.*/
			for (d = 0; 2 > d; d=d+1)
			{
				/* Use variables b and d to calculate *
				 * input variable c (iterated in *
				 * Gray code order). */
				c=(!b&&d)||(b&&!d);
				/* Calculate and print one K-map entry *
				 * (function F(a,b,c) ). */
				
				// F(a,b,c) = (a+b+c’)(a’+b)(b’+c’)
				f=(a||b||!c)&&(!a||b)&&(!b||!c);
				
				printf(" %d ", f);
			}
		}
		/* End of row reached: print a newline character. */
		printf("\n");
	}
	return 0;
}

