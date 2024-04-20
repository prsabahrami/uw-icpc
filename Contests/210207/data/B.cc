#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll n, A, B;
  cin>>n;
  vi nxt(n);
  rep(i,0,n) cin >> nxt[i];
  cin >> A >> B;

  vi xs = nxt;
  sort(all(xs));
  xs.erase(unique(all(xs)), xs.end());
  assert(sz(xs) == n);
  rep(i,0,n) nxt[i] = lower_bound(all(xs), nxt[i]) - begin(xs);

  ll cost = 0;
  vector<pii> ans;
  auto swp = [&](int x, int y) {
    assert(nxt[y] <= x && x < y && y <= nxt[x]);
    cost += B + A*(y-x);
    ans.emplace_back(x+1, y+1);
    swap(nxt[x], nxt[y]);
  };

  rep(x,0,n) if(nxt[x] < x) {
    vi q = {nxt[x]};
    while(nxt[q.back()] < x) q.push_back(nxt[q.back()]);
    q.push_back(x);
    reverse(all(q));
    rep(i,1,sz(q)) swp(q[i], q[i-1]);
  }
  rep(i,0,n) assert(nxt[i] == i);

  cout << cost << endl;
  cout << sz(ans) << endl;
  for(auto [x,y] : ans) cout << x << " " << y << "\n";
}
