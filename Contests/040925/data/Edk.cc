#include <iostream>
using namespace std;

int u[26];
int p[26][26];
char ch[6];

main() {
	int i, j, k, x, y, z, n;
	bool first = true;

	while( cin >> n && n ) {
		if( !first ) cout << '\n'; first = false;
		memset(p, 0, sizeof(p));
		for( i = 0; i < n; i++ ) {
			for( j = 0; j < 6; j++ ) cin >> ch[j];
			for( j = 0; j < 5; j++ ) u[ch[j]-'A'] = 1;
			for( j = 0; j < 5; j++ ) p[ch[5]-'A'][ch[j]-'A'] = 1;
		}
		for( k = 0; k < 26; k++ )
		for( i = 0; i < 26; i++ )
		for( j = 0; j < 26; j++ )
			p[i][j] |= p[i][k] & p[k][j];
		for( i = 0; i < 26; i++ ) if( u[i] ) {
			u[i] = 0;
			cout << (char)('A'+i);
			for( j = i+1; j < 26; j++ ) if( p[i][j] && p[j][i] ) {
				u[j] = 0;
				cout << ' ' << (char)('A'+j);
			}
			cout << '\n';
		}
	}
}
