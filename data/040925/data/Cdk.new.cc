#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef vector<int> VI;  typedef vector<vector<int> > VVI;
typedef vector<string> VS;  typedef vector<vector<string> > VVS;

int parse(string s, VS &tn, VVI &tc) {
	int p, q, b, n = tc.size();
	for( p = 1; p < s.size() && s[p] != '('; p++ );
	tn.push_back(s.substr(0, p));
	tc.push_back(VI());
	while( p < s.size() && s[p] != ')' ) {
		for( q = ++p, b = 0; b || s[q] != ',' && s[q] != ')'; q++ )
			b += (s[q] == '(') - (s[q] == ')');
		if( q != p ) {
			int z = parse(s.substr(p, q-p), tn, tc);
			tc[n].push_back(z);
			tc[tc[n].back()].push_back(n);
		}
		p = q;
	}
	return n;
}

VS an, bn;
VVI ac, bc;

bool traverse(int x, int xf, int y, int yf) {
	if( an[x] != bn[y] || ac[x].size() != bc[y].size() ) return false;
	int i, j, k;
	for( i = 0; i < ac[x].size(); i++ ) if( ac[x][i] == xf ) break;
	for( j = 0; j < bc[y].size(); j++ ) if( bc[y][j] == yf ) break;
	for( k = 0; k < ac[x].size()-1; k++ ) {
		i = (i+1)%ac[x].size();
		j = (j+1)%bc[y].size();
		if( !traverse(ac[x][i], x, bc[y][j], y) ) return false;
	}
	return true;
}

main() {
	int N, x, y;
	for( cin >> N; N--; ) {
		an.clear(); bn.clear();
		ac.clear(); bc.clear();
		string s;
		cin >> s;
		parse(s, an, ac);
		cin >> s;
		parse(s, bn, bc);
		if( an.size() != bn.size() ) goto fail;
		if( an.size() == 1 && an[0] == bn[0] ) goto pass;
		if( an.size() == 1 ) goto fail;
		for( x = 0; x < an.size(); x++ ) if( ac[x].size() == 1 ) break;
		for( y = 0; y < bn.size(); y++ )
			if( bc[y].size() == 1 && bn[y] == an[x] )
				if( traverse(ac[x][0], x, bc[y][0], y) )
					goto pass;
fail:	cout << "different\n"; continue;
pass:	cout << "same\n";
	}
}
