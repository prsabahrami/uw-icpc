/**
 * Deon Nicholas' solution to "Treasure Hunt"
 *
 * "Just do it".
 *
 * Keep track of the current row and column,
 * as well as which cells have already been visited. At
 * each step, change the row,column according to the instruction
 * in the current cell.
 *
 * If you ever get to a cell you've already visited: "Lost" ("infinite loop")
 * If you ever leave the game board: "Out"
 * If you ever get to a "T" cell: print the number of steps taken so far.
 *
 * These are the only ways the game can end. And one of the above
 * cases will occur in at most R*C steps, so you don't have to worry
 * about time limit here. Just be wary to handle the first case above,
 * so that you don't actually get into an infinite loop, but just detect
 * it and quit early.
 **/


#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>

using namespace std;

#define MAXR 205
#define MAXC 205

typedef pair<int,int> pii;

#define FOR(i,n) for(int i=0;i<(n);++i)

map<char,pii> delta;

char A[MAXR][MAXC];
bool seen[MAXR][MAXC];

#define done(s) return ((cout << (s) << endl), 0)

int main() {
  delta['N'] = make_pair(-1,0);
  delta['E'] = make_pair(0,1);
  delta['S'] = make_pair(1,0);
  delta['W'] = make_pair(0,-1);

  int R,C;
  scanf("%d%d",&R,&C);
  FOR(i,R) scanf("%s",&A[i][0]);

  memset(seen,0,sizeof(seen));

  int ans = 0;
  int i = 0, j = 0;
  while(true) {
    if (i<0 || i>=R || j<0 || j>=C) done("Out");
    else if (seen[i][j]) done("Lost");
    else if (A[i][j] == 'T') done(ans);
    else {
      seen[i][j] = true;
      pii d = delta[A[i][j]];
      i += d.first;
      j += d.second;
      ans++;
    }
  }

  assert(false);
}












