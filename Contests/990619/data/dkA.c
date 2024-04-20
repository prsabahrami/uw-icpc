#include <math.h>

main() {
	int i, j, k, a, b, s, m, n;
	double x, y, z;

	for(;;) {
		scanf( " %d %d %d %d %d", &a, &b, &s, &m, &n );
		if( a+b+s+m+n == 0 ) break;
		x = a*(double)m;
		y = b*(double)n;
		z = hypot( x, y );
		printf( "%.2lf %.2lf\n", atan2(y,x)*180.0/M_PI, z/s );
	}
}
