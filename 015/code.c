#include <stdio.h>

#define GRID_SIZE 20
#define ulong unsigned long long

int main() {
	ulong grid[GRID_SIZE + 1][GRID_SIZE + 1];
	
	for (ulong y = 0; y <= GRID_SIZE; y++) {
		for (ulong x = 0; x <= GRID_SIZE; x++) {
			grid[y][x] = 0;
		}
	}
	
	grid[0][0] = 1;
	
	for (ulong y = 0; y <= GRID_SIZE; y++) {
		for (ulong x = 0; x <= GRID_SIZE; x++) {
			ulong num = grid[y][x];
			if (x > 0) {
				num += grid[y][x-1];
			}
			if (y > 0) {
				num += grid[y-1][x];
			}
			grid[y][x] = num;
			//printf("%d,%d\n", x, y);
		}
	}
	
	for (ulong y = 0; y <= GRID_SIZE; y++) {
		for (ulong x = 0; x <= GRID_SIZE; x++) {
			printf("%lu ", grid[y][x]);
		}
		printf("\n");
	}	
	
	return 0;
}
