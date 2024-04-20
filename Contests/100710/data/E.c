#include <math.h>
#include <stdio.h>

double r = 6371009;
double sqr(double x) { return x*x; }
double torad(double deg) { return deg/180*M_PI; }
main() {
    int N;
    scanf("%d ", &N);
    while(N--) {
        double alat, alng, blat, blng;
        scanf("%lf %lf %lf %lf ", &alat, &alng, &blat, &blng);
        //printf("%lf %lf %lf %lf\n", alat, alng, blat, blng);
        alat = torad(alat);
        alng = torad(alng);
        blat = torad(blat);
        blng = torad(blng);
        double ax = cos(alat) * cos(alng);
        double ay = cos(alat) * sin(alng);
        double az = sin(alat);
        double bx = cos(blat) * cos(blng);
        double by = cos(blat) * sin(blng);
        double bz = sin(blat);
        double dist = r*sqrt(sqr(ax-bx)+ sqr(ay-by)+sqr(az-bz));
        double arc = r * acos(ax*bx + ay*by + az*bz);
        //printf("%lf %lf\n", dist, arc);
        double TOL=0.00001;
        int a1 = arc-dist+TOL+.5;
        int a2 = arc-dist-TOL+.5;
        if(a1 != a2) *((int*)5) = 0;
        printf("%.0lf\n", arc-dist);
    }
}
