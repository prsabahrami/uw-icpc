#include <iostream>
using namespace std;

main() {
	int i, x, ln, n, N;

	for( cin >> N; N--; ) {
		cin >> ln >> n;
		int mn = 0, mx = 0;
		for( i = 0; i < n; i++ ) {
			cin >> x;
			mn >?= x <? ln-x;
			mx >?= x >? ln-x;
		}
		cout << mn << ' ' << mx << '\n';
	}
}
