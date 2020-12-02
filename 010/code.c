#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define ulong unsigned long

#define limit 2000000

// Assumes number is odd and > 2
bool isPrime(ulong num) {
	int sqrtNum = (int)sqrt((double)num);
	for (int i = 3; i <= sqrtNum; i += 2) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

void main() {
	ulong sum = 2;
	for (ulong i = 3; i < limit; i += 2) {
		if (isPrime(i)) {
			sum += i;
		}
	}
	printf("%lu\n", sum);
}
