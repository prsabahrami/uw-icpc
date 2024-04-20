#define TOL (1e-8)
#define max(a,b) ((a)<(b)?(b):(a))
#include <stdio.h>
#include <math.h>

struct vec {
    double x,y,z;
    vec() { x = y = z = 0; }
    vec( double _x, double _y, double _z ) { x = _x; y = _y; z = _z; }
    vec cross( vec o ) {
        return vec( y*o.z - z*o.y, z*o.x - x*o.z, x*o.y - y*o.x );
    }
    double norm() {
        return sqrt( x*x+y*y+z*z );
    }
    vec normalize() {
        double n = norm();
        if( z<0 ) n = -n;
        return vec( x/n, y/n, z/n );
    }
};
struct loc { 
    double lat, lng;
    vec torec() {
        return vec( cos(lat) * cos(lng), cos(lat) * sin(lng), sin(lat) );
    }
};
double readangle() {
    double deg, min;
    char suf;
    scanf( "%lf,%lf%c ", &deg, &min, &suf );
    deg += min/60;
    if( suf == 'S' ) deg = -deg;
    if( suf == 'W' ) deg = 360-deg;
    return deg * M_PI / 180;
}
loc readloc() {
    loc ret;
    ret.lat = readangle();
    ret.lng = readangle();
    return ret;
}
void printlat( double lat ) {
    char suf = 'N';
    if( lat < 0 ) {
        lat = -lat; suf = 'S';
    }
    int mins = (int) ( lat / M_PI * 180 * 60 + 0.5 );
    printf( "%u,%u%c\n", mins/60, mins%60, suf );
}
main() {
    int N;
    scanf( "%d ", &N );
    while(N--) {
        loc sl, el;
        vec s, e;
        sl = readloc(); el = readloc();
        if( sl.lng > el.lng ) {
            loc tmp = sl; sl = el; el = tmp;
        }
        s = sl.torec(); e = el.torec();
        vec n = s.cross(e);
        if( fabs( n.norm() ) < TOL ) {
            if( M_PI/2 - sl.lat < TOL || M_PI/2 - el.lat < TOL ) {
                puts( "90,0N" ); continue;
            }
            puts( "undefined" ); continue;
        }
        if( 1-fabs(n.z) < TOL ) { // equator
            puts( "0,0N" ); continue;
        }
        if( fabs(n.z) < TOL ) { // meridian
            if( sl.lat + el.lat > 0 ) {
                puts( "90,0N" ); continue;
            }
            printlat( max( sl.lat, el.lat ) ); continue;
        }
        n = n.normalize();
        double lat = acos( n.z );
        double lng = atan2( -n.y, -n.x );
        if( lng < 0 ) lng += 2*M_PI;
        if( el.lng - sl.lng < M_PI ) {
            if( el.lng > lng && sl.lng < lng ) {
                printlat( lat );
            } else printlat( max( el.lat, sl.lat ) );
        } else {
            if( !( el.lng > lng && sl.lng < lng  ) ) {
                printlat( lat );
            } else printlat( max( el.lat, sl.lat ) );
        }
    }
}
