#include <stdio.h>
#include <string.h>

#define uint unsigned long

#define low 1
#define high 1000

void numAsStr(char* str, uint num) {
	// thousands
	if (num > 999) {
		uint thousand = num / 1000;
		numAsStr(str, thousand);
		strcat(str, "thousand");
		numAsStr(str, num - (thousand * 1000));
	}
	// hundreds
	else if (num > 99) {
		uint hundred = num / 100;
		numAsStr(str, hundred);
		strcat(str, "hundred");
		
		// hundreds need an "and" if non zero tens column
		uint ten = num - (hundred * 100);
		if (ten != 0) {
			strcat(str, "and");
			numAsStr(str, ten);
		}
	}
	// tens
	else if (num > 9) {
		uint ten = num / 10;
		// 10-19 needs special handling of ones column
		if (ten == 1) {
			if (num == 10) strcat(str, "ten");
			else if (num == 11) strcat(str, "eleven");
			else if (num == 12) strcat(str, "twelve");
			else if (num == 13) strcat(str, "thirteen");
			else if (num == 14) strcat(str, "fourteen");
			else if (num == 15) strcat(str, "fifteen");
			else if (num == 16) strcat(str, "sixteen");
			else if (num == 17) strcat(str, "seventeen");
			else if (num == 18) strcat(str, "eighteen");
			else if (num == 19) strcat(str, "nineteen");
			return;
		}
		// others can have one column appended
		else if (ten == 2) strcat(str, "twenty");
		else if (ten == 3) strcat(str, "thirty");
		else if (ten == 4) strcat(str, "forty");
		else if (ten == 5) strcat(str, "fifty");
		else if (ten == 6) strcat(str, "sixty");
		else if (ten == 7) strcat(str, "seventy");
		else if (ten == 8) strcat(str, "eighty");
		else if (ten == 9) strcat(str, "ninety");
		numAsStr(str, num - (ten * 10));
	}
	// ones
	else if (num == 1) strcat(str, "one");
	else if (num == 2) strcat(str, "two");
	else if (num == 3) strcat(str, "three");
	else if (num == 4) strcat(str, "four");
	else if (num == 5) strcat(str, "five");
	else if (num == 6) strcat(str, "six");
	else if (num == 7) strcat(str, "seven");
	else if (num == 8) strcat(str, "eight");
	else if (num == 9) strcat(str, "nine");
	else if (num == 0) strcat(str, "");
}

int main() {
	uint chars = 0;
	
	char str[50];
	for (uint i = low; i <= high; i++) {
		memset(str, 0, sizeof(str));
		numAsStr(str, i);
		chars += strlen(str);
	}
	printf("%u\n", chars);
	
	return 0;
}
