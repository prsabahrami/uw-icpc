#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <map>
#include <set>

using namespace std;

#define MAXN 200000

typedef struct {
  int x; int y;
} point;

// s sorted by y, t sorted by x, 

int cmpt( const void *a, const void *b) {
  const point *ap = (point *)a, *bp = (point *)b;
  if (ap->x == bp->x && ap->y == bp->y)
    return 0;
  if (ap->x < bp->x || ap->x == bp->x && ap->y < bp->y)
    return -1;
  return 1;
}

int cmps( const void *a, const void *b) {
  const point *ap = (point *)a, *bp = (point *)b;
  if (ap->x == bp->x && ap->y == bp->y)
    return 0;
  if (ap->y < bp->y || ap->y == bp->y && ap->x < bp->x)
    return -1;
  return 1;
}

point t[MAXN], s[MAXN];
int c[MAXN], res[MAXN];

int main () {
  int n;
  while (1) {
    cin >> n;
    if (!n) break;
    assert(0 < n && n <= MAXN);
    for (int i = 0; i < n; i++) {
      cin >> s[i].x >> s[i].y;
      t[i].x = s[i].x; t[i].y = s[i].y;
      c[i] = 0;
    }
    qsort(t, n, sizeof(point), cmpt);
    qsort(s, n, sizeof(point), cmps);
    int l,m,r, cnt;
    for (int i = 0; i < n; i++) {
      l = 0; r = n-1;
      cnt = 0;
      while (l < r) {
	m = (l+r)/2;
	if (cmpt(&t[m], &s[i]) == -1) {
	  cnt += c[m]; l = m+1;
	} else {
	  c[m]++; r = m;
	}
      }
      res[r] = cnt+1;
    }
    map<int,int> xm, ym, xc, yc; // count to the left or below and on the lines
    for (int i=0;i<n;i++) {
      xm[t[i].x] = i+1; ym[s[i].y] = i+1;
      xc[t[i].x]++; yc[s[i].y]++;
    }
    map<pair<int,int>,int> pxb, pyb; // left and below on x and y of a point
    int i = 0;
    while (i<n) {
      int xi = t[i].x, j = i;
      while (i<n && xi == t[i].x) {
	pyb[make_pair(t[i].x,t[i].y)] = i-j;
	i++;
      }
    }
    i = 0;
    while (i<n) {
      int yi = s[i].y, j = i;
      while (i<n && yi == s[i].y) {
	pxb[make_pair(s[i].x,s[i].y)] = i-j;
	i++;
      }
    }
    int ss = -1;
    set<int> oset;
    i = 0;
    while (i<n) {
      int xi = t[i].x;
      int lss = n, los = 0;
      while (i<n && xi == t[i].x) {
	int nos = xm[xi]-xc[xi]+ym[t[i].y]-yc[t[i].y]-2*res[i]+2
	  +pyb[make_pair(t[i].x,t[i].y)]+pxb[make_pair(t[i].x,t[i].y)];
	int nss = n-nos-xc[xi]-yc[t[i].y]+1;
	if (nss < lss) { lss = nss; los = nos; }
	i++;
      }
      if (lss > ss) { 
	ss = lss; oset.clear(); oset.insert(los); 
      } else if (lss == ss)  oset.insert(los); 
    }
    printf("Stan: %d; Ollie:",ss);
    for (set<int>::iterator p=oset.begin(); p!=oset.end();p++)
      printf(" %d",*p);
    printf(";\n");
  }
  return 0;
}
