#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cmath>
typedef vector<int> VI;  typedef vector<vector<int> > VVI;
typedef vector<string> VS;  typedef vector<vector<string> > VVS;
typedef signed long long i64;  typedef unsigned long long u64;

main() {
	int i, j, k, x, y, z, n;
	int prob;

	for( scanf( " %d", &prob ); prob; prob-- ) {
		scanf( " %d", &n );
		int best = 1000000000;
		for( x = 1; x <= n; x++ ) if( n%x == 0 )
		for( y = 1; y <= n/x; y++ ) if( (n/x)%y == 0 )
		for( z = 1; z <= n/x/y; z++ ) if( n == x*y*z )
			best <?= 2*(x*y + y*z + z*x);
		printf( "%d\n", best );
	}
}

