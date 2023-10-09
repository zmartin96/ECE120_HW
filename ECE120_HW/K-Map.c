#include <stdio.h>

unsigned int testFunction(unsigned int *function,
						  unsigned int*w,unsigned int*x,
						  unsigned int*y,unsigned int*z)
{
	if (*function==0)
	{
		// f(w,x,y,z) = w'x' + x'y' + y'z + z'w'
		return ((!*w&&!*x)||(!*x&&!*y)||(!*y&&*z)||(!*z&&!*w));
	}
	else
	{
		// g(w,x,y,z) = (x+y)(w'+y+z')
		return ((*x||*y)&&(!*w||*y||!*z));
	}
};

int kMap(void)
{
	// Hey Jonathan, have a nice day!
	unsigned int a, b, d, w, x, y, z;
	// definition of functions
	char funct[2][40]={"f(w,x,y,z) = w'x' + x'y' + y'z + z'w'",
						"g(w,x,y,z) = (x+y)(w'+y+z')"};
	unsigned int f;
	
	// iterates a, which picks the function (f or g)
	for (a=0;2>a;a++)
	{
		printf("Function %s:\n\n",*(funct+a));
		/* Print header for K-map. */
		printf("\t\t\t yz \n");
		printf("\t\t00 01 11 10 \n");
		printf("\t   _______________\n");
		
		// iterate y, where binary order=Gray code order
		for (w = 0; 2>w; w++)
		{
			/* Loop over input variable b in binary order. */
			for (b = 0; 2 > b; b++) 
			{
				/* Use variables b and y to calculate *
				 * input variable z (iterated in Gray code order). */
				x=(!b&&w)||(b&&!w);
				
				// print the vertical axis labels
				printf("wx=%u%u | ", w,x);
				
				// iterate w, where binary order=Gray code order
				for (y=0;2>y;y++)
				{
					/* Loop over d in binary order.*/
					for (d=0;2>d;d++)
					{
						/* Use variables w and d to calculate *
						 * input variable x (iterated in Gray code order). */
						z=(!y&&d)||(y&&!d);
						
						// call the function to calculate K-map entry
						f=testFunction(&a, &w, &x, &y, &z);
						
						// print resulting value
						printf(" %d ", f);
					}
					
				}
				/* End of row reached: print a newline character. */
				printf("\n");
			}
			
		}
		// End of function reached: two newlines for visual separation
		printf("\n\n");
	}
	return 0;
}

