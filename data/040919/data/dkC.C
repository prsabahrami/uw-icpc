#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

#define GRAN 10000

main() {
	int i, j, x, n;

	while( cin >> n && n ) {
		vector<double> w(n);
		for( i = 0; i < n; i++ ) cin >> w[i];
		double g = accumulate(w.begin(), w.end(), 0.0)/2.0;
		vector<double> dyn(GRAN+1, -1.0);
		vector<vector<bool> > dynb(GRAN+1);
		dyn[0] = 0.0; dynb[0] = vector<bool>(n);
		for( i = 0; i < n; i++ ) {
			for( j = GRAN; j >= 0; j-- ) if( dyn[j] != -1.0 ) {
				int x = (int)((dyn[j] + w[i])/g*GRAN + 1e-9);
				if( x > GRAN ) continue;
				if( dyn[x] != -1.0 ) continue;
				dyn[x] = dyn[j] + w[i];
				dynb[x] = dynb[j]; dynb[x][i] = true;
			}
		}
		for( x = GRAN; dyn[x] == -1.0; x-- );
		bool first = true;
		for( i = 0; i < n; i++ ) if( dynb[x][i] ) {
			if( !first ) cout << ' '; first = false;
			cout << i+1;
		}
		cout << '\n';
	}
}
