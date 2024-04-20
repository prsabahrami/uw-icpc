#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

int main()
{
	int i,j;
	double L,d,C,L2,R,delta,theta,x;

	while (scanf("%lf %lf %lf ", &L, &d, &C)==3) {
	  if (L < 0) break;
 		if (L < 1e-6 || d < 1e-6 || C < 1e-6) {
 			printf("0.000\n");
 			continue;
 		}
		L2 = d*C*L + L;
		L2/=2.0; L/=2.0;
		for (x = 1e20, delta=1e20; delta>=1e-12; delta/=2.0) {
			R = sqrt(x*x + L*L);
			if (fabs(x) < 1e-10) x = 1e-10;
			theta = atan(L/x);
			if (theta*R < L2) x-=delta;else x+=delta;
		}
		R = sqrt(x*x + L*L);
		printf("%.3lf\n", R-x);
	}
	return 0;
}
