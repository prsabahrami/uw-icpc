#include <stdio.h>
#include <math.h>

#define EPS 10e-8

int main () {
  double D, V, R, r, v;
  double PI = acos(-1.0);
  double rl, rh;
  while(scanf("%lf%lf", &D, &V) == 2 && D) {
    V /= 2; R = D/2;
    if (PI*R*R*R - 1.0/3*PI*(R)*(R*R) < V) {
      printf("Too much\n");
      return 0;
    }
    rl = 0; rh = R;
    while (fabs(rl-rh)>EPS) {
      r = (rh+rl)/2;
      v = PI*R*R*R - 1.0/3*PI*(R-r)*(R*R+r*R+r*r) - PI*r*r*r;
      if (v<V)
	rh = r;
      else
	rl = r;
    }
    printf("%.3f\n", 2*r);
  }
  if (D) printf("missing end record\n");
  return 0;
}
