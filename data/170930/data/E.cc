#include <bits/stdc++.h>

using namespace std;

namespace {
#define VERA(i, a, b)for(auto i=(ll)(a);i<(ll)(b);++i)
#define ANDY(i, a, b)for(auto i=(ll)(a);i>(ll)(b);--i)

typedef long long ll;
typedef long double dd;

struct Rectangle {
  ll x1, y1, x2, y2;

  bool Contains(ll xl, ll xr) const {
    return x1 <= xl && xr <= x2;
  }
};

ll CalcLine(ll m, ll b, ll xl, ll xr, ll L, ll R) {
  // let f(x) = mx+b
  // return sum_{max(xl,L)}^{min(xr,R)} f(x)
  xl = max(xl, L);
  xr = min(xr, R);
  if (xl > xr)
    return 0;
  return (xr - xl + 1) * (m * xl + b + m * xr + b) / 2;
}

ll Calc(ll x1, ll y1, ll x2, ll y2, ll L, ll R) {
  ll corners[4] = {x1 + y1, x2 + y1, x1 + y2, x2 + y2};
  sort(corners, corners + 4);
  ll res = 0;
  res += CalcLine(1, -corners[0], corners[0], corners[1], L, R);
  res += CalcLine(0, corners[1] - corners[0], corners[1] + 1, corners[2], L, R);
  res += CalcLine(-1, corners[3], corners[2] + 1, corners[3], L, R);
  return res;
}

void Solve(int test_num) {
  (void) test_num;
  ll N, L, R;
  cin >> N >> L >> R;
  vector<Rectangle> rects(N);
  for (auto& r : rects) {
    cin >> r.x1 >> r.y1 >> r.x2 >> r.y2;
  }
  ll res = 0;
  vector<ll> xvals;
  map<ll, ll> yvals;
  for (const auto& r : rects) {
    xvals.push_back(r.x1);
    xvals.push_back(r.x2);
  }
  sort(xvals.begin(), xvals.end());
  xvals.erase(unique(xvals.begin(), xvals.end()), xvals.end());
  VERA(i, 1, xvals.size()) {
    yvals.clear();
    const auto xl = xvals[i - 1], xr = xvals[i];
    for (const auto& r : rects) {
      if (r.Contains(xl, xr)) {
        yvals[r.y1] += 1;
        yvals[r.y2] -= 1;
      }
    }
    ll sum = 0, prev = 0;
    for (const auto& entry : yvals) {
      if (sum > 0) {
        res += Calc(xl, prev, xr, entry.first, L, R);
      }
      sum += entry.second;
      prev = entry.first;
    }
  }
  cout << res << endl;
}

void init() {
}

}

int main() {
#ifdef AZN
  const auto start_time = chrono::system_clock::now();
  freopen("../../input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  srand(1223);
  init();
  int tests = 1;
//  cin >> tests;
  for (int test = 1; test <= tests; ++test) {
    Solve(test);
  }
#ifdef AZN
  cerr << "Took: " << ((chrono::system_clock::now() - start_time).count() / 1e9) << " s" << endl;
#endif
  return 0;
}
