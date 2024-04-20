#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
using namespace std;
typedef vector<int> VI;  typedef vector<vector<int> > VVI;
typedef vector<string> VS;  typedef vector<vector<string> > VVS;
typedef signed long long i64;  typedef unsigned long long u64;

int dx[5] = {-1, 1, 0, 0, 0};
int dy[5] = {0, 0, -1, 1, 0};
string ds = "WENS.";

int best[32][32][32][32];
int prev[32][32][32][32];
char g[32][32];

inline int enc(int ax, int ay, int bx, int by) {
	return (ax<<24)+(ay<<16)+(bx<<8)+by;
}

inline int dec(int &ax, int &ay, int &bx, int &by, int c) {
	ax = (c>>24); ay = ((c>>16)&255); bx = ((c>>8)&255); by = (c&255);
}

main() {
	int i, j, k, x, y, z, n, first=1;
	int ax, ay, bx, by, ad, bd, nax, nay, nbx, nby, nz;

	while( cin >> n && n ) {
		memset(g, '*', sizeof(g));
		memset(best, -1, sizeof(best));
		for( y = 1; y <= n; y++ )
		for( x = 1; x <= n; x++ ) {
			cin >> g[y][x];
			if( g[y][x] == 'H' ) {ax = x; ay = y;}
			if( g[y][x] == 'h' ) {bx = x; by = y;}
		}
		priority_queue<pair<int, int> > q;
		z = (ax-bx)*(ax-bx) + (ay-by)*(ay-by);
		best[ax][ay][bx][by] = z;
		prev[ax][ay][bx][by] = -1;
		q.push(make_pair(z, enc(ax, ay, bx, by)));
		while( !q.empty() ) {
			dec(ax, ay, bx, by, q.top().second); z = q.top().first; q.pop();
			if( best[ax][ay][bx][by] > z ) continue;
			if( g[ay][ax] == 'S' && g[by][bx] == 's' ) break;
			for( ad = 0; ad < 5; ad++ ) if( (ad<4)^(g[ay][ax]=='S') )
			for( bd = 0; bd < 5; bd++ ) if( (bd<4)^(g[by][bx]=='s') ) {
				nax = ax+dx[ad]; nay = ay+dy[ad];
				nbx = bx+dx[bd]; nby = by+dy[bd];
				if( g[nay][nax] == '*' || g[nby][nbx] == '*' ||
					g[nay][nax] == 'h' || g[nby][nbx] == 'H' ||
					g[nay][nax] == 's' || g[nby][nbx] == 'S' ) continue;
				nz = z <? (nax-nbx)*(nax-nbx)+(nay-nby)*(nay-nby);
				if( nz <= best[nax][nay][nbx][nby] ) continue;
				best[nax][nay][nbx][nby] = nz;
				prev[nax][nay][nbx][nby] = (ad<<8)+bd;
				q.push(make_pair(nz, enc(nax, nay, nbx, nby)));
			}
		}
		if( !first ) cout << '\n';
		first = 0;
		printf( "%.2lf\n", sqrt((double)best[ax][ay][bx][by]) );
		string as, bs;
		while( prev[ax][ay][bx][by] != -1 ) {
			ad = (prev[ax][ay][bx][by]>>8);
			bd = (prev[ax][ay][bx][by]&255);
			if( ds[ad] != '.' ) as += ds[ad];
			if( ds[bd] != '.' ) bs += ds[bd];
			ax -= dx[ad]; ay -= dy[ad];
			bx -= dx[bd]; by -= dy[bd];
		}
		reverse(as.begin(), as.end());
		reverse(bs.begin(), bs.end());
		cout << as << '\n' << bs << '\n';
	}
}

