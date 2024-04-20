#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double EPS = 1e-8;

double getv() {
	int dg, mn;
	char dir;
	scanf( " %d,%d%c", &dg, &mn, &dir );
	return ((dir=='S' || dir=='E') ? -1 : 1) * (dg + mn/60.0);
}

main() {
	double pi = acos(0.0)*2, tmp;
	int n;

	for( cin >> n; n--; ) {
		double lat = getv()*pi/180, lon = getv()*pi/180;
		double ret = lat;
		double x1 = sin(lon)*cos(lat), y1 = cos(lon)*cos(lat), z1 = sin(lat);
		lat = getv()*pi/180, lon = getv()*pi/180;
		ret >?= lat;
		double x2 = sin(lon)*cos(lat), y2 = cos(lon)*cos(lat), z2 = sin(lat);

		double d = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
		if( d < EPS ) goto done;
		if( d > 2-EPS ) {
			if( z1 > 1-EPS || z2 > 1-EPS ) goto done;
			cout << "undefined\n";
			continue;
		}

		{
			double x3 = y1*z2 - z1*y2;
			double y3 = z1*x2 - x1*z2;
			double z3 = x1*y2 - y1*x2;
			double d = sqrt(x3*x3 + y3*y3 + z3*z3);
			x3 /= d; y3 /= d; z3 /= d;
			if( z3 < 0 ) {x3 = -x3; y3 = -y3; z3 = -z3;}
			double th = -atan2(y3, x3), sth = sin(th), cth = cos(th);
			tmp = x1*cth - y1*sth; y1 = y1*cth + x1*sth; x1 = tmp;
			tmp = x2*cth - y2*sth; y2 = y2*cth + x2*sth; x2 = tmp;
			tmp = x3*cth - y3*sth; y3 = y3*cth + x3*sth; x3 = tmp;
			swap(x3, z3); x3 = -x3;
			if( acos(x1*x3 + y1*y3 + z1*z3) +
				acos(x2*x3 + y2*y3 + z2*z3) <
				acos(x1*x2 + y1*y2 + z1*z2)+EPS )
				ret = asin(z3);
		}

done:
		char ch = (ret < 0.0) ? 'S' : 'N';
		ret = abs(ret * 180/pi);
		ret += 0.5/60;
		cout << (int)ret << ',' << ((int)(ret*60))%60 << ch << endl;
	}
}
