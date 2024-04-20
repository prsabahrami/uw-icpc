// Rectilinear polygon

// Note: for each x or y coordinate there must be an even number of points
// and thus the edges are forced.

// Check whether it is connected.

// P. Rudnicki, Nagano, May 5, 2003

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100010

typedef struct {
  int p, x, y, h, v;
} Point;

Point P[MAXN];

int cmpx(const void *a, const void *b) {
  Point *ap = (Point *)a, *bp = (Point *)b;
  if (ap->x < bp->x) return -1;
  if (ap->x > bp->x) return 1;
  if (ap->y < bp->y) return -1;
  if (ap->y > bp->y) return 1;
  return 0;
}

int cmpy(const void *a, const void *b) {
  Point *ap = (Point *)a, *bp = (Point *)b;
  if (ap->y < bp->y) return -1;
  if (ap->y > bp->y) return 1;
  if (ap->x < bp->x) return -1;
  if (ap->x > bp->x) return 1;
  return 0;
}

int cmpp(const void *a, const void *b) {
  Point *ap = (Point *)a, *bp = (Point *)b;
  return ap->p - bp->p;
}

int main () {
  int c;
  scanf("%d",&c);
  while (c--) {
    int n; 
    scanf("%d",&n);
    assert(4 <= n && n <= 100000);
    for(int i = 0; i < n; i++) {
      scanf("%d%d",&(P[i].x), &(P[i].y));
      P[i].p = i; P[i].v = -1; P[i].h = -1;
    }
    qsort(P,n,sizeof(Point),cmpx);     // sort xs
    int i = 0;
    while (i+1 < n) {
      if (P[i].x == P[i+1].x) {
	P[i].v = P[i+1].p;
	P[i+1].v = P[i].p;
	i +=2;
      } else goto A;
    }
    qsort(P,n,sizeof(Point),cmpy);    // sort ys
    i = 0;
    while (i+1 < n) {
      if (P[i].y == P[i+1].y) {
	P[i].h = P[i+1].p;
	P[i+1].h = P[i].p;
	i += 2;
      } else goto A;
    }
    // check connectedness
    qsort(P,n,sizeof(Point),cmpp);    
    int u[MAXN];
    memset(u,0,n*sizeof(int));
    i = 0;
    int sum;
    sum = 0;
    while (1) {
      if (P[i].v == -1) break;
      sum += abs(P[P[i].v].y - P[i].y);
      i = P[P[i].v].p;
      u[i] = 1;
      if (P[i].h == -1) break;
      sum += abs(P[P[i].h].x - P[i].x);
      i = P[P[i].h].p;      
      u[i] = 1;
      if (!i) break;
    }
    int done;
    done = 1;
    for (int i = 0; i < n; i++)
      if (!u[i]) { done = 0; break; }
    if (done) { printf("%d\n",sum); continue; }
  A: printf("-1\n");
  }
  return 0;
}
