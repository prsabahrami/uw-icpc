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

const string LETS[5] = {
  "***************",
  "*.**.**..*.**..",
  "*******..*.****",
  "*.**.**..*.**..",
  "*.*************"
};

void solve(int test_num) {
  (void) test_num;
  int N;
  cin >> N;
  string str;
  cin >> str;
  for (int r = 0; r < 5; ++r) {
    for (int ch : str)
      for (int c = 0; c < 3; ++c)
        cout << LETS[r][3 * (ch - 'A') + c];
    cout << endl;
  }
}

void init() {
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
    solve(test);
  }
#ifdef AZN
  cerr << "Took: " << ((chrono::system_clock::now() - start_time).count() / 1e6) << " s" << endl;
#endif
  return 0;
}
