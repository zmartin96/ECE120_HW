//
//  HEX.c
//  ECE120_HW
//
//  Created by Zachary Martin on 11/8/23.
//
#include <stdio.h>
#include "showBits.h"

int HEX(void){
	int R0=0x3074,
		R1=0x3080,
		R2=0xD431,
		R3=0xCA1C;
	printf("R0: 0x%X\nR1: 0x%X\nR2: 0x%X\nR3: 0x%X\n\n",R0,R1,R2,R3);
	printf("R0: #%d\nR1: #%d\nR2: #%d\nR3: #%d\n\n",R0,R1,R2,R3);
	R3=R0&R2;
	R0=R0+R3;
	printf("R0: 0x%X\nR1: 0x%X\nR2: 0x%X\nR3: 0x%X\n\n",R0,R1,R2,R3);
	printf("R0: #%d\nR1: #%d\nR2: #%d\nR3: #%d\n\n",R0,R1,R2,R3);
	return 0;
};

int main(void)
{
	
	int16_t R2=213;
	int16_t R1=R2+0xEEFE;
	R1=R1+1;
	//printf("R1: %X\n",R1);
	//SHOW(short, 0xD032);
	//printf("\n\n0x0A0C & 0xFFFF: %X\n\n",0x0A0C & 0xFFFF);
	
	R1=0x0A0C;
	R2=16;
	for (int i=0;i<32;i++)
	{
		if ((R1 & 0x8000)-0x8000==0) R2--;
		R1=R1+R1;
		//printf("\nR1+R1: %X\nR2: %X\n",R1,R2);
	}
	
	//printf("\n~0x8000: %X\n~0x8000+1: %X\n",~0x8000,~0x8000+1);
	
	//printf("R0: %X\n",0x3000+0xFFFE);
	
	//printf("R2: %X\n",0x3003);
	//printf("M: %X",0xA400+0x3003);
	
	/*
	 0101 001 010 1 0 0001 	; R1 <-- R2 & x0001		Check last digit and store result in R1
	 0000 010 0 0000 0001 	; Brz	PC + x0001		if R1 =x0000, R2 is even, so we just need to add 1 into R1
	 1001 001 001 111111 	; R1 <-- NOT R1			otherwise, R1 is x0001, so we need to take its compliment by
	 ;												negating it and adding 1. currently, R1=xFFFE
	 0001 001 001 1 0 0001 	; R1 <-- R1 + x0001		if R2 is even, R1=x0001 (#1). if R2 is odd, R1=xFFFF (#-1)
	 */
	
	R1=0x0A0C;
	R2=0;
	R1=~R1;
	int16_t M;
	int j=1;
	printf("R1: %X\n",R1);
	do{
		M=R1;
		R1=R1&0x8000;
		if (R1!=0) R2++;
		printf("R2 (%d): %X\n",j,R2);
		R1=M;
		R1=R1+R1;
		printf("R1: %X\n",R1);
		
		j++;
	} while(R1);
	
	return 0;
}
