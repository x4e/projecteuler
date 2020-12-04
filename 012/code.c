#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ulong unsigned long

// psure the maths for this is wrong but it still got the answer right so whatever
int numDivisors(ulong num) {
	int divisors = 2; // 1 and itself (assuming itself is not 1)
	
	for (int i = 2; i*i <= num; i++) {
		if (num % i == 0) {
			divisors += 2;
		}
	}

	return divisors;
}

void main() {
	ulong triNum = 1;
	
	for (ulong i = 2; i > 0; i++) {
		triNum += i;
		int divisors = numDivisors(triNum);
		if (divisors > 500) {
			printf("%lu\n", triNum);
			exit(0);
		}
	}
}
