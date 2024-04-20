#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string scale[] =
	{"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

main() {
	int i, j, k, x, y, z, n;
	string s, note;

	for(;;) {
		getline(cin, s);
		if( s == "END" ) break;
		stringstream ss(s);
		vector<int> u(12);
		while( ss >> note ) {
			u[find(scale, scale+12, note)-scale] = 1;
		}
		int first = 1;
		for( i = 0; i < 12; i++ ) {
			if( u[(i+1)%12] || u[(i+3)%12] || u[(i+6)%12] ||
				u[(i+8)%12] || u[(i+10)%12] ) continue;
			if( !first ) cout << ' ';
			first = 0;
			cout << scale[i];
		}
		cout << '\n';
	}
}
