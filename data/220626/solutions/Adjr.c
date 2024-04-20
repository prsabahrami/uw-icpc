#include <stdio.h>

static double aire(int nn, double rr) {
    double bb, xx;
    bb = 0.5 / rr;
    xx = 1.0;
    while (nn > 0) {
	if (xx < bb) {
	    xx = (xx - rr + 0.25 / xx) / (1.0 - rr);
	} else {
	    xx *= 1.0 + rr;
	}
	nn -= 1;
    }
    return xx;
}

int main(void) {
    int nn;
    double rr;
    while (scanf("%d %lf", &nn, &rr) == 2) {
	if (nn == 0) break;
	printf("%.3f\n", aire(nn, rr));
    }
    return 0;
}
