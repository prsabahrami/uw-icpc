#include <iostream>
#include <cstdio>
using namespace std;

#define MINMONEY (-512 * 30)
#define MAXMONEY (512 * 3 * 30)
#define PR3 (1.0 / 14)
#define PR2 (1.0 / 14)
#define PR1 (2.0 / 14)

int K, M, L;
double memo[31][MAXMONEY - MINMONEY + 1];
double doit(int r, int m) {
	double &ret = memo[r][m - MINMONEY];
	if( ret != -1.0 ) return ret;
	if( r >= K && m > 0 ) return ret = 1.0;
	ret = 0.0;
	double p = 1.0;
	int r2 = r, b = 1;
	for(;;) {
		if( ++r2 > M ) return ret;
		ret += (p*PR1 * doit(r2, m+b));
		ret += (p*PR2 * doit(r2, m+b+b));
		ret += (p*PR3 * doit(r2, m+b+b+b));
		m -= b;
		p *= 1.0-PR1-PR2-PR3;
		if( r2 >= K && m > 0 ) return ret += p;
		b <<= 1;
		if( b > L ) return ret += p*doit(r2, m);
	}
}

main() {
	int n;
	for( cin >> n; n--; ) {
		cin >> K >> M >> L;
		for( int i = 0; i < 31; i++ )
		for( int j = 0; j <= MAXMONEY - MINMONEY; j++ )
			memo[i][j] = -1.0;
		printf( "%.4lf\n", doit(0, 0) );
	}
}
