#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define uint unsigned int
#define ulong unsigned long
#define udouble unsigned double

#define targetSum 1000

void main() {
	for (ulong a = 1; a < 1000; a++) {
		for (ulong b = 1; b < 1000; b++) {
			if (a + b > 1000) continue;
			
			ulong aSquaredPlusBSquared = (a*a) + (b*b);
			double cSquared = sqrt((double)aSquaredPlusBSquared);
			ulong c = (ulong)round(cSquared);
			
			// check for inprecision in the sqrt 
			if (c * c != aSquaredPlusBSquared) continue;
			
			ulong sum = a + b + c;
			
			if (sum == 1000) {
				printf("%d\n", a * b * c);
				exit(0);
			}
		}
	}
	exit(1);
}

