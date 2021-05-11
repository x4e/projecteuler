/// Yes, this was the most imaginative thing I could come up with
/// Still runs very fast though.
/// Make sure to add -Igmp to gcc flags to include gmp.

#include <stdio.h>
#include "gmp.h"

#define base 2
#define exponent 1000

#define ulong unsigned long long
#define uint unsigned int

int main() {
	mpz_t num;
	mpz_init(num);
	
	// store base in an mpz
	mpz_t basez;
	mpz_init(basez);
	mpz_set_ui(basez, base);
	
	// num = basez % exponent
	mpz_pow_ui(num, basez, exponent);
	
	mpz_t sum;
	mpz_init(sum);
	while (mpz_cmp_ui(num, 0) != 0) {
		// mod = num % 10
		mpz_t mod;
		mpz_init(mod);
		mpz_mod_ui(mod, num, 10);
		
		// sum = sum + mod
		mpz_add(sum, sum, mod);
		
		// num /= 10
		mpz_tdiv_q_ui(num, num, 10);
	}
	
	gmp_printf("%Zd\n", sum);
	
	return 0;
}
