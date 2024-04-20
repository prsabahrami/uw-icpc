#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef vector<int> VI;  typedef vector<vector<int> > VVI;

#define MAXLEN 500000

inline int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}

main() {
	int i, j, k, c, w, x, y, z, n, t;
	bool first = true;

	while( cin >> n >> t && n+t ) {
		if( !first ) cout << '\n'; first = false;
		set<int> poss[5];
		set<int>::iterator it;
		poss[0].insert(1);
		for( i = 0; i < n; i++ ) {
			cin >> x;
			for( j = 3; j >= 0; j-- )
			for( it = poss[j].begin(); it != poss[j].end(); it++ )
				poss[j+1].insert(*it * x / gcd(*it, x));
		}
		VI v(poss[4].begin(), poss[4].end());
		while( t-- ) {
			cin >> z;
			x = 0; y = 1000000000;
			for( i = 0; i < v.size(); i++ ) {
				x >?= z-z%v[i];
				y <?= z+(v[i] - z%v[i])%v[i];
			}
			cout << x << ' ' << y << '\n';
		}
	}
}
