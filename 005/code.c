#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define divMin 1
#define divMax 20

void main() {
	for (int i = 1; i > 0; i++) {
		bool valid = true;
		for (int x = divMin; x <= divMax; x++) {
			if (i % x != 0) {
				valid = false;
				break;
			}
		}
		if (valid) {
			printf("%d\n", i);
			exit(0);
		}
	}
	exit(1);
}
