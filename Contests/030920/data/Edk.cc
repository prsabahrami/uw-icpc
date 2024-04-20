#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

struct Point {
	double x, y;
	Point(double x, double y) : x(x), y(y) {}
	Point operator-(const Point &p) const {return Point(x-p.x, y-p.y);}
	Point operator+(const Point &p) const {return Point(x+p.x, y+p.y);}
};

double PI = acos(0.0)*2;
string compass[32] = {"N", "NbE", "NNE", "NEbN", "NE", "NEbE", "ENE", "EbN",
					  "E", "EbS", "ESE", "SEbE", "SE", "SEbS", "SSE", "SbE",
					  "S", "SbW", "SSW", "SWbS", "SW", "SWbW", "WSW", "WbS",
					  "W", "WbN", "WNW", "NWbW", "NW", "NWbN", "NNW", "NbW"};

Point vect(double th, double d) {
	return Point(sin(th)*d, cos(th)*d);
}

double dot(Point a, Point b) {return a.x*b.x + a.y*b.y;}
double cross(Point a, Point b) {return a.x*b.y - a.y*b.x;}

double dist(Point p, Point s, Point e) {
	if( dot(p-s, e-s) * dot(p-e, e-s) <= 0 )
		return fabs(cross(p-s, e-s)) / sqrt(dot(e-s, e-s));
	return sqrt(dot(p-s, p-s)) <? sqrt(dot(p-e, p-e));
}

int dir[1000];
double d[1000];

main() {
	int i, j, k, x, y, z, n;
	string s;

	while( cin >> n && n ) {
		Point t(0, 0), a(0, 0), b(0, 0);
		for( i = 0; i < n; i++ ) {
			cin >> s >> d[i];
			dir[i] = find(compass, compass+32, s) - compass;
			t = t + vect(dir[i]*PI/16, d[i]);
		}
		double ret = 1e20, th;
		cin >> th;
		th *= PI/180;
		for( i = 0; i < n; i++ ) {
			b = a + vect(dir[i]*PI/16 - th, d[i]);
			ret <?= dist(t, a, b);
			a = b;
		}
		printf( "%.2lf\n", ret );
	}
}

