#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define FR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,n) FR(i,0,n)
#define CLR(x,a) memset(x,a,sizeof(x))
#define setmax(a,b) a = max(a,b)

int ls[100000],rs[100000];
bool notroot[100000];
int height[100000];
int ans[100000];
int N;

void doheight(int i) {
  int h = 1;

  if (ls[i]) {
    doheight(ls[i]-1);
    setmax(h, 1+height[ls[i]-1]);
  }
  if (rs[i]) {
    doheight(rs[i]-1);
    setmax(h, 1+height[rs[i]-1]);
  }

  height[i] = h;
}

int getheight(int c) {
  if (c) return height[c-1];
  else return 0;
}

void doans(int i, int lheight=0, int rheight=0, int ltopheight=0, int rtopheight=0) {
  ans[i] = 0;
  setmax(ans[i], 1+lheight);
  setmax(ans[i], 1+rheight);
  setmax(ans[i], 1+ltopheight+getheight(ls[i]));
  setmax(ans[i], 1+rtopheight+getheight(rs[i]));

  if (ls[i]) {
    doans(ls[i]-1, lheight, max(rheight, 1+rtopheight+getheight(rs[i])),
		   ltopheight, 1+rtopheight);
  }
  if (rs[i]) {
    doans(rs[i]-1, max(lheight, 1+ltopheight+getheight(ls[i])), rheight,
		   1+ltopheight, rtopheight);
  }
}

void doit() {
  scanf("%d",&N);
  if (N==0) exit(0);

  CLR(notroot,0);
  FOR(i,N) {
    int l,r;
    scanf("%d%d",&l,&r);
    if (l) notroot[l-1] = 1;
    if (r) notroot[r-1] = 1;
    ls[i] = l;
    rs[i] = r;
  }

  int root = -1;
  FOR(i,N) if (!notroot[i]) root = i;
  
  doheight(root);
  doans(root);

  FOR(i,N) printf("%d\n", ans[i]);
}

const int MULTICASE = 1;
int main() {
  do {
    doit();
  } while (MULTICASE);
}
