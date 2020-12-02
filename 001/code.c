#include <stdlib.h>
#include <stdio.h>

#define limit 1000

void main() {
	int sum = 0;
	for (int i = 0; i < limit; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			sum += i;
		}
	}
	printf("%d\n", sum);
}
