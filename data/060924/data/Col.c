#include <math.h>
#include <stdio.h>

#define TOL 0.0000001

double hb, db, hn, dn, h;

double cyl(double height, double diam) {
    return height*diam*diam/4*M_PI;
}
double taper(double height, double d1, double d2) {
    double r1 = d1/2;
    double r2 = d2/2;
    return M_PI*(r1*r1+r1*r2+r2*r2)*height/3;
}
double partcyl(double height, double diam, double level) {
    double r = diam/2;
    //if(level<0) return cyl(height, diam)-partcyl(height, diam, -level);
    if(level<0) printf("crap1\n");
    if(level>r) return 0;
    if(r<TOL) return 0;
    return height*(r*r*acos(level/r)-level*sqrt(r*r-level*level));
}
double sq(double x) { return x*x; }
double cube(double x) { return x*x*x; }
double cone(double height, double d1) {
    double r1 = d1/2;
    return height*r1*r1*M_PI/3;
}
double parttaper(double height, double d1, double d2, double level) {
    double r1 = d1/2;
    double r2 = d2/2;
    if(level<0) {
        printf("crap2\n");
        return taper(height, d1, d2) - parttaper(height, d1, d2, -level);
    }
    if(level < TOL) return .5*taper(height, d1, d2);
    if(r1<r2) {
        printf("crap3\n");
    }
    if(level>r2) {
        //printf("foo %lf %lf %lf\n", r1, r2, level);
        double frac = (r1-level)/(r1-r2);
        //printf("fr %lf\n", frac);
        height *= frac;
        r2 = level;
    }
    if(r1-r2 < TOL) {
        return partcyl(height, d1/2+d2/2, level);
    }
    double rb = r1;
    double rn = r2;
    double k = level;
    double sqrn = sqrt(rn*rn-level*level);
    double sqrb = sqrt(rb*rb-level*level);
    double ret = -height/6*(-2*acos(k/rn)*rn*rn*rn+4*k*rn*sqrn+2*acos(k/rb)*rb*rb*rb-3*k*sqrb*rb+3*log(rb+sqrb)*k*k*k-k*k*k*atanh(sqrb/rb)-k*rb*sqrb-3*log(rn+sqrn)*k*k*k+k*k*k*atanh(sqrn/rn))/(rn-rb);
    if(ret != ret) printf("crap4 %lf %lf %lf %lf\n", r1, r2, level, height);
    return ret;
}
double standingUp(double level) {
    if(level < hb) {
        return cyl(level, db);
    } else if(level < h-hn) {
        return cyl(hb, db) + taper(level-hb, db, db-(level-hb)/(h-hn-hb)*(db-dn));
    } else {
        //printf("%lf %lf %lf\n",  cyl(level, db) , taper(h-hn-hb, db, dn) , cyl(level-(h-hn), dn));
        return cyl(hb, db) + taper(h-hn-hb, db, dn) + cyl(level-(h-hn), dn);
    }
}
double ld(double level) {
    if(level < 0) return standingUp(h)-ld(-level);
    return partcyl(hb, db, level) + parttaper(h-hb-hn, db, dn, level) + partcyl(hn, dn, level);
}
double lyingDown(double level) {
    level = db/2-level;
    return ld(level);
}
double bsrch(double lo, double hi, double target) {
    double mid = hi/2+lo/2;
    if(hi-lo < TOL) return mid;
    double ld;
    ld = lyingDown(mid);
    if(lyingDown(mid) > target) return bsrch(lo, mid, target);
    else return bsrch(mid, hi, target);
}
main() {
    while(1) {
        double volume, level, k;
        scanf("%lf %lf %lf %lf %lf %lf", &k, &hb, &db, &hn, &dn, &h);
        if(k==0 && hb==0 && db==0 && hn==0 && dn==0 && h==0) break;
        volume = standingUp(k);
    //printf("%lf %lf\n", standingUp(h), ld(0)*2);
        level = bsrch(0, db, volume);
        printf("%.3lf\n", level);
    //printf("%lf %lf\n", volume, lyingDown(level));
    //printf("%lf %lf %lf %lf\n", volume, lyingDown(15.482), lyingDown(15.481), level);
    }
}
