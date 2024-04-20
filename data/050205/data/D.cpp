/** Waterloo-2005-02-D: Beat the Spread!, Stefan Buettcher, 2005-01-30 **/

#include <stdio.h>
#include <stdlib.h>

// X + Y = S  and  X - Y = D ;  assume X > Y
int main() {
	int n, s, d, x, y;
	scanf("%i", &n);
	while (--n >= 0) {
		scanf("%i%i", &s, &d);
		x = (s + d) / 2;
		if (2 * x != s + d)
			printf("impossible\n");
		else {
			y = s - x;
			if (y < 0)
				printf("impossible\n");
			else
				printf("%i %i\n", x, y);
		}
	}
	return 0;
}


