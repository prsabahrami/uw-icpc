#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n;
int rn[101], rw[101];

double val(double a, double b) {
	double ret = 0.0;
	for( int i = 0; i < n; i++ )
		if( rw[i] )
			ret += log(1 - 1/(exp(a + b*rn[i])+1));
		else
			ret += log(1/(exp(a + b*rn[i])+1));
	return ret;
}

double findb(double a) {
	double blo = -10.0, bhi = 10.0, bm1, bm2;
	for( int brep = 0; brep < 50; brep++ ) {
		bm1 = (blo*17 + bhi*15)/32;
		bm2 = (blo*15 + bhi*17)/32;
		if( val(a, bm1) < val(a, bm2) )
			blo = bm1; else bhi = bm2;
	}
	return (blo+bhi)/2;
}

double finda() {
	double alo = -10.0, ahi = 10.0, am1, am2;
	for( int arep = 0; arep < 50; arep++ ) {
		am1 = (alo*17 + ahi*15)/32;
		am2 = (alo*15 + ahi*17)/32;
		if( val(am1, findb(am1)) < val(am2, findb(am2)) )
			alo = am1; else ahi = am2;
	}
	return (alo+ahi)/2;
}

main() {
	while( cin >> n && n ) {
		for( int i = 0; i < n; i++ ) cin >> rn[i] >> rw[i];
		double a = finda();
		printf( "%.4lf %.4lf\n", a, findb(a) );
	}
}
