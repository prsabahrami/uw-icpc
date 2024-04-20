/*
Problem : Point of view in Flatland

In Flatland, there are three circular planets: their centers and radii
are given. Find a point in Flatland, from which all three planets appear
to have the same size (same angular diameter). Let's call such a point
an _isoobservation_ point.

The input has several lines.
Each line has nine numbers, three for each planet.
    Each triple has X and Y coordinates of a planet center, and the
    radius of that planet. Each radius is positive.
The input ends with a line with nine zeros; do not process this line.

For each input line, print the X and Y coordinates of an isoobservation
point in the format shown in the sample; but if there is no such point,
print "No solution".

To simplify the problem you may assume that:
    - The planets' centers are not all collinear.
    - The planets are totally disjoint.
    - The planets are transparent and non-refractive. That is, a planet
      is visible and has the same apparent shape and size, whether or
      not there's another planet in front of it.
    - The input data are such that the existence or non-existence of
      such a point is computable, even with slight rounding error. But
      use double-precision, eh?
*/

/* If there are two isoobservation points, this program prints both. */

#include <math.h>
#include <stdio.h>
#include <stdbool.h>

static double CenterX[3], CenterY[3], Radius[3];



/* The locus of isoobservation points of two planets is either a line
   or a circle.
   If it's a line, keep a point on the line and a vector along the line;
   if it's a circle, keep the center and radius. */
typedef struct {
    double px, py; /* point on line or center of circle */
    double vx, vy; /* vector along line */
    double ra;     /* radius */
    bool isLine;   /* %%% put last, to workaround GDB bug */
} isolocus;

static void computeIsolocus(int idx1, int idx2, isolocus *il) {
    double ux, uy, dist, rd, t1, t2;

    il->isLine = Radius[idx1] == Radius[idx2];
    if (il->isLine) {
	/* midpoint is on line */
	il->px = (CenterX[idx1] + CenterX[idx2]) / 2.0;
	il->py = (CenterY[idx1] + CenterY[idx2]) / 2.0;

	/* vx,vy is difference, rotated 90 degrees
	   (or -90 degrees; don't care which) */
	il->vx = CenterY[idx1] - CenterY[idx2];
	il->vy = CenterX[idx2] - CenterX[idx1];
    } else {
	/* compute distance and unit delta */
	ux = CenterX[idx2] - CenterX[idx1];
	uy = CenterY[idx2] - CenterY[idx1];
	dist = hypot(ux, uy);
	ux /= dist;
	uy /= dist;

	/* compute circle radius and center */
	rd = Radius[idx1] * dist;
	t1 = rd / (Radius[idx1] - Radius[idx2]);
	t2 = rd / (Radius[idx1] + Radius[idx2]);
	il->ra = fabs(t1 - t2) / 2.0;
	t1 = (t1 + t2) / 2.0;
	il->px = CenterX[idx1] + t1 * ux;
	il->py = CenterY[idx1] + t1 * uy;
    }
}



static void intersectLines(const isolocus *il1, const isolocus *il2) {
    double det, dx, dy, tt, xx, yy;

    det = il1->vx * il2->vy - il1->vy * il2->vx;
	/* If det==0, the planets are collinear. */
    dx = il1->px - il2->px;
    dy = il1->py - il2->py;
#if 1
    /* These two computations should come out the same. */
    tt = (dx * il2->vy - dy * il2->vx) / det;
    xx = il1->px - tt * il1->vx;
    yy = il1->py - tt * il1->vy;
#else
    tt = (dy * il1->vx - dx * il1->vy) / det;
    xx = il2->px + tt * il2->vx;
    yy = il2->py + tt * il2->vy;
#endif
    printf("%.2f %.2f\n", xx, yy);
}

static void intersectCircs(const isolocus *il1, const isolocus *il2) {
    double dx, dy, dist, aa, bb, xx, yy;

    dx = il2->px - il1->px;
    dy = il2->py - il1->py;
    dist = hypot(dx, dy);
    aa = (dist * dist + il1->ra * il1->ra - il2->ra * il2->ra) / (2.0 * dist);
    bb = il1->ra * il1->ra - aa * aa;
    if (bb < 0.0) {
	printf("No solution\n");
	return;
    }
    bb = sqrt(bb) / dist;
    aa /= dist;

    xx = il1->px + aa * dx;
    yy = il1->py + aa * dy;
    printf("%.2f %.2f, %.2f %.2f\n",
	xx + bb * dy, yy - bb * dx,
	xx - bb * dy, yy + bb * dx);
	    /* Here dx,dy is rotated. */
}



static void doit(void) {
    isolocus il1, il2;

    computeIsolocus(0, 1, &il1);
    computeIsolocus(0, 2, &il2);

    if (il1.isLine) {
	if (il2.isLine) {
	    intersectLines(&il1, &il2);
	} else {
	    /* avoid writing intersectLineCirc */
	    computeIsolocus(1, 2, &il1);
	    intersectCircs(&il1, &il2);
	}
    } else {
	if (il2.isLine) {
	    /* avoid writing intersectLineCirc */
	    computeIsolocus(1, 2, &il2);
	}
	intersectCircs(&il1, &il2);
    }
}

int main(void) {
    while (scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf",
	&CenterX[0], &CenterY[0], &Radius[0],
	&CenterX[1], &CenterY[1], &Radius[1],
	&CenterX[2], &CenterY[2], &Radius[2]) == 9)
    {
	if (Radius[0] == 0.0) break; /* input delimiter */
	doit();
    }

    return 0;
}
