#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <iomanip>
#include <assert.h>
#include <algorithm>

#define EPS 0.000001

using namespace std;

double r;
int k;
const double PI = acos(-1.0);
vector<double> reachTime, speed, angle;
vector<pair<double, double> > c;

bool covers(double t) {
    c.clear();

    for (int i = 0; i < k; i++) {
        if (t < reachTime[i]) continue;
        double range = speed[i] * (t - reachTime[i]);
        if (range >= PI) return true;
        c.push_back(make_pair(angle[i] - range, angle[i] + range));
    }

    // Add special intervals for overlaps outside of [0; 2*PI]
    double mn = 2 * PI, mx = 0;
    for (int i = 0; i < c.size(); i++) {
        if (c[i].first < 0) {
            mn = min(mn, c[i].first);
            c[i].first = 0;
        }
        if (c[i].second > 2 * PI) {
            mx = max(mx, c[i].second);
            c[i].second = 2 * PI;
        }
    }

    if (mn < 0) {
        c.push_back(make_pair(2*PI + mn, 2*PI + EPS));
    }
    if (mx > 2*PI) {
        c.push_back(make_pair(-EPS, mx - 2*PI));
    }

    sort(c.begin(), c.end());

    double start = c[0].first;

    if (start > 0) {
        return false;
    }

    double cur = c[0].second;
    for (int i = 1; i < c.size(); i++) {
        if (c[i].first <= cur) {
            cur = max(cur, c[i].second);
        }
    }
    return cur >= 2*PI;
}

void solve() {
    cin >> r >> k;

    reachTime.clear();
    speed.clear();
    angle.clear();

    double x, y, rocketSpeed, virusSpeed;
    for (int i = 0; i < k; i++) {
        cin >> x >> y >> rocketSpeed >> virusSpeed;

        assert(rocketSpeed > 0);
        assert(virusSpeed > 0);

        double dst = sqrt(x*x+y*y) - r;
        reachTime.push_back(dst / rocketSpeed);
        // Calculate angle
        angle.push_back(atan2(y, x) + PI);
        // Calculate angular speed
        speed.push_back(virusSpeed / r);      
    }

    // Binary search the time to cover the planet
    double ll = 0, rr = 2000000;
    while (rr - ll > EPS) {
        double mid = (rr + ll) / 2;
        if (covers(mid)) {
            rr = mid;
        } else {
            ll = mid;
        }
    }

    cout << fixed << setprecision(9) << ll << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    int numTests;
    cin >> numTests;
    for (int i = 0; i < numTests; i++) {
        solve();
    }
    return 0;
}
