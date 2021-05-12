#include <stdio.h>

#define uint unsigned long
#define tlen 15

uint main() {
	uint triangle[tlen][tlen] = {
		{75},
		{95,64},
		{17,47,82},
		{18,35,87,10},
		{20, 4,82,47,65},
		{19, 1,23,75, 3,34},
		{88, 2,77,73, 7,63,67},
		{99,65, 4,28, 6,16,70,92},
		{41,41,26,56,83,40,80,70,33},
		{41,48,72,33,47,32,37,16,94,29},
		{53,71,44,65,25,43,91,52,97,51,14},
		{70,11,33,28,77,73,17,78,39,68,17,57},
		{91,71,52,38,17,14,91,43,58,50,27,29,48},
		{63,66, 4,68,89,53,67,30,73,16,69,87,40,31},
		{04,62,98,27,23, 9,70,98,73,93,38,53,60, 4,23}
	};
	
	// iterate through each element in the triangle and add it's number toeither 
	// the above right or above left number - whichever is largest at the end of 
	// this process the largest number on the bottom row is the "maximum total"
	for (uint y = 1; y < tlen; y++) {
		for (uint x = 0; x <= y; x++) {
			uint max;
			
			// number above to the left
			uint left = 0;
			if (x > 0)
				left = triangle[y-1][x-1];
			// number above to the right
			uint right = triangle[y-1][x];
			
			if (right > left) {
				max = right;
			} else {
				max = left;
			}
			
			// add to this spaces number
			max += triangle[y][x];
			triangle[y][x] = max;
		}
	}
	
	// find max number at bottom row
	uint max = 0;
	uint y = tlen - 1;
	for (uint x = 0; x < tlen; x++) {
		uint num = triangle[y][x];
		if (num > max) {
			max = num;
		}
	}
	printf("%lu\n", max);
	
	return 0;
}
