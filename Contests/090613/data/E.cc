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

int W,vh,N;
int xs[100000],ys[100000];
int S;
int ss[1000000];
int main() {
  scanf("%d%d%d",&W,&vh,&N);
  assert(1 <= W && W <= 100000000);
  assert(1 <= vh && vh <= 1000000);
  assert(2 <= N && N <= 100000);

  FOR(i,N) {
    scanf("%d%d",&xs[i],&ys[i]);
    assert(1 <= xs[i] && xs[i] <= 100000000);
    assert(1 <= ys[i] && ys[i] <= 100000000);
  }

  FOR(i,N-1) assert(ys[i+1] > ys[i]);

  scanf("%d",&S);
  assert(1 <= S && S <= 1000000);
  FOR(i,S) {
    scanf("%d",&ss[i]);
    assert(1 <= ss[i] && ss[i] <= 1000000);
  }
  sort(&ss[0], &ss[S]);

  int lo = -1, hi = S;
  while (lo+1 < hi) {
    int mid = (lo+hi)/2;

    ll s = ss[mid];

    // 2*10^8 * 10^6 = 2*10^14
    ll l = 0, r = 200000000 * s;
    ll y = 0;

    bool ok = 1;
    FOR(i,N) {
      // 10^8 * 10^6 = 10^14
      l -= ll(ys[i]-y) * vh;
      r += ll(ys[i]-y) * vh;

      // 2*10^8 * 10^6 = 2*10^14
      if(l<xs[i]*s) l = xs[i]*s;
      if(r>(xs[i]+W)*s) r = (xs[i]+W)*s;

      if (r < l) {
	ok = 0;
	break;
      }

      y = ys[i];
    }

    if (ok) lo = mid;
    else hi = mid;
  }

  if (lo==-1) {
    printf("IMPOSSIBLE\n");
  } else {
    printf("%d\n", ss[lo]);
  }
}
