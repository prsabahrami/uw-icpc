#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define EPS 1e-9

char direction[8][10] = {
	"east", "northeast", "north", "northwest",
	"west", "southwest", "south", "southeast"
};
double dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
double dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

main() {
	double r, x1, y1, x2, y2, x3, y3;
	bool first = true;
	while( cin >> r >> x1 >> y1 >> x2 >> y2 ) {
		if( !first ) cout << '\n'; first = false;
		for( int d1 = 0; d1 < 8; d1++ )
		for( int d2 = 0; d2 < 8; d2++ )
		if( (d1-d2+8)%8 == 1 || (d1-d2+8)%8 == 7 ) {
			double lo = 0.0, hi = 2*r, dist;
			for( int rep = 0; rep < 60; rep++ ) {
				dist = (hi+lo)/2;
				x3 = x1 + dist*dx[d1]; y3 = y1 + dist*dy[d1];
				if( ((y2-y3)*dx[d2] - (x2-x3)*dy[d2]) *
					((y2-y1)*dx[d2] - (x2-x1)*dy[d2]) > 0 )
					lo = dist; else hi = dist;
			}
			if( x3*x3 + y3*y3 > r*r+EPS ) continue;
			if( fabs((y2-y3)*dx[d2] - (x2-x3)*dy[d2]) > EPS ) continue;
			if( (y2-y3)*dy[d2] < -EPS || (x2-x3)*dx[d2] < -EPS ) continue;
			if( fabs(x3-x1) + fabs(y3-y1) > EPS )
				printf( "%s %.10lf\n", direction[d1],
						sqrt((y3-y1)*(y3-y1) + (x3-x1)*(x3-x1)) );
			if( fabs(x2-x3) + fabs(y2-y3) > EPS )
				printf( "%s %.10lf\n", direction[d2],
						sqrt((y2-y3)*(y2-y3) + (x2-x3)*(x2-x3)) );
			goto done;
		}
done:	;
	}
}
