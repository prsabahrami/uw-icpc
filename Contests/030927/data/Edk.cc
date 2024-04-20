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

char c[100][100];
int sb[101];
int nn[101][101], u[101];
int best[101][101];

void outp(int a, int n) {
	if( a == 1 ) return;
	int i;
	for( i = 1; i < a; i++ )
		if( best[a][n] == best[i][n-1] + nn[i][a] ) break;
	outp(i, n-1);
	cout << ' ' << a;
}

main() {
	int i, j, k, x, y, z, n, nab;

	while( cin >> n && n != -1 ) {
		memset(c, 0, sizeof(c));
		for( i = 0; i < n; i++ ) {
			cin >> x >> y;
			c[x][y] = 1;
		}
		cin >> n;
		memset(sb, 0, sizeof(sb));
		for( i = 0; i < n; i++ ) {
			cin >> x;
			sb[x] = 1;
		}
		cin >> nab;
		memset(nn, 0, sizeof(nn));
		for( i = 1; i < 100; i++ ) {
			memset(u, 0, sizeof(u));
			for( j = i+1; j <= 100; j++ ) {
				nn[i][j] = nn[i][j-1];
				for( x = 1; x < 100; x++ ) {
					if( sb[x] ) z = x;
					if( !u[z] && c[x][j-1] ) nn[i][j] += u[z] = 1;
				}
			}
		}
		memset(best, -50, sizeof(best));
		best[1][1] = 0;
		for( i = 1; i < 100; i++ )
		for( j = i+1; j <= 100; j++ )
		for( n = 1; n < nab; n++ )
			best[j][n+1] >?= best[i][n] + nn[i][j];
		cout << nab << " 1";
		outp(100, nab);
		cout << '\n';
	}
}

