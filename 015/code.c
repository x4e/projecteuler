#include <stdio.h>

#define GRID_SIZE 20
#define ulong unsigned long long

int main() {
	// 2d array to represent the grid
	ulong grid[GRID_SIZE + 1][GRID_SIZE + 1];
	
	// initialise each grid entry to 0
	for (ulong y = 0; y <= GRID_SIZE; y++) {
		for (ulong x = 0; x <= GRID_SIZE; x++) {
			grid[y][x] = 0;
		}
	}
	
	// first entry is 1 to start it off
	grid[0][0] = 1;
	
	
	for (ulong y = 0; y <= GRID_SIZE; y++) {
		for (ulong x = 0; x <= GRID_SIZE; x++) {
			// Get the number for current space
			// This should be irrelevant except for the 1st space
			ulong num = grid[y][x];
			// If it exists, add the number of the left space
			if (x > 0) {
				num += grid[y][x-1];
			}
			// If it exists, add the number of the above space
			if (y > 0) {
				num += grid[y-1][x];
			}
			// Set the current space to the addition
			grid[y][x] = num;
		}
	}
	
	// The bottom right space contains the final number
	printf("%llu\n", grid[GRID_SIZE][GRID_SIZE]);
	
	return 0;
}
