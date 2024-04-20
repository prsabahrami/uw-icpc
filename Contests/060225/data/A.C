#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

/* how close to call equal */
#define EPSILON 1E-8

typedef struct {
  double x, y;
} Point;

/* returns 1 if intersect at a point, 0 if not, -1 if the lines coincide */
int intersect_line(Point a, Point b, Point c, Point d, Point *p) {
  Point t;
  double r, s, denom, num1, num2;
  assert((a.x != b.x || a.y != b.y) && (c.x != d.x || c.y != d.y));
  num1 = (a.y - c.y)*(d.x - c.x) - (a.x - c.x)*(d.y - c.y);
  num2 = (a.y - c.y)*(b.x - a.x) - (a.x - c.x)*(b.y - a.y);
  denom = (b.x - a.x)*(d.y - c.y) - (b.y - a.y)*(d.x - c.x);
  if (fabs(denom) >= EPSILON) {
    r = num1 / denom;
    s = num2 / denom;
    if (0-EPSILON <= r && r <= 1+EPSILON && 
        0-EPSILON <= s && s <= 1+EPSILON) {
      p->x = a.x + r*(b.x - a.x);
      p->y = a.y + r*(b.y - a.y);
      return 1;
    } else return 0;
  } else {
    if (fabs(num1) >= EPSILON) {
      return 0;
    } else {
      if (a.x > b.x || (a.x == b.x && a.y > b.y)) { t = a; a = b; b = t; }
      if (c.x > d.x || (c.x == d.x && c.y > d.y)) { t = c; c = d; d = t; }
      if (a.x == b.x) { /* vertical lines */
        if (b.y == c.y) { *p = b; return 1;
        } else if (a.y == d.y) { *p = a; return 1;
        } else if (b.y < c.y || d.y < a.y) { return 0;
        } else return -1;
      } else {
        if (b.x == c.x) { *p = b; return 1;
        } else if (a.x == d.x) { *p = a; return 1; 
	} else if (b.x < c.x || d.x < a.x) return 0;
        else return -1;
      }
      return -1;
    }
  }
}

int main () {
  int h, m, s;
  double x[6];
  while (1) {
    for (int i = 1; i < 6; i++) {
      if (scanf("%d:%d:%d",&h,&m,&s) != 3) return 0;
      x[i] = h*3600+m*60+s;
    }
    assert(x[1] < x[2]);
    assert(x[2] < x[3]);
    assert(x[3] < x[4]);
    assert(x[4] < x[5]);
    double y0, y1, y2, y3, y4, y5;
    y0 = y5 = 10000;
    y3 = y5+(x[5]-x[3])/x[5]*(y0-y5);
    y4 = y5+(x[5]-x[4])/x[5]*(y0-y5);
    y2 = y3*x[2]/x[3];
    y1 = y3*x[1]/x[3];
    Point a, b, c, d, r;
    a.x=x[1]; a.y=y1; b.x=x[4]; b.y=y4; c.x=x[2]; c.y=y2; d.x=x[5]; d.y=y5;
    int res = intersect_line(a, b, c, d, &r);
    assert (res == 1);
    char buf[100];
    sprintf(buf, "%.0f",r.x); sscanf(buf,"%d",&s);
    h = s/3600; s %= 3600; m = s/60; s %= 60;
    printf("%02d:%02d:%02d\n",h,m,s);
  }
  return 0;
}
