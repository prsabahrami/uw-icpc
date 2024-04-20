#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef vector<int> VI;  typedef vector<vector<int> > VVI;
typedef vector<string> VS;  typedef vector<vector<string> > VVS;
typedef signed long long i64;  typedef unsigned long long u64;

main() {
	int i, j, k, x, y, z, n, S, dx, dy;

	while( cin >> S >> x >> y >> dx >> dy && S+x+y+dx+dy ) {
		for( n = 0; n <= 1000000; n++ ) {
			if( x%(2*S) > S && (y+S)%(2*S) > S ) break;
			if( (x+S)%(2*S) > S && y%(2*S) > S ) break;
			x += dx;
			y += dy;
		}
		if( n <= 1000000 ) {
			cout << "After " << n << " jumps the flea lands at ";
			cout << '(' << x << ", " << y << ").\n";
		} else
			cout << "The flea cannot escape from black squares.\n";
	}
}

