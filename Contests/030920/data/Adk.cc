#include <iostream>
#include <algorithm>
using namespace std;

struct Doll {
	int h, d, w;
	bool fitsin( const Doll &D ) const {
		return h <= D.h-D.w-D.w && d <= D.d-D.w-D.w;
	}
};

Doll d[200];
int n;

// prev[size of seq 1][size of seq 2][1 + last doll in seq 1]
unsigned char prev[201][201][201];
int seq[200];

main() {
	int i, j, k, x, y, z, seqn, first=1;

	while( cin >> n && n ) {
		z = n; n *= 2;
		for( i = 0; i < n; i++ ) cin >> d[i].h >> d[i].d >> d[i].w;
		memset(prev, 0, sizeof(prev));
		prev[0][0][0] = 255;
		for( i = 0; i < n; i++ ) {
			for( j = i+1; j < n; j++ )
				if( d[i].fitsin(d[j]) ) swap(d[i], d[j]);
			for( j = 0; j < i; j++ ) if( !j || d[i].fitsin(d[j-1]) )
				for( k = 0; k <= i && k < z; k++ )
					if( prev[k][i-k][j] )
						prev[i-k][k+1][i] = j+1;
			if( !i || d[i].fitsin(d[i-1]) )
				for( j = 0; j <= i; j++ )
					for( k = 0; k <= i && k < z; k++ )
						if( prev[i-k][k][j] )
							prev[i-k][k+1][j] = 255;
		}
		for( i = 0; i < n; i++ ) if( prev[z][z][i] ) break;
		for( x = y = z, seqn = 1; x || y; ) {
			seq[x+y-1] = seqn;
			if( prev[x][y][i] == 255 ) {
				y--;
			} else {
				i = prev[x][y][i]-1;
				y--;
				swap(x, y);
				seqn ^= 1;
			}
		}
		if( !first ) cout << '\n';
		first = 0;
		for( i = 0; i < n; i++ ) if( seq[i] == 0 )
			cout << d[i].h << ' ' << d[i].d << ' ' << d[i].w << '\n';
		cout << "-\n";
		for( i = 0; i < n; i++ ) if( seq[i] == 1 )
			cout << d[i].h << ' ' << d[i].d << ' ' << d[i].w << '\n';
	}
}

