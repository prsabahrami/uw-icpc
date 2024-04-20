#include <bits/stdc++.h>

#ifdef AZN

#include "../Azn.cpp"

#else
#define pln(...)
#define dbgln(...)
#endif

using namespace std;

typedef long long ll;
typedef double dd;

const int MAXL = 10;
unordered_set<ll> cnt[MAXL];

void solve(int test_num) {
  (void) test_num;
  int N;
  string S;
  cin >> N >> S;
//  N = 100000;
//  for (int i = 0; i < N; ++i)
//    S += rand() % 26 + 'a';
  // 19999378295
  for (int i = 0; i < N; ++i) {
    ll now1 = 0, now2 = 0;
    for (int off = 0; off < min(N, MAXL); ++off) {
      now1 = now1 * 26 + (S[(i + off) % N] - 'a');
      now2 = now2 * 26 + (S[(i - off + N) % N] - 'a');
      cnt[off].insert(now1);
      cnt[off].insert(now2);
    }
  }
  ll res = 2LL * N * max(0, N - MAXL);
  for (int off = 0; off < MAXL; ++off)
    res += cnt[off].size();
  cout << res << endl;
}

void init() {
}

int main() {
#ifdef AZN
  const auto start_time = chrono::system_clock::now();
  freopen("/Users/yfhuang/ACM_LOCAL/input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  srand(1223);
  init();
  int tests = 1;
//  cin >> tests;
//  scanf("%d", &tests);
  for (int test = 1; test <= tests; ++test) {
    solve(test);
  }
#ifdef AZN
  cerr << "Took: " << ((chrono::system_clock::now() - start_time).count() / 1e6) << " s" << endl;
#endif
  return 0;
}
