#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ulong unsigned long

#define limit 100

void main() {
	ulong sumOfSquares = 0;
	ulong squareOfSums = 0;
	for (ulong i = 1; i <= limit; i++) {
		sumOfSquares += (i * i);
		squareOfSums += i;
	}
	squareOfSums *= squareOfSums;
	
	printf("%d\n", squareOfSums - sumOfSquares);
}
