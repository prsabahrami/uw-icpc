#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string.h>
#include <utility>
#include <queue>
#include <stack>
#include <iomanip>
#include <ctype.h>
#include <map>
#include <set>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <sstream>
#include <math.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <tuple>
#include <cmath>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>
#include <fstream>
#pragma comment(linker, "/STACK:67108864")

using namespace std;

typedef long long LL;

#define FOR(i,n) for(int i = 0;i < n;i++)
#define MP make_pair
#define PB push_back
#define ALL(a) (a).begin(),(a).end()
#define PII pair<int, int>
#define PLL pair<long long, long long>
#define CLEAR(a) memset(a, 0, sizeof(a))
#define ERASE(a) memset(a, -1, sizeof(a))
#define INF 2000000000
#define y1 uu1
#define y2 uu2
const double EPS = 1E-12;
const double PI = acos(-1.0);
const LL mod = 1000000007;

using namespace std;

int k;
double p;

double dp1[10050];
double dp2[1005];

double test(int n) {
  assert(n > 0);
  if (dp2[n] >= 0) return dp2[n];
  if (n == 1) return 1.0;
  double rv = 1.0;
  double x = 1.0;
  FOR(i, n) {
    x *= (1 - p);
  }
  rv += (1 - x) * n;
  dp2[n] = rv;
  return rv;
}

double get(int n) {
  if (n == 0) return 0.0;
  if (n == 1) return 1.0;
  if (dp1[n] > 0) return dp1[n];
  double rv = n;
  for (int m = 1; m <= min(n, k); m++) {
    rv = min(test(m) + get(n - m), rv);
  }
  dp1[n] = rv;
  return rv;
}

void solve() {
  int n;
  cin >> n >> k >> p;
  FOR(i, 10050) {
    dp1[i] = -1;
  }
  FOR(i, 1005) {
    dp2[i] = -1;
  }
  for (int i = 1; i <= k; i++) test(i);
  FOR(i, min(n, 10*k)) {
    get(i);
  }
  double rv;
  if (n <= 10*k) {
    rv = get(n);
  } else {
    double bst = n;
    for (int i = 1; i <= k; i++) {
      int diff = (n - 10*k);
      int f = diff / i;
      double val = (f+1) * test(i) + get(n - (f+1)*i);
      if (val < bst) bst = val;
    }
    rv = bst;
  }
  cout << fixed << setprecision(9) << rv << endl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0);
  solve();
  return 0;
}
