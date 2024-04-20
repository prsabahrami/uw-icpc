#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef vector<int> VI;  typedef vector<vector<int> > VVI;
typedef vector<string> VS;  typedef vector<vector<string> > VVS;
typedef signed long long i64;  typedef unsigned long long u64;

string action = "LR.";
string pos = "ULDR";
enum {UP, LEFT, DOWN, RIGHT};

bool allow(int ol, int Or, int nl, int nr) {
	if( nl != ol && nr != Or ) return false;
	if( nl == nr || nl == RIGHT && nr == LEFT ) return false;
	if( nl == RIGHT && nr != Or ) return false;
	if( nr == LEFT && nl != ol ) return false;
	return true;
}

string seq;

int memo[100][4][4][3];
int doit(int p, int l, int r, char last, int disp) {
	if( p == seq.size() ) return 0;
	int &ret = memo[p][l][r][action.find(last)];
	if( !disp && ret != -1 ) return ret;
	ret = 1<<30;
	int bestnl = -1, bestnr = -1, cost;
	if( seq[p] == '.' ) ret = doit(p+1, l, r, '.', 0);
	for( int nl = 0; nl < 4; nl++ ) if( allow(l, r, nl, r) ) {
		if( seq[p] != '.' && pos[nl] != seq[p] ) continue;
		cost = (last!='L')?1: (l==nl)?3: (l==(nl^2))?7: 5;
		cost += doit(p+1, nl, r, 'L', 0);
		if( cost < ret ) {ret = cost; bestnl = nl; bestnr = -1;}
	}
	for( int nr = 0; nr < 4; nr++ ) if( allow(l, r, l, nr) ) {
		if( seq[p] != '.' && pos[nr] != seq[p] ) continue;
		cost = (last!='R')?1: (r==nr)?3: (r==(nr^2))?7: 5;
		cost += doit(p+1, l, nr, 'R', 0);
		if( cost < ret ) {ret = cost; bestnl = -1; bestnr = nr;}
	}
	if( disp ) {
		char act = (bestnl!=-1)?'L': (bestnr!=-1)?'R': '.';
		cout << act;
		doit(p+1, (bestnl==-1)?l:bestnl, (bestnr==-1)?r:bestnr, act, 1);
	}
	return ret;
}

main() {
	for(;;) {
		cin >> seq;
		if( seq == "#" ) break;
		memset(memo, -1, sizeof(memo));
		int r = doit(0, LEFT, RIGHT, '.', 1);
                //cout << " " << r;
		cout << '\n';
	}
}

