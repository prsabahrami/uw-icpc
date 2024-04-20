#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <string>
#include <vector>
using namespace std;

#define SZ(v) int((v).size())
#define FR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,n) FR(i,0,n)
#define FORI(i,v) FOR(i,SZ(v))
#define CLR(x,a) memset(x,a,sizeof(x))
#define setmax(a,b) a = max(a,b)
#define setmin(a,b) a = min(a,b)
typedef long long ll;

int R,C;
char buf[16];
int deg[16][16];
int nod[16][16][4];
const int MAXV = 514;
bool mark[MAXV];
int cap[MAXV][MAXV];
vector<int> edg[MAXV];
const int s=MAXV-2,t=MAXV-1;
void connect(int v, int w, int u) {
  cap[v][w] = u;
  cap[w][v] = 0;
  edg[v].push_back(w);
  edg[w].push_back(v);
}
int dr[] = { -1, 0, 1, 0 },
    dc[] = { 0, 1, 0, -1 };
const int inf = 123456789;
int dfs(int v, int flocap=inf) {
  if (v==t) return flocap;

  if (mark[v]) return 0;
  mark[v] = 1;

  FORI(i,edg[v]) {
    int w = edg[v][i];
    if (cap[v][w]) {
      int f = dfs(w, min(flocap, cap[v][w]));

      if (f) {
	cap[v][w] -= f;
	cap[w][v] += f;
	return f;
      }
    }
  }
  return 0;
}
void doit() {
  scanf("%d%d",&R,&C);
  if (R==0) exit(0);

  FOR(v,MAXV) edg[v].clear();
  CLR(cap,0);

  FOR(r,R) {
    FOR(c,C) {
      scanf(" %s",buf);
      if (0==strcmp("x",buf)) deg[r][c]=0;
      else deg[r][c] = strlen(buf);
    }
  }

  int next = 0;
  FOR(r,R) FOR(c,C) {
    if (deg[r][c] != 2) {
      FOR(k,4) nod[r][c][k] = next;
      if ((r+c)%2) connect(s, next, deg[r][c]);
      else connect(next, t, deg[r][c]);
      ++next;
    } else {
      FOR(k,4) nod[r][c][k] = next + (k%2);
      if ((r+c)%2) FOR(k,2) connect(s, next+k, 1);
      else FOR(k,2) connect(next+k, t, 1);
      next += 2;
    }
  }

  FOR(r,R) FOR(c,C) if ((r+c)%2) {
    FOR(k,4) {
      int r2 = r+dr[k], c2 = c+dc[k];
      if (r2<0||r2>=R||c2<0||c2>=C) continue;
      int k2 = (k+2)%4;

      connect(nod[r][c][k], nod[r2][c2][k2], 1);
    }
  }

  while (1) {
    CLR(mark,0);
    int f = dfs(s);
    if (f == 0) break;
  }

  int ed=0,od=0;
  FOR(r,R) FOR(c,C) {
    if ((r+c)%2) od += deg[r][c];
    else ed += deg[r][c];
  }

  bool happy = 1;
  FOR(v,MAXV) if (cap[s][v] || cap[v][t]) happy = 0;

  printf("%s\n", happy ? "SOLVABLE" : "UNSOLVABLE");
}
int main() {
  while (1) doit();
}
