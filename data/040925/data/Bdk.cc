#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
typedef vector<string> VS;  typedef vector<vector<string> > VVS;

main() {
	int i, j;
	string A, B, s;

	getline(cin, A);
	while( getline(cin, A) && getline(cin, B) ) {
		VS a, b;
		istringstream as(A), bs(B);
		while( as >> s ) a.push_back(s);
		while( bs >> s ) b.push_back(s);
		if( a.size() != b.size() ) goto fail;
		bool change;
		do {
			change = false;
			for( i = 0; i < a.size(); i++ )
			if( (a[i][0] == '<') ^ (b[i][0] == '<') ) {
				if( b[i][0] == '<' ) swap(a, b);
				s = a[i];
				for( j = 0; j < a.size(); j++ )
					if( a[j] == s && b[j][0] != '<' && b[j] != b[i] ) goto fail;
				for( j = 0; j < a.size(); j++ ) if( a[j] == s ) {
					if( b[j][0] != '<' && b[j] != b[i] ) goto fail;
					a[j] = b[i];
				}
				change = true;
			}
		} while( change );
		for( i = 0; i < a.size(); i++ ) if( a[i][0] == '<' ) a[i] = "darn";
		for( i = 0; i < a.size(); i++ ) {
			if( i ) cout << ' ';
			cout << a[i];
		}
		cout << '\n';
		continue;
fail:	cout << "-\n";
	}
}
