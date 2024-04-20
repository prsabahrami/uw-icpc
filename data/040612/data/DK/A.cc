#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

main() {
	double L, n, C, Lp;
	double hi, lo, mid;
	double pi = acos(0.0)*2;

	while( cin >> L >> n >> C ) {
	  if (L < 0) break;
		if( n*C == 0 ) {printf( "%.3lf\n", 0.0 ); continue;}
		Lp = (1+n*C)*L;
		lo = 0.0; hi = pi/2;
		for( int i = 0; i < 100; i++ ) {
			mid = (hi+lo)/2;
			if( mid/sin(mid) > Lp/L ) hi = mid; else lo = mid;
		}
		printf( "%.3lf\n", (1-cos(mid))*Lp/2/mid );
	}
}
