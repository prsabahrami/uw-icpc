#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <set>
typedef vector<int> VI;  typedef vector<vector<int> > VVI;
typedef vector<string> VS;  typedef vector<vector<string> > VVS;
typedef signed long long i64;  typedef unsigned long long u64;

int ns;
VI s;
set<int> sides;
set<int> half;

void doit(int b, int p, int x, int mn) {
	if( x == 0 ) sides.insert(b);
	if( x <= 0 || p == ns ) return;
	if( p > 0 && s[p] == s[p-1] && (b&(1<<(p-1))) )
		doit(b, p+1, x, s[p]+1);
	else
		doit(b, p+1, x, mn);
	if( s[p] >= mn ) doit(b+(1<<p), p+1, x-s[p], mn);
}

main() {
	int i, j, k, x, y, z, n;
	set<int>::iterator it, it2;

	for( cin >> n; n; n-- ) {
		cin >> ns;
		s = VI(ns);
		for( i = 0; i < ns; i++ ) cin >> s[i];
		sort(s.begin(), s.end());
		x = 0;
		for( i = 0; i < ns; i++ ) x += s[i];
		if( x%4 ) {cout << "no" << endl; continue;}
		x /= 4;
		half = sides = set<int>();
		doit(0, 0, x, 0);
		for( it = sides.begin(); it != sides.end(); ++it ) {
			it2 = it;
			for( ++it2; it2 != sides.end(); ++it2 )
				if( !(*it & *it2) )
					half.insert(*it | *it2);
		}
		y = (1<<ns)-1;
		for( it = half.begin(); it != half.end(); ++it ) {
			if( half.count(*it^y) ) break;
		}
		cout << ((it==half.end())?"no":"yes") << endl;
	}
}

