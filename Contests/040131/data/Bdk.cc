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
typedef pair<int, int> PII;

bool dcmp(const PII &a, const PII &b) {
	return a.first+a.second < b.first+b.second;
}

main() {
	int i, j, k, x, y, z, n, m, N, prob=1;
	int hi, lo, t;

	for( cin >> N; N--; ) {
		cin >> n >> m;
		vector<PII> v(n);
		for( i = 0; i < n; i++ ) cin >> v[i].first >> v[i].second;
		sort(v.begin(), v.end(), dcmp);
		hi = 1000000, lo = -2000000;
		for( i = 0; i < n; i++ ) hi <?= v[i].first;
		while( hi != lo ) {
			t = (hi+lo+1)/2;
			z = 0; x = -1000000000;
			for( i = 0; i < n; i++ ) if( v[i].second-v[i].first > x ) {
				z++;
				x = v[i].first+v[i].second - 2*t;
			}
			if( z <= m ) lo = t; else hi = t-1;
		}
		cout << "Case " << prob++ << ": " << hi << '\n';
	}
}

