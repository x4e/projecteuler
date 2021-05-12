#include <stdio.h>
#include <stdbool.h>

#define uint unsigned int

/// Whether given year is leap year
bool leapYear(uint year) {
	return (
		// A leap year occurs on any year evenly divisible by 4
		year % 4 == 0
		&&
		(
			// but not on a century
			year % 1000 != 0
			||
			// unless it is divisible by 400
			year % 400 == 0
		)
	);
}

/// Return days in month (where month is 0 indexed)
int daysInMonth(bool leap, uint month) {
	static int days[] = {
		31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};
	// On a leap year february has one more day
	if (leap && month == 1) return 29;
	return days[month];
}

int main() {
	uint sundays = 0;
	
	uint day = 0;
	for (uint year = 1900; year <= 2000; year++) {
		bool leap = leapYear(year);
		for (uint month = 0; month < 12; month++) {
			// count months with first day as sunday between 1901-2000
			if (year >= 1901 && (day % 7) == 6) {
				sundays += 1;
			}
			day += daysInMonth(leap, month);
		}
	}
	
	printf("%lu\n", sundays);
	
	return 0;
}
