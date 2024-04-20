#include <iostream>
using namespace std;

main() {
	int s, d, n;

	for( cin >> n; n--; ) {
		cin >> s >> d;
		if( s-d < 0 || (s+d)%2 || (s-d)%2 ) {cout << "impossible\n"; continue;}
		cout << (s+d)/2 << ' ' << (s-d)/2 << endl;
	}
}
