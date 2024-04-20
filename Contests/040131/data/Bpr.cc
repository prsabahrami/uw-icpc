#include <stdio.h>
#include <assert.h>
#include <set>
#include <queue>
#include <math.h>

// n * log n P. Rudnicki

#define MAXN 100000
#define MAXC 1000000

using namespace std;

int t[MAXN], x[MAXN];
char u[MAXN];
int ql[MAXN], qr[MAXN];
int n, m, mid;

int howmany(int il, int ir) {
  while (il < n && !u[ql[il]]) il++;  // s is the next leftmost
  if (il == n) return 0;
  while (ir < n && x[qr[ir]]-(t[qr[ir]]-mid) <= x[ql[il]]+(t[ql[il]]-mid)) 
    { u[qr[ir]] = 0; ir++; }
  u[ql[il]] = 0;
  //  printf("\t %d %d \n", il, ir);
  return 1+howmany(il+1, ir);
}

int cmp (const void *ap, const void *bp) {
  int a = *(int *)ap, b = *(int *)bp;
  if (x[a]+t[a] < x[b]+t[b]) return -1;
  if (x[a]+t[a] > x[b]+t[b]) return 1;
  return 0;
}

int cmp1 (const void *ap, const void *bp) {
  int a = *(int *)ap, b = *(int *)bp;
  if (x[a]-t[a] < x[b]-t[b]) return -1;
  if (x[a]-t[a] > x[b]-t[b]) return 1;
  return 0;
}

int main () {
  int c;
  scanf("%d",&c);
  for (int cc = 1; cc <= c; cc++) {
    int mint = MAXC, minx = MAXC, maxx = -MAXC;
    scanf("%d%d",&n,&m);
    assert(1 <= n && n <= MAXN && 1 <= m && m <= MAXN);
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &t[i], &x[i]);
      assert(-MAXC <= t[i] && t[i] <= MAXC && -MAXC <= x[i] && x[i] <= MAXC);
      if (t[i] < mint) mint = t[i];
      if (x[i] < minx) minx = x[i];
      if (x[i] > maxx) maxx = x[i];
    }
    int lt = mint-ceil((maxx-minx)/2.0), ht = mint;
    int sol = ht;
    for (int i = 0; i < n; i++) ql[i] = qr[i] = i;
    qsort(ql,n,sizeof(int),cmp);
    qsort(qr,n,sizeof(int),cmp1);
    while (lt <= ht) {
      mid = ceil((ht+lt)/2.0);
      for (int i = 0; i < n; i++) u[i] = 1;
      int count = howmany(0,0);
      //      printf("%d %d %d : %d (left %d)\n", lt, mid, ht, count, u.size());
      if (count <= m) {
	sol = mid;
	lt = mid+1;
      } else
	ht = mid-1;
    }
    printf("Case %d: %d\n", cc, sol);
  }
  return 0;
}
