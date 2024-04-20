/*
    Let r be the amount of rope-stretch, v be downward speed, g be
    the downward acceleration of gravity.

    Recognizing that
    - while James is in free-fall, r = f(t) is a quadratic, and
    - while James is constrained by the rope, r = f(t) is a sinusoid,
    one finds that in the two cases,

    v = sqrt[2g(l + r)]			(r <= 0)

    v = sqrt[a - k/w(r - gw/k)^2]	(r >= 0)

    where a is the constant that makes the velocities equal when r=0;
    namely a = g(2l + gw/k).
*/

#include <stdio.h>

#define GRAV 9.81
#define SMASH 10.0

int main(void) {
    double kk, ll, ss, ww, rr, vsq, wdk, t1;

    while (scanf("%lf %lf %lf %lf", &kk, &ll, &ss, &ww) == 4) {
	if ((kk == 0.0) && (ll == 0.0) && (ss == 0.0) && (ww == 0.0)) break;

	rr = ss - ll; /* stretch at impact */
	if (rr <= 0.0) {
	    /* free-fall touchdown */
	    vsq = 2.0 * GRAV * ss;
	} else {
	    wdk = ww / kk;
	    t1 = rr - GRAV * wdk;
	    vsq = GRAV * (2.0 * ll + GRAV * wdk) - t1 * t1 / wdk;
	}

	if (vsq < 0.0) {
	    printf("Stuck in the air.\n");
	} else if (vsq <= (SMASH*SMASH)) {
	    printf("James Bond survives.\n");
	} else {
	    printf("Killed by the impact.\n");
	}
    }

    return 0;
}
