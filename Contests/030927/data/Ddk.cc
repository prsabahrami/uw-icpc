#include <iostream>
#include <cstring>
using namespace std;

int seen[101][10002], cookie = 0;
int rc[101][101], re[101], ru[101], nr;

int doit(int r, int e) {
	if( ru[r] ) {
		if( ru[r] >= e ) return 0;
		e = 10001;
	}
	e <?= 10001;
	if( e <= 0 || seen[r][e] == cookie ) return 0;
	seen[r][e] = cookie;
	if( r == nr ) return 1;
	int oru = ru[r];
	ru[r] = e;
	for( int i = 1; i <= nr; i++ ) if( rc[r][i] )
		if( doit(i, e+re[i]) ) return 1;
	ru[r] = oru;
	return 0;
}

main() {
	int i, j, n, r;

	while( cin >> nr && nr != -1 ) {
		memset(rc, 0, sizeof(rc));
		memset(ru, 0, sizeof(ru));
		for( i = 1; i <= nr; i++ ) {
			cin >> re[i] >> n;
			for( j = 0; j < n; j++ ) {
				cin >> r;
				rc[i][r] = 1;
			}
		}
		cookie++;
		cout << (doit(1, 100) ? "winnable\n" : "hopeless\n");
	}
}

