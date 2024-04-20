#include <math.h>
main() {
    int mins;
    double x,y,xx,yy;
    double dist=0;
    scanf( "%lf %lf ", &x, &y );
    while( scanf( "%lf %lf %lf %lf ", &x, &y, &xx, &yy ) == 4 ) {
        dist += hypot( xx-x, yy-y );
    }
    dist/=10000.0;
    mins = dist*60.0+.5;
    printf( "%u:%02u\n", mins/60, mins%60 );
}
