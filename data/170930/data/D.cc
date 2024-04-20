// https://oeis.org/A001524
#include <bits/stdc++.h>

using namespace std;

namespace {
#define VERA(i, a, b)for(auto i=(ll)(a);i<(ll)(b);++i)
#define ANDY(i, a, b)for(auto i=(ll)(a);i>(ll)(b);--i)

typedef long long ll;
const int MOD = int(1e9) + 7;

void Add(int& a, int b) {
  a += b;
  if (a >= MOD)
    a -= MOD;
}

void Solve(int test_num) {
  (void) test_num;
  ll H, N;
  cin >> H >> N;
  int res = 0;
  vector<int> dp(N + 1, 0);
  dp[0] = 1;
  VERA(i, 1, H + 1) {
    const int min_needed = i * (i + 1) / 2;
    if (min_needed > N)
      break;
    // left side
    VERA(x, 0, dp.size() - min_needed) {
      Add(dp[x + i], dp[x]);
    }
    Add(res, dp[N - min_needed]);
    // right side
    VERA(x, 0, dp.size() - min_needed) {
      Add(dp[x + i], dp[x]);
    }
  }
  cout << res << endl;
}

void init() {}
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
//  scanf("%d", &tests);
  for (int test = 1; test <= tests; ++test) {
    Solve(test);
  }
#ifdef AZN
  cerr << "Took: " << ((chrono::system_clock::now() - start_time).count() / 1e9) << " s" << endl;
#endif
  return 0;
}
