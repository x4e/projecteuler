#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ulong unsigned long

#define targetPrime 10001

bool isPrime(ulong num) {
	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

void main() {
	int primesFound = 0;
	for (ulong i = 2; i > 0; i++) {
		if (isPrime(i)) {
			primesFound += 1;
			
			if (primesFound == targetPrime) {
				printf("%d\n", i);
				exit(0);
			}
		}
	}
	exit(1);
}
