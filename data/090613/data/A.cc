#include <cstring>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>
using namespace std;

#define FR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,n) FR(i,0,n)
#define FORI(i,v) FOR(i,(int)(v).size())
#define FORALL(i,v) for(typeof((v).end())i=(v).begin();i!=(v).end();++i)
#define CLR(x,a) memset(x,a,sizeof(x))
#define BEND(v) (v).begin(),(v).end()
#define SZ(v) (int)(v).size()
#define MP make_pair
#define PB push_back
#define A first
#define B second
#define dump(x) cerr << #x << " = " << (x) << endl
typedef long long ll; typedef long double ld;

int n,m;
char grid[2000][2000];
int nmark[2],prev;
bool full;
int nlines[2];
int nkey[2][3000][3000];
int dr[] = { 1, 1, 0, -1 },
    dc[] = { 0, 1, 1, 1 };
char get(int r, int c) {
  if (r<0 || r>=n || c<0 || c>=n) return '.';
  return grid[r][c];
}
void detect(int p, char ch) {
  FOR(k,4) {
    FOR(r,n) FOR(c,n) {
      if (get(r-dr[k],c-dc[k]) != ch) {
	int len=0;
	while (get(r+len*dr[k],c+len*dc[k]) == ch) ++len;

	if (len >= m) {
	  ++nlines[p];

	  FOR(i,len) if (i<m && m+i >= len) {
	    ++nkey[p][r+i*dr[k]][c+i*dc[k]];
	  }
	}
      }
    }
  }
}
int main() {
  scanf("%d%d",&n,&m);

  FOR(i,n) FOR(j,n) scanf(" %c",&grid[i][j]);

  CLR(nmark,0);
  full = 1;

  FOR(i,n) FOR(j,n) {
    if (grid[i][j] == 'X') ++nmark[0];
    else if (grid[i][j] == 'O') ++nmark[1];
    else full = 0;
  }

  if (nmark[0] == nmark[1]) prev = 1;
  else if (nmark[0] == nmark[1]+1) prev = 0;
  else {
    printf("ERROR\n");
    return 0;
  }

  CLR(nlines,0);
  CLR(nkey,0);
  FOR(p,2) {
    detect(p,"XO"[p]);
  }

  if (nlines[1-prev] != 0) {
    printf("ERROR\n");
    return 0;
  }

  if (nlines[prev] == 0) {
    if (full) printf("DRAW\n");
    else printf("IN PROGRESS\n");
    return 0;
  }

  bool happy = 0;
  FOR(i,n) FOR(j,n) if (nkey[prev][i][j] == nlines[prev]) happy = 1;

  if (!happy) {
    printf("ERROR\n");
    return 0;
  }

  printf("%c WINS\n", "XO"[prev]);
}
