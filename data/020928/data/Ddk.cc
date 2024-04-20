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
	int i, j, k, x, y, z, n, N;

	for( cin >> N; N; N-- ) {
		cin >> n;
		VI s(n);
		x = 0;
		for( i = 0; i < n; i++ ) {
			cin >> s[i];
			x += s[i];
		}
		y = 0;
		for( i = 0; i < n; i++ )
			if( s[i]*n > x )
				y++;
		printf( "%.3lf%%\n", y*100.0/(double)n );
	}
}

