#include <stdlib.h>
#include <stdio.h>

#define bool int
#define true 1
#define false 0

#define ulong unsigned long

ulong largestPrime(ulong num) {
	ulong largest = 0;

	while (true) {
		bool found = false;
		for (ulong i = 2; i*i < num; i++) {
			if (num % i == 0) {
				if (i > largest) largest = i;
				num = num / i;
				found = true;
				break;
			}
		}
		if (!found) break;
	}
	if (num > largest) largest = num;

	return largest;
}

void main() {
	printf("%lu\n", largestPrime(600851475143));
}
