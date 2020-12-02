#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ulong unsigned long

#define base 10
#define limit 999

bool isPalindrome(ulong num) {
	const int length = snprintf(NULL, 0, "%lu", num) + 1;
	char str[length];
	snprintf(str, length, "%lu", num);

	int x = 0;
	int y = length - 2;
	while (x < y) {
		if (str[x] != str[y]) return false;
		x += 1;
		y -= 1;
	}

	return true;
}

void main() {
	ulong largest = 0;
	
	for (ulong i1 = 0; i1 <= limit; i1++) {
		for (ulong i2 = 0; i2 <= limit; i2++) {
			ulong product = i1 * i2;
			if (product > largest && isPalindrome(product)) {
				largest = product;
			}
		}
	}
	printf("%d\n", largest);
}

