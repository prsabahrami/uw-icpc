#include <iostream>
#include <string>
using namespace std;

main() {
	int x = (1<<10)-1, n;
	string s;

	for(;;) {
		cin >> n;
		if( !n ) break;
		cin >> s >> s;
		if( s == "high" ) x &= (1<<(n-1))-1;
		else if( s == "low" ) x &= (1<<10)-(1<<n);
		else if( s == "on" ) {
			if( x & (1<<(n-1)) )
				cout << "Stan may be honest\n";
			else
				cout << "Stan is dishonest\n";
			x = (1<<10)-1;
		}
	}
}
