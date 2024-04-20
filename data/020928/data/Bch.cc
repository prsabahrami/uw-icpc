#include <stdio.h>

bool exceeds_tau(int b, int a) {
	const double tau = 1.6180339887498948482045868343656;
	return (double) b > (double) a * tau;
}

bool wins(int a, int b) {
	if (a > b) { int c = a; a = b; b = c; }
	return (a > 0 && (b == a || exceeds_tau(b, a)));
}

int main(int argc, char *argv[]) {
	for (;;) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0) break;
		puts(wins(a,b) ? "Stan wins" : "Ollie wins");
	}
	return 0;
}

/* vim:ts=4:sw=4
 */
