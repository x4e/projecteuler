#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ulong unsigned long

#define base 10

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
	printf("%d\n", isPalindrome(6006));
	printf("%d\n", isPalindrome(60606));
	printf("%d\n", isPalindrome(40506));
}

