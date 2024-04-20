#include <iostream>
#include <cstdio>
using namespace std;

int gtoc[5] = {9, 4, 4, 4, 7};

main() {
	int i;
	double tot, tfat, x, fx, p, c;
	char ch, fch;

	for(;;) {
		tot = tfat = 0;
		for(;;) {
			p = 100; c = 0;
			for( i = 0; i < 5; i++ ) {
				if( scanf( " %lf %c", &x, &ch ) != 2 ) break;
				if( ch == 'g' ) c += gtoc[i]*x;
				if( ch == 'C' ) c += x;
				if( ch == '%' ) p -= x;
				if( i == 0 ) {fx = x; fch = ch;}
			}
			if( !i ) break;
			tot += c*100/p;
			if( fch == 'g' ) tfat += gtoc[0]*fx;
			if( fch == 'C' ) tfat += fx;
			if( fch == '%' ) tfat += c*fx/p;
		}
		if( tot == 0 ) break;
		cout << (int)(tfat*100/tot + 0.50000001) << "%\n";
	}
}

