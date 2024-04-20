/*
    Input primes; for each, print least non-constant Magic bitstring
    of length (prime-1).
*/

#include <stdio.h>
#include <string.h>

#define OVERSIZE 100001
static char BitString[OVERSIZE]; /* using '0', '1' to represent bits */

static void doMagic(int sz) {
    int ix, quadres, delta;

    memset(BitString, '1', sz);
    BitString[sz] = '\0';
    quadres = 0;
    delta = 4;
    for (ix = 2; ix < sz; ix += 2) {
	quadres = (quadres + delta) % sz;
	BitString[quadres] = '0';
	delta += 8;
    }
    printf("%s\n", &BitString[1]);
}

int main(void) {
    int sz;

    while (scanf("%d", &sz) == 1) {
	if (sz == 0) break;
	/* sz must be prime, and less than OVERSIZE */
	if (sz == 2) {
	    printf("Impossible\n");
	} else {
	    doMagic(sz);
	}
    }
    return 0;
}

/* Tester: five largest inputs are 99929 99961 99971 99989 99991 */
