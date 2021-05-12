/// Run with -lgmp

#include <stdio.h>
#include "gmp.h"

#define BASE_NUM 100

int main() {
	mpz_t base;
	mpz_init(base);
	mpz_set_ui(base, BASE_NUM);
	
	mpz_t fact;
	mpz_init(fact);
	mpz_set_ui(fact, 1);
	
	// while base != 1
	while (mpz_cmp_ui(base, 1) != 0) {
		// fact = base * fact
		mpz_mul(fact, base, fact);
		
		// base = base - 1
		mpz_sub_ui(base, base, 1);
	}
	
	mpz_t sum;
	mpz_init(sum);
	
	mpz_t digit;
	mpz_init(digit);
	
	mpz_t mod;
	mpz_init(mod);
	
	// while fact != 0
	while (mpz_cmp_ui(fact, 0) != 0) {
		// get the ones column
		// mod = fact % 10
		mpz_mod_ui(mod, fact, 10);
		// add ones column to sum
		// sum = sum + mod
		mpz_add(sum, sum, mod);
		// divide fact by 10 to discard ones column
		// fact /= 10
		mpz_tdiv_q_ui(fact, fact, 10);
	}
	
	gmp_printf("%Zd\n", sum);
	
	return 0;
}
