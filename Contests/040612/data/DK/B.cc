#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void mul(string &s, int n) {
	for( int i = 29, c = 0; i >= 0; i-- ) {
		int x = (s[i]-'0')*n+c;
		s[i] = x%10 + '0';
		c = x/10;
	}
}

void sub(string &s, string &t) {
	for( int i = 29, c = 0; i >= 0; i-- ) {
		int x = (s[i]-'0')-(t[i]-'0') + c;
		s[i] = (x+10)%10 + '0';
		c = (x+10)/10-1;
	}
}

main() {
	string s, zero(30, '0');
	vector<string> p2, p3;
	p2.push_back(zero);
	p2[0][29] = '1';
	p3.push_back(p2[0]);
	for( int i = 0; i < 300; i++ ) {
		p2.push_back(p2.back());
		mul(p2.back(), 2);
		p3.push_back(p3.back());
		mul(p3.back(), 3);
	}
	while( cin >> s ) {
	  if (s == "0") break;
		while( s.size() < 30 ) s = '0'+s;
		vector<string> ret;
		for( int i = 299; i >= 0; i-- )
			if( p2[i] < s ) {
				sub(s, p2[i]);
				ret.push_back(p3[i]);
			}
		reverse(ret.begin(), ret.end());
		cout << "{ ";
		for( int i = 0, j; i < ret.size(); i++ ) {
			if( i ) cout << ", ";
			for( j = 0; ret[i][j] == '0'; j++ );
			cout << ret[i].substr(j);
		}
		cout << " }\n";
	}
}
