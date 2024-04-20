//  PR, meant to be immediate

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

using namespace std;

#define MAXN 200000

int main () {
  int n;
  int x[MAXN], y[MAXN];
  while (1) {
    scanf("%d",&n);
    if (!n) break;
    assert(0 < n && n%2 && n <= MAXN);
    int nn = (n-1)/2;
    int xb, yb;
    for(int i=0;i<n;i++) {
      scanf("%d%d",&x[i],&y[i]);
      if (i == nn) {
	xb = x[i]; yb = y[i];
      }
    }
    int ss = 0, os = 0;
    for (int i = 0; i<n; i++) {
      if (x[i] < xb && y[i] < yb || x[i] > xb && y[i] > yb) ss++;
      if (x[i] < xb && y[i] > yb || x[i] > xb && y[i] < yb) os++;
    }
    printf("%d %d\n",ss,os);
  }
  return 0;
}
