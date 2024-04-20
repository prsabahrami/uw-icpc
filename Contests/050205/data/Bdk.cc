#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

main() {
	int i, j, k, x, y, z, n;

	while( cin >> n && n ) {
		vector<int> v(n);
		for( i = 0; i < n; i++ ) cin >> v[i];
		vector<int> sv = v;
		sort(sv.begin(), sv.end());
		for( i = 0; i < n; i++ )
			v[i] = lower_bound(sv.begin(), sv.end(), v[i]) - sv.begin();
		vector<int> bucket2((n+4095)>>12);
		vector<vector<int> > bucket(bucket2.size()<<6);
		long long ret = 0;
		for( i = 0; i < n; i++ ) {
			y = v[i] >> 6;
			for( j = 0; j < bucket[y].size(); j++ )
				ret += (bucket[y][j] > v[i]);
			bucket[y].push_back(v[i]);
			bucket2[y>>6]++;
			for( y++; y & 63; y++ )
				ret += bucket[y].size();
			for( y >>= 6; y < bucket2.size(); y++ )
				ret += bucket2[y];
		}
		cout << ret << endl;
	}
}
