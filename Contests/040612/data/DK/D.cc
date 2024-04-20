#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

double EPS = 1e-8;

int xsp[10], ysp[10];
map<int, double> best[10][10];
map<int, double>::iterator it, it2;

main() {
	int i, j, k, t, v, x, y, z, n, N, prob=1;
	int x1, y1, x2, y2, t1, t2, gs;
	double g;

	for( cin >> N; N--; ) {
		cin >> n >> gs;
		for( i = 0; i < n; i++ ) cin >> xsp[i];
		for( i = 0; i < n; i++ ) cin >> ysp[i];
		cin >> x1 >> y1 >> x2 >> y2 >> t1 >> t2;
		x1--; y1--; x2--; y2--;
		t1 *= 210; t2 *= 210;
		if( x1 > x2 ) {swap(x1, x2); reverse(ysp, ysp+n);}
		if( y1 > y2 ) {swap(y1, y2); reverse(xsp, xsp+n);}
		for( x = x1; x <= x2; x++ )
		for( y = y1; y <= y2; y++ )
			best[x][y].clear();
		best[x1][y1][0] = -1000.0;
		for( x = x1; x <= x2; x++ )
		for( y = y1; y <= y2; y++ )
		for( it = best[x][y].begin(); it != best[x][y].end(); it++ ) {
			if( x < x2 ) {
				for( v = 5; v <= xsp[y]; v += 5 ) {
					t = it->first + 12600*gs/v;
					g = it->second + gs/(80-0.03*v*v);
					if( t <= t2 ) best[x+1][y][t] <?= g;
				}
			}
			if( y < y2 ) {
				for( v = 5; v <= ysp[x]; v += 5 ) {
					t = it->first + 12600*gs/v;
					g = it->second + gs/(80-0.03*v*v);
					if( t <= t2 ) best[x][y+1][t] <?= g;
				}
			}
		}
		printf( "Scenario %d:\n", prob++ );
		for( it = best[x2][y2].begin(); it != best[x2][y2].end(); it++ )
			if( it->first >= t1 ) break;
		if( it == best[x2][y2].end() ) {
			printf( "IMPOSSIBLE\n" );
			continue;
		}
		printf( "The earliest  arrival:" );
		printf( " %d minutes, fuel %.2lf gallons\n",
				(it->first+209)/210, it->second+1000.0 );
		for( it2 = it; it != best[x2][y2].end(); it++ )
			if( it->second < it2->second-EPS ) it2 = it;
		printf( "The economical travel:" );
		printf( " %d minutes, fuel %.2lf gallons\n",
				(it2->first+209)/210, it2->second+1000.0 );
	}
}
