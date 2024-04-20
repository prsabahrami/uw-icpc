#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
using namespace std;

#define CORRECT 0
#define PRESENTATION 1
#define WRONG 2

string action = "LR.";
string pos = "ULDR";
enum {UP, LEFT, DOWN, RIGHT};
bool allowed(int ol, int OR, int nl, int nr) {	// allowable new foot position?
	if( nl != ol && nr != OR ) return false;
	if( nl == nr || nl == RIGHT && nr == LEFT ) return false;
	if( nl == RIGHT && nr != OR ) return false;
	if( nr == LEFT && nl != ol ) return false;
	return true;
}

string seq;

int memo[100][4][4][3];
int doit(int p, int l, int r, char last) {
	if( p == seq.size() ) return 0;
	int &ret = memo[p][l][r][action.find(last)];
	if( ret != -1 ) return ret;
	ret = 1<<30;
	int bestnl = -1, bestnr = -1, cost;
	if( seq[p] == '.' ) ret = doit(p+1, l, r, '.');
	for( int nl = 0; nl < 4; nl++ ) if( allowed(l, r, nl, r) ) {
		if( seq[p] != '.' && pos[nl] != seq[p] ) continue;
		cost = (last!='L')?1: (l==nl)?3: (l==(nl^2))?7: 5;
		cost += doit(p+1, nl, r, 'L');
		if( cost < ret ) {ret = cost; bestnl = nl; bestnr = -1;}
	}
	for( int nr = 0; nr < 4; nr++ ) if( allowed(l, r, l, nr) ) {
		if( seq[p] != '.' && pos[nr] != seq[p] ) continue;
		cost = (last!='R')?1: (r==nr)?3: (r==(nr^2))?7: 5;
		cost += doit(p+1, l, nr, 'R');
		if( cost < ret ) {ret = cost; bestnl = -1; bestnr = nr;}
	}
	return ret;
}

int c[4][4], c2[4][4];
string ans;

int retval(int argc, char *argv[])
{
	if( argc < 3 ) return -1;
	ifstream inp(argv[1]);
	if( !inp.is_open() ) return -1;

	int nseq = 0;
	while( inp >> seq && seq != "#" ) {
		assert( seq.size() && seq.size() <= 70 );
		//assert( ++nseq <= 100 );
		memset(memo, -1, sizeof(memo));
		int cost = doit(0, LEFT, RIGHT, '.');
		cin >> ans;
		if( ans.size() != seq.size() ) return WRONG;
		memset(c, 100, sizeof(c));
		c[LEFT][RIGHT] = 0;
		for( int i = 0; i < ans.size(); i++ ) {
			if( ans[i] == '.' ) {
				if( seq[i] != '.' ) return WRONG;
				continue;
			}
			memset(c2, 100, sizeof(c2));
			for( int l = 0; l < 4; l++ )
			for( int r = 0; r < 4; r++ ) if( c[l][r] < 1000000 ) {
				for( int d = 0; d < 4; d++ )
					if( seq[i] == '.' || seq[i] == pos[d] ) {
						int nl = l, nr = r, nc = c[l][r];
						((ans[i] == 'L') ? nl : nr) = d;
						if( !allowed(l, r, nl, nr) ) continue;
						if( i == 0 || ans[i-1] != ans[i] )
							nc++;
						else
							nc += (ans[i]=='L') ?
								((l==nl) ? 3 : (l==(nl^2)) ? 7 : 5) :
								((r==nr) ? 3 : (r==(nr^2)) ? 7 : 5);
						c2[nl][nr] <?= nc;
					}
			}
			memcpy(c, c2, sizeof(c));
		}

		int best = 1000000;
		for( int l = 0; l < 4; l++ )
		for( int r = 0; r < 4; r++ ) {
			assert( c[l][r] >= cost );
			best <?= c[l][r];
		}
		if( best != cost ) return WRONG;
	}
	return CORRECT;
}

int main(int argc, char *argv[]) {
	int ret = retval(argc, argv);
	return ret;
}
