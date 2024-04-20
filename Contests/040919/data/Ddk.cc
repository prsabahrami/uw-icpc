#include <iostream>
#include <map>
using namespace std;

map<string, int> memo;
int doit(string s) {
	int x;
	for( x = 0; s[x] == s[s.size()-1-x] && x+x < s.size(); x++);
	if( x ) s = s.substr(x, s.size()-x-x);
	if( s.size() <= 1 ) return 0;
	int &ret = memo[s], n = s.size();
	if( ret ) return ret;
	ret = 1000000;
	for( x = 0; x < n-1; x++ ) if( s[x] == s[n-1] ) break;
	if( x < n-1 ) 
		ret <?= x + doit(s.substr(0, x) + s.substr(x+1, n-1-x-1));
	if( !x ) return ret;
	for( x = n-1; x > 0; x-- ) if( s[x] == s[0] ) break;
	if( x > 0 )
		ret <?= n-1-x + doit(s.substr(1, x-1) + s.substr(x+1, n-x-1));
	return ret;
}

main() {
	int i, j, k, x, y, z, n;
	string s;
	getline(cin, s);
	sscanf( s.c_str(), "%d", &n );
	while( n-- ) {
		memo.clear();
		getline(cin, s);
		x = doit(s);
		if( x == 1000000 ) cout << "Impossible\n"; else cout << x << '\n';
	}
}
