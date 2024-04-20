#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
using ld = long double;

int main() {
  //cin.tie(0)->sync_with_stdio(0);
  //cin.exceptions(cin.failbit);
  int n;
  cin >> n;

  vector<array<ld,3>> v(3*n);
  rep(j,0,3) rep(i,0,3*n) scanf("%Lf", &v[i][j]);

  auto gen_prefix = [&](int opponent, const vi& idx) {
    priority_queue<ld> active;
    vector<ld> ans = {-1e18};
    ld gain = 0;
    for(int i : idx) {
      gain -= v[i][opponent]; // give i to opponent
      active.emplace(2*v[i][0]+v[i][opponent]);

      if(sz(active) > n) { // take best one back
        gain += active.top();
        active.pop();
      }
      ans.push_back(sz(active) == n ? gain : -1e18);
    }
    return ans;
  };


  vi idx(3*n);
  iota(all(idx), 0);
  sort(all(idx), [&](int x, int y){ return v[x][1]-v[x][2] > v[y][1]-v[y][2]; });

  auto pre = gen_prefix(1,idx);
  reverse(all(idx));
  auto suf = gen_prefix(2,idx);
  reverse(all(suf));

  ld ans = -1e18;
  rep(i,0,sz(pre)) ans = max(ans, pre[i] + suf[i]);
  cout << fixed << setprecision(14) << fixed;
  cout << (ans/3)*1000 << endl;
}
