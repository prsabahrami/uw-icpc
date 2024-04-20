#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define FR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,n) FR(i,0,n)
#define CLR(x,a) memset(x,a,sizeof(x))
#define setmax(a,b) a = max(a,b)
#define setmin(a,b) a = min(a,b)
typedef long long ll;

const int R=15,C=15;
int i;
char grid[16][16];
int colset[16];
void doit() {
  FOR(r,R) {
    scanf("%s",grid[r]);
    if (0==strcmp("END",grid[r])) exit(0);
  }

  int ans = 15;
  FOR(S,(1<<R)) {
    CLR(colset,0);

    FOR(r,R) if (0==((1<<r)&S)) {
      FOR(c,C) if (grid[r][c]=='#') colset[c]=1;
    }

    int now = 0;
    FOR(c,C) now += colset[c];
    setmax(now, __builtin_popcount(S));
    setmin(ans, now);
  }

  printf("%d\n",ans);
}
int main() {
  while (1) doit();
}
