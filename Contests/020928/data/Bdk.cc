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

int iswin(int x, int y) {
	if( x > y ) swap(x, y);
	if( y%x == 0 ) return 1;
	if( y-x < x ) return 1-iswin( y-x, x );
	return 1;
}

main() {
	int i, j, k, x, y, z, n;

	for(;;) {
		scanf( " %d %d", &x, &y );
		if( x+y == 0 ) break;
		cout << (iswin(x, y) ? "Stan wins" : "Ollie wins") << endl;
	}
}

