#include <iostream>
#include <cstdio>

using namespace std;

int n;
double d[1001], Pl, Pr;

main() {
	while( cin >> n >> Pl >> Pr && n) {
		d[0] = 0.0;
		for( int i = 1; i <= n; i++ ) {
			d[i] = 1e50;
			for( int j = 0; j < i; j++ )
				d[i] <?= d[j] + d[i-j-1] + 1 +	// do left, right, then middle
						(1/(1-Pl-Pr) - 1) *		// E(knocking down middle)
						((Pl*d[j] + Pr*d[i-j-1])/(Pl+Pr) + 1);
												// cost of knocking down middle
		}
		printf( "%.2lf\n", d[n] );
	}
}
