#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> VI;  typedef vector<vector<int> > VVI;

main() {
	int i, j, k, x, y, z, n;
	char ch;
	
	while( cin >> n && n ) {
		cin >> ch;
		VI p(n);
		for( i = 0; i < n; i++ ) {
			cin >> x;
			p[x] = i;
		}
		for( i = 1; i < n; i++ )
			for( j = 0; j+i+i < n; j++ )
				if( (p[j] < p[j+i]) ^ (p[j+i] > p[j+i+i]) ) goto fail;
		cout << "yes\n"; continue;
fail:	cout << "no\n";
	}
}
