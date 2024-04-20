#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

char buf[1000];

main() {
	int i, j, k, a, b, x, m, n, na, N, prob=1;

	for( scanf( " %d", &N ); N--; ) {
		scanf( " %d %d %d", &n, &m, &na );
		vector<int> nleft;
		for( i = 0; i < 20; i++ ) {
			nleft.push_back(n >= m ? n-m : 100000);
			n /= 2;
		}
		vector<pair<int, string> > ret;
		for( i = 0; i < na; i++ ) {
			scanf( " %[^:]:%d,%d", buf, &a, &b );
			x = 1000000000;
			for( j = 0; j < nleft.size(); j++ )
				x <?= b*j + a*nleft[j];
			ret.push_back(make_pair(x, string(buf)));
		}
		sort(ret.begin(), ret.end());
		cout << "Case " << prob++ << '\n';
		for( i = 0; i < ret.size(); i++ )
			cout << ret[i].second << ' ' << ret[i].first << '\n';
	}
}
