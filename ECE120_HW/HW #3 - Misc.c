//
//  HW #3 - Misc.c
//  ECE120_HW
//
//  Created by Zachary Martin on 9/11/23.
//

#include <stdio.h>
int basicIO(void)
{
	double weight;
	int age;
	printf("Type your weight: ");
	scanf("%lf",&weight);
	printf("\nType your age: ");
	scanf("%d",&age);
	printf("\n\nYour weight is %lf lbs\nYour age is %d\n\n",weight,age);
	return 0;
}


int mainx(void)
{
	int a = 0x3794;
	int b = 0x8268;
	
	printf("a | b = 0x%X\n", a|b);
	printf("a ^ b = 0x%X\n", a^b);
	printf("~a    = 0x%X\n", ~a);
	printf("a & b = 0x%X\n", a&b);

	return 0;
}
