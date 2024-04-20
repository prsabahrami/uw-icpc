#include <bits/stdc++.h>

using namespace std;

namespace {

#define VERA(i, a, b)for(auto i=(ll)(a);i<(ll)(b);++i)
#define ANDY(i, a, b)for(auto i=(ll)(a);i>(ll)(b);--i)

typedef long long ll;
typedef long double dd;

void Solve(ll test_num) {
  (void) test_num;
  vector<int> arr(5);
  for (auto& a : arr)
    cin >> a;
  sort(arr.begin(), arr.end());
  int res = 0;
  VERA(i, 0, 5) {
    VERA(j, i + 1, 5) {
      VERA(k, j + 1, 5) {
        if (arr[i] + arr[j] > arr[k]) {
          ++res;
        }
      }
    }
  }
  cout << res << endl;
}

void Init() {
}

}

int main() {
#ifdef AZN
  const auto start_time = chrono::system_clock::now();
  freopen("../input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  srand(1223);
  Init();
  ll tests = 1;
//  cin >> tests;
  VERA(test, 1, tests + 1) {
    Solve(test);
  }
#ifdef AZN
  cerr << "Took: " << ((chrono::system_clock::now() - start_time).count() / 1e9) << " s" << endl;
#endif
  return 0;
}
