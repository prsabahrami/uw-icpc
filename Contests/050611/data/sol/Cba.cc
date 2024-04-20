#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <list>
#include <vector>
using namespace std;

#define BOUNDARY 1
#define EPS 1e-8
#define SQR(x) ((x)*(x))

typedef struct{
  double x,y;
} Point;

double dist_2d(Point a, Point b){
  return sqrt(SQR(a.x-b.x)+SQR(a.y-b.y));
}

int intersect_line(Point a, Point b, Point c, Point d, Point *p){
  Point t; double r, s, denom, num1, num2;

  num1  = (a.y - c.y)*(d.x - c.x) - (a.x - c.x)*(d.y - c.y);
  num2  = (a.y - c.y)*(b.x - a.x) - (a.x - c.x)*(b.y - a.y);
  denom = (b.x - a.x)*(d.y - c.y) - (b.y - a.y)*(d.x - c.x);

  if (fabs(denom) >= EPS) {
    r = num1 / denom;
    s = num2 / denom;

    if (//0-EPS <= r && r <= 1+EPS && 
        0-EPS <= s && s <= 1+EPS) {
      p->x = a.x + r*(b.x - a.x);
      p->y = a.y + r*(b.y - a.y);
      return 1;
    }
    return 0;
  }
  if (fabs(num1) >= EPS) return 0;
  if (a.x > b.x || (a.x == b.x && a.y > b.y)) { t = a; a = b; b = t; }
  if (c.x > d.x || (c.x == d.x && c.y > d.y)) { t = c; c = d; d = t; }
  if (a.x == b.x) {
    if (b.y == c.y) {
      *p = b; return 1; 
    } else if (a.y == d.y) {
      *p = a; return 1;
    } else if (b.y < c.y || d.y < a.y)
      return 0;
  } else {
    if (b.x == c.x) {
      *p = b; return 1;
    } else if (a.x == d.x) {
      *p = a; return 1;
    } else if (b.x < c.x || d.x < a.x) 
      return 0;
  }
  return -1;
}

int pt_in_poly(Point *p, int n, Point a) {
  int i, j, c = 0;

  for (i = 0, j = n-1; i < n; j = i++) {
    if (dist_2d(p[i],a)+dist_2d(p[j],a)-dist_2d(p[i],p[j]) < EPS)
      return BOUNDARY;
    if ((((p[i].y<=a.y) && (a.y<p[j].y)) ||
         ((p[j].y<=a.y) && (a.y<p[i].y))) &&
        (a.x < (p[j].x-p[i].x) * (a.y - p[i].y) 
               / (p[j].y-p[i].y) + p[i].x)) c = !c;
  }
  return c;
}

int sort_hits(const void *a, const void *b)
{
	Point *ha = (Point *)a;
	Point *hb = (Point *)b;
	if (ha->x == hb->x) return (ha->y <= hb->y) ? -1 : 1;
	return (ha->x < hb->x) ? -1 : 1;
}

int main()
{
	int i,j,k,n,m,nh,z;
	double ret;
	Point a,b,c,poly[1024],hit[4048];

	while (scanf("%d %d ", &n, &m)==2) {
		if (!n && !m) break;
		for (i=0; i<n; i++) scanf("%lf %lf ", &poly[i].x, &poly[i].y);
		for (z=0; z<m; z++) {
			scanf("%lf %lf %lf %lf ", &a.x, &a.y, &b.x, &b.y);
			for (i=nh=0; i<n; i++) {
				j = (i+1)%n;
				if (intersect_line(a,b,poly[i],poly[j],&c)==1) {
					hit[nh++] = c;
				}
			}
			ret = 0;
			qsort(hit, nh, sizeof(Point), sort_hits);
			for (i=0; i<nh-1; i++) {
				c.x = (hit[i].x + hit[i+1].x)/2;
				c.y = (hit[i].y + hit[i+1].y)/2;
				if (pt_in_poly(poly, n, c)) 
					ret += dist_2d(hit[i], hit[i+1]);
			}
			printf("%.3lf\n", ret);
		}
	}
	return 0;
}
