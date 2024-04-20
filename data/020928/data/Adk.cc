#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cmath>
typedef vector<int> VI;  typedef vector<vector<int> > VVI;
typedef vector<string> VS;  typedef vector<vector<string> > VVS;
typedef signed long long i64;  typedef unsigned long long u64;

int gcd(int a, int b) {
	int n;
	while( b ) {
		n = b;
		b = a%b;
		a = n;
	}
	return abs(a);
}

char buf[1000000];

void writefraction(int a, int b) {
	int n = gcd(a, b);
	if( b < 0 ) n = -n;
	a /= n; b /= n;
	cout << a;
	if( b != 1 ) cout << '/' << b;
	cout << endl;
}

main() {
	int i, j, k, x1, y1, z1, x2, y2, z2, n;
	int num, den;
	int eq, sgn;
	int prob, first=1;
	char *tok, ch;

	for( scanf( "%d ", &prob ); prob; prob-- ) {
		if( !first ) putchar( '\n' );
		first = 0;
		gets(buf);
		eq = sgn = 1;
		x1 = y1 = z1 = 0;
		for( tok = strtok(buf, " "); tok; tok = strtok(0, " ")) {
			if( strcmp(tok, "=") == 0 ) {eq = -1; sgn = 1; continue;}
			if( *tok == '+' ) if( !*(++tok) ) continue;
			if( *tok == '-' ) {sgn = -sgn; if( !*(++tok) ) continue;}
			if( isalpha(tok[0]) ) n = 1; else n = atoi(tok);
			char ch = tok[strlen(tok)-1];
			if( ch == 'x' ) x1 += n*eq*sgn;
			else if( ch == 'y' ) y1 += n*eq*sgn;
			else z1 += n*eq*sgn;
			sgn = 1;
		}
		gets(buf);
		eq = sgn = 1;
		x2 = y2 = z2 = 0;
		for( tok = strtok(buf, " "); tok; tok = strtok(0, " ")) {
			if( strcmp(tok, "=") == 0 ) {eq = -1; sgn = 1; continue;}
			if( *tok == '+' ) if( !*(++tok) ) continue;
			if( *tok == '-' ) {sgn = -sgn; if( !*(++tok) ) continue;}
			if( isalpha(tok[0]) ) n = 1; else n = atoi(tok);
			ch = tok[strlen(tok)-1];
			if( ch == 'x' ) x2 += n*eq*sgn;
			else if( ch == 'y' ) y2 += n*eq*sgn;
			else z2 += n*eq*sgn;
			sgn = 1;
		}
		gets(buf);
		num = -(z1*y2-z2*y1);
		den =   x1*y2-x2*y1;
		if (den == 0) {
			if( y1 || y2 || !(x1 || x2) || (z2*x1 != z1*x2) )
				cout << "don't know" << endl;
			else
				if( x1 ) writefraction(-z1, x1); else writefraction(-z2, x2);
		} else
			writefraction(num, den);
		num = -(z1*x2-z2*x1);
		den =   y1*x2-y2*x1;
		if (den == 0) {
			if( x1 || x2 || !(y1 || y2) || (z2*y1 != z1*y2) )
				cout << "don't know" << endl;
			else
				if( y1 ) writefraction(-z1, y1); else writefraction(-z2, y2);
		} else
			writefraction(num, den);
	}
}

