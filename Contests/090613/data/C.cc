#include <cstring>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>
using namespace std;

#define FR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,n) FR(i,0,n)
#define FORALL(i,v) for(typeof((v).end())i=(v).begin();i!=(v).end();++i)
#define CLR(x,a) memset(x,a,sizeof(x))
#define BEND(v) (v).begin(),(v).end()
#define MP make_pair
#define PB push_back
#define A first
#define B second
#define dump(x) cerr << #x << " = " << (x) << endl
typedef long long ll; typedef long double ld;

const ll MOD = 1000000007;

ll L;
int K;
ll dp[2][101];
int dodp(int l) {
  FOR(i,l) {
    int i1 = i%2, i2 = (i+1)%2;
    CLR(dp[i2],0);

    FOR(k2,K+1) {
      int k1 = ((i-2*k2)%K+K)%K;
      int k0 = K-k1-k2;
      if (k0+k1+k2 > K) continue;
      if (k0 < 1) continue;
      
      int k0p = k0-1, k1p = k1+1, k2p = k2;
      if (k0p == 0) k1p = k2p, k2p = 0;
      dp[i2][k2p] = (dp[i2][k2p] + k0*dp[i1][k2])%MOD;

      if (k1 > 0) {
	k1p = k1-1, k2p = k2+1;
	dp[i2][k2p] = (dp[i2][k2p] + k1*dp[i1][k2])%MOD;
      }
    }
  }

  return l%2;
}

struct Matrix {
  ll dat[101][101];
  Matrix() {
    CLR(dat,0);
    FOR(k,K+1) dat[k][k] = 1;
  }
};

const Matrix operator*(const Matrix &A, const Matrix &B) {
  Matrix C;

  FOR(i,K+1) FOR(j,K+1) {
    C.dat[i][j] = 0;
    FOR(k,K+1) C.dat[i][j] = (C.dat[i][j] + A.dat[i][k]*B.dat[k][j]) % MOD;
  }

  return C;
}

const Matrix expmod(Matrix X, ll n) {
  Matrix ret;

  while (n) {
    if (n%2) ret = ret*X;
    X = X*X;
    n /= 2;
  }

  return ret;
}

int main() {
  scanf("%lld%d",&L,&K);
  assert(1 <= L && L <= 1000000000000000000LL);
  assert(1 <= K && K <= 100);

  ll matpart = L/K;

  Matrix X;

  FOR(k,K+1) {
    CLR(dp,0);
    dp[0][k] = 1;

    int idx = dodp(K);

    FOR(kp,K+1) {
      X.dat[kp][k] = dp[idx][kp];
    }
  }

  Matrix Y = expmod(X, matpart);

  CLR(dp,0);
  FOR(k,K+1) dp[0][k] = Y.dat[k][0];

  ll extpart = L-K*matpart;
  assert(extpart >= 0);

  int finidx = dodp(extpart);

  ll ans = 0;
  FOR(k2,K+1) ans = (ans + dp[finidx][k2]) % MOD;

  printf("%lld\n",ans);
}
