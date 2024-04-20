#include <iostream>
#include <vector>
using namespace std;

main() {
  int i, j, k, nr, ne;
	long long x, y, z;

	while (cin >> nr && nr != -1) {
	  vector<int> px, py, pz;
		for (i = 0; i < nr; i++) {
		  cin >> x >> y >> z;
			px.push_back(x); py.push_back(y); pz.push_back(z);
		}
		if (!nr) {++nr; px.push_back(101); py.push_back(101); pz.push_back(101);}
		cin >> ne;
		for (i = 0; i < ne; i++) {
		  cin >> x >> y >> z;
			px.push_back(x); py.push_back(y); pz.push_back(z);
		}
		if (!ne) {++ne; px.push_back(101); py.push_back(101); pz.push_back(101);}
		for (;;) {
			for (i = 0; i < px.size(); i++)
			for (j = i+1; j < px.size(); j++)
			for (k = j+1; k < px.size(); k++) {
				x = (pz[j]-pz[i]) * (py[k]-py[i]) - (py[j]-py[i]) * (pz[k]-pz[i]);
				y = (px[j]-px[i]) * (pz[k]-pz[i]) - (pz[j]-pz[i]) * (px[k]-px[i]);
				z = (py[j]-py[i]) * (px[k]-px[i]) - (px[j]-px[i]) * (py[k]-py[i]);
				if (x == 0 && y == 0 && z == 0) continue;
				long long rmin = 1000000000000000000LL, rmax = -1000000000000000000LL;
				long long emin = 1000000000000000000LL, emax = -1000000000000000000LL;
				for (int m = 0; m < nr; m++) {
					int v = x*px[m] + y*py[m] + z*pz[m];
					rmin <?= v; rmax >?= v;
				}
				for (int m = nr; m < px.size(); m++) {
					int v = x*px[m] + y*py[m] + z*pz[m];
					emin <?= v; emax >?= v;
				}
				if (rmin == rmax && rmin == emin && rmin == emax) {
					// all points coplanar; add an independent vector.
					px.push_back(px.back() + x);
					py.push_back(px.back() + y);
					pz.push_back(px.back() + z);
				}
				if (rmin > emax) {
				  cout << -x << ' ' << -y << ' ' << -z << ' ' << rmin << endl;
					goto done;
				}
				if (rmax < emin) {
				  cout << x << ' ' << y << ' ' << z << ' ' << -rmax << endl;
					goto done;
				}
			}
			// all points colinear; add an independent vector.
			px.push_back(px.back() + 202);
			py.push_back(py.back() + 203);
			pz.push_back(pz.back() + 204);
		}
done:;
	}
}
