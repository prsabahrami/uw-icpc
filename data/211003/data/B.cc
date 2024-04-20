#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;



const ll mod = (119 << 23) + 1, root = 62; // = 998244353

ll modpow(ll b, ll e) {
  ll ans = 1;
  for (; e; b = b * b % mod, e /= 2)
    if (e & 1) ans = ans * b % mod;
  return ans;
}

typedef vector<ll> vl;
void ntt(vl &a) {
  int n = sz(a), L = 31 - __builtin_clz(n);
  static vl rt(2, 1);
  for (static int k = 2, s = 2; k < n; k *= 2, s++) {
    rt.resize(n);
    ll z[] = {1, modpow(root, mod >> s)};
    rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
  }
  vi rev(n);
  rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
  rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int k = 1; k < n; k *= 2)
    for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
      ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
      a[i + j + k] = ai - z + (z > ai ? mod : 0);
      ai += (ai + z >= mod ? z - mod : z);
    }
}
vl conv(const vl &a, const vl &b) {
  if (a.empty() || b.empty()) return {};
  int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
  int inv = modpow(n, mod - 2);
  vl L(a), R(b), out(n);
  L.resize(n), R.resize(n);
  ntt(L), ntt(R);
  rep(i,0,n) out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
  ntt(out);
  return {out.begin(), out.begin() + s};
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n,m;
  cin>>n>>m;
  int DEG = 4;
  vector<vl> a(DEG,vl(n,1)), b(DEG,vl(m,1));
  rep(i,0,n) cin>>a[1][i];
  rep(i,0,m) cin>>b[1][i];
  reverse(all(b[1]));

  rep(k,2,DEG) {
    rep(i,0,n) a[k][i] = a[k-1][i] * a[1][i] % mod;
    rep(i,0,m) b[k][i] = b[k-1][i] * b[1][i] % mod;
  }

  mt19937 rng(/*seed=*/42);
  uniform_int_distribution<ll> uid(ll(0.1*mod), ll(0.9*mod));
  rep(i,0,n) {
    int r = uid(rng);
    rep(k,0,DEG) a[k][i] = (a[k][i] * r) % mod;
  }
  rep(i,0,m) {
    int r = uid(rng);
    rep(k,0,DEG) b[k][i] = (b[k][i] * r) % mod;
  }

  // (x-y)(x-y-1)(x-y+1)
  // = x^3 - 3 x^2 y + 3 x y^2 - x - y^3 + y

  auto x3 = conv(a[3], b[0]);
  auto x2y = conv(a[2], b[1]);
  auto xy2 = conv(a[1], b[2]);
  auto x = conv(a[1], b[0]);
  auto y3 = conv(a[0], b[3]);
  auto y = conv(a[0], b[1]);

  vl ans(sz(x3));
  rep(i,0,sz(ans)) {
    ans[i] = x3[i] - 3*x2y[i] + 3*xy2[i] - x[i] - y3[i] + y[i];
    ans[i] = ((ans[i] % mod) + mod) % mod;
  }

  int cnt = 0;
  rep(i,m-1,n) if(ans[i] == 0) ++cnt;
  cout << cnt << endl;
}
