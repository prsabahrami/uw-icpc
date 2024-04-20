#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#define EPS 1E-6
#define pt(a) &(a.x), &(a.y), &(a.z)

typedef struct {
  double x, y, z;
} Point;

Point operator + (Point a, Point b) {
  Point p;

  p.x = a.x + b.x;
  p.y = a.y + b.y;
  p.z = a.z + b.z;
  return p;
}

Point operator * (double k, Point a) {
  Point p;

  p.x = k*a.x;
  p.y = k*a.y;
  p.z = k*a.z;
  return p;
}

Point operator * (Point a, double k) {
  return (k*a);
}

Point operator / (Point a, double k) {
  return a*(1/k);
}

Point operator - (Point a, Point b) {
  return a+(-1.0*b);
}

double dot(Point a, Point b) {
  return a.x*b.x + a.y*b.y + a.z*b.z;
}

Point cross(Point a, Point b) {
  Point cp;
 
  cp.x = a.y*b.z-b.y*a.z;
  cp.y = b.x*a.z-a.x*b.z;
  cp.z = a.x*b.y-b.x*a.y;
  return cp;
}

double lng2(Point a) {  // find the length of a vector, squared
  return dot(a,a);
}

double lng(Point a) {   // find the length of a vector
  return sqrt(dot(a,a));
}

Point closest_pt_iline(Point a, Point b, Point p) {
  double along = dot(b-a,p-a)/lng2(b-a);
  return (b-a)*along + a;
}

/* Given a sphere and an infinite line, determine if the two
   intersect, and if so, find the points of intersection.  If the 
   line is tangent to the sphere, the points will be the same */

int sphere_iline_isect(Point c, double r, Point a, Point b, 
                      Point *p, Point *q) {
  Point vec, mid = closest_pt_iline(a,b,c);

  if (lng2(c-mid) > r*r) return 0;
  vec = (a-b)*sqrt((r*r - lng2(c-mid))/lng2(a-b));
  *p = mid + vec;
  *q = mid - vec;
  return 1;
}

int main()
{
	int i,j,k,m,hit[128];
	double pi = -acos(-1);
	double r = 40000.0/(2*pi);
	double d1,d2,d3;
	Point s[128], t[128], o,p1,p2;
	o.x = o.y = o.z = 0.0;

	while (scanf("%d %d ", &m,&k)==2) {
		if (!k) break;
		memset(hit, 0, sizeof(hit));
		for (i=0; i<m; i++) scanf("%lf %lf %lf ", &s[i].x,&s[i].y,&s[i].z);
		for (i=0; i<k; i++) scanf("%lf %lf %lf ", &t[i].x,&t[i].y,&t[i].z);
		for (i=0; i<m; i++) for (j=0; j<k; j++) {
			if (hit[j]) continue;
			if (!sphere_iline_isect(o,r,t[j],s[i],&p1,&p2)) {
				hit[j] = 1;
				continue;
			}
			d1 = lng(t[j]-s[i]);
			d2 = lng(p1-s[i]);
			d3 = lng(p2-s[i]);
			//printf("%lf\n",d1);
			//printf("%lf\n", d2);
			//printf("%lf %lf %lf %lf\n", p1.x,p1.y,p1.z,d2);
			//printf("%lf\n", d3);
			//printf("%lf %lf %lf %lf\n", p2.x,p2.y,p2.z,d3);
			if (d2+EPS < d1 || d3+EPS < d1) continue;
			//printf("Hit!\n");
			hit[j] = 1;
		}
		for (i=j=0; i<k; i++) if (hit[i]) j++;
		printf("%d\n", j);
	}
	return 0;
}
