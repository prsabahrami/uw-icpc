#include <stdio.h>
#include <math.h>
#include <assert.h>

double PI = acos(-1);

int main () {
  double l, c, t, d;
  while (scanf("%lf%lf%lf",&l,&t,&c) == 3) {
    if (l < 0) break;
    d = l*c*t;
    assert(d<=l/2);
    double low = 0, high = PI, med = (low+high)/2, r;
    if (l == 0 || t == 0 || c == 0) {
      printf("%.3f\n",0.0);
      continue;
    }
    while (fabs(high-low) > 1e-12) {
      //      printf("%.3f\n",med);
      r = l/(sin(med/2)*2);
      if (med*r < l+d)
	low = med;
      else if (med*r > l+d)
	high = med;
      else break;
      med = (low+high)/2;
    }
    printf("%.3f\n",r-r*cos(med/2));
  }
}
