#include <math.h>

#define TOL 0.000001

double sx1[10], sx2[10], sy1[10], sy2[10];
int ns;

int Num( double x, double y, int s ) {
	double dist, dx, dy;

	if( s == 0 ) {
		if( x > TOL && y > TOL && x < 100.0-TOL && y < 100.0-TOL )
			return 1;
		return 0;
	}
	dx = sx2[s-1]-sx1[s-1]; dy = sy2[s-1]-sy1[s-1];
	dist = hypot(dx,dy); dx /= dist; dy /= dist;
	dist = dx*(y-sy1[s-1])-dy*(x-sx1[s-1]);
	if( dist < TOL ) return 0;
	return Num( x, y, s-1 ) + Num( x+2*dy*dist, y-2*dx*dist, s-1 );
}

main() {
	int i, j, k, n;
	double x, y, z;

	scanf( " %d", &ns );
	for( i = 0; i < ns; i++ )
		scanf( " %lf %lf %lf %lf", &sx1[i], &sy1[i], &sx2[i], &sy2[i] );
	for( scanf( " %d", &n ); n > 0; n-- ) {
		scanf( " %lf %lf", &x, &y );
		printf( "%d\n", Num( x, y, ns ) );
	}
}
