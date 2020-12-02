#include <stdlib.h>
#include <stdio.h>

#define lim 4000000

void main() {
	int sum = 0;
	int a = 1;
	int b = 2;
	
	while (b <= lim) {
		if (a % 2 == 0) sum += a;
		if (b % 2 == 0) sum += b;
		a = b + a;
		b = b + a;
	}
	printf("%d\n", sum);
}
