#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <arpa/inet.h>
#include <errno.h>

void print_byte_as_bits(char val) 
{
	for (int i = 7; 0 <= i; i--) {
		printf("%c", (val & (1 << i)) ? '1' : '0');
	}
}

void print_bits(char * ty, char * val, unsigned char * bytes, size_t num_bytes) 
{
	printf("(%*s) %*s = [ ", 15, ty, 16, val);
	
	for (size_t i = num_bytes-1; i<-1; i--) {
		print_byte_as_bits(bytes[i]);
		printf(" ");
	}
	
	printf("]\n");
}

#define SHOW(T,V) do { T x = V; print_bits(#T, #V, (unsigned char*) &x, sizeof(x)); } while(0)
