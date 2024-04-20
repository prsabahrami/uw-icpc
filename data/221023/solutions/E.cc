#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
#include <iostream>
#include <functional>
#include <complex>
#include <stdlib.h>
#include <random>
#pragma comment(linker, "/STACK:836777216")

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<pii, int> p3i;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<p3i> v3i;
typedef vector<vii> vvii;
typedef vector<p3i> vp3i;
typedef long double ld;
typedef vector<ld> vld;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define REPD(i, n) for (int (i) = (n) - 1; (i) >= 0; (i)--)
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define FORD(i,a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define rv(v) reverse(all(v))
#define CL(v, val) memset((v), (val), sizeof((v)))
#define SORT(a) sort(all(a))
#define un(v) SORT(v), (v).resize(unique(all(v)) - (v).begin())
#define eps 1.0e-9
#define X first
#define Y second
#define bit(n) (1 << (n))
#define bit64(n) (ll(1) << (n))
#define sqr(x) ((x) * (x))

ll xs,ys,xf,yf;
ll corner, cross, line, tshape;

void NO() {
  printf("No\n");
}

void YES() {
  printf("Yes\n");
}

ll CornerToLine(ll line) {
  return line / 2 * 4 + (line % 2 ? 3 : 0);
}

int main(void) {
  scanf("%lld%lld", &xs, &ys);
  scanf("%lld%lld", &xf, &yf);
  scanf("%lld%lld%lld%lld", &corner, &cross, &line, &tshape);

  cross-= 2;
  tshape += cross;

  ll dx = abs(xs - xf);
  ll dy = abs(ys - yf);

  if (dy > dx) {
    swap(dx, dy);
  }

  //special cases
  if (dy == 0) {
    if (dx == 1) {
      YES();
      return 0;
    }
    dx--;

    ll needed = (line + tshape < dx ? dx - (line + tshape) : 0);

    if (needed) {
      ll corner_needed = CornerToLine(needed);

      if (corner_needed > corner) {
        NO();
        return 0;
      }
    }

    YES();
    return 0;
  }

  if (corner + tshape < 1) {
    NO();
    return 0;
  }

  if (!corner) {
    corner++;
    tshape--;
  }

  corner--;

  line += tshape;

  dx--;
  dy--;

  if (dx + dy <= line) {
    YES();
    return 0;
  }

  ll corners_rep = min(dy, corner / 2);
  dx -= corners_rep;
  dy -= corners_rep;
  corner -= corners_rep * 2;

  ll line_y = min(dy, line);
  dy -= line_y;
  line -= line_y;

  ll line_x = min(dx, line);
  dx -= line_x;
  line -= line_x;

  ll corners_needed = 0;

  if (!dy) {
    if (dx % 2) {
      dx--;
      corners_needed++;
    }
  }
  corners_needed += CornerToLine(dx) + CornerToLine(dy);
  if (corners_needed > corner) {
    NO();
    return 0;
  }
  YES();
  return 0;
}







