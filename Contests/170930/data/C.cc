#include <bits/stdc++.h>

using namespace std;

namespace {

#define VERA(i, a, b)for(auto i=(ll)(a);i<(ll)(b);++i)
#define ANDY(i, a, b)for(auto i=(ll)(a);i>(ll)(b);--i)

typedef long long ll;
typedef long double dd;

void Solve(ll test_num) {
  (void) test_num;
  int N, K;
  cin >> N >> K;
  --K;
//  N = 100000, K = 50000;
  vector<int> arr(N), cnt(N + 1);
  for (auto& a : arr) {
    cin >> a;
//    a = rand() % 2000000000;
  }
  sort(arr.begin(), arr.end());
  int low = 0, hig = arr.back() - arr.front();
  while (low <= hig) {
    const int mid = low + (hig - low) / 2;
    fill(cnt.begin(), cnt.end(), 0);
    {
      int lef = 0;
      VERA(i, 0, N) {
        while (lef < i && arr[i] - arr[lef] > mid)
          ++lef;
        if (i - lef >= K) {
          ++cnt[lef];
          --cnt[i + 1];
        }
      }
    }
    {
      int rig = 0;
      ANDY(i, N - 1, -1) {
        while (rig > i && arr[rig] - arr[i] > mid)
          --rig;
        if (rig - i >= K) {
          ++cnt[i];
          --cnt[rig + 1];
        }
      }
    }
    partial_sum(cnt.begin(), cnt.end(), cnt.begin());
    cnt.back() = -1;
    if (find(cnt.begin(), cnt.end(), 0) == cnt.end())
      hig = mid - 1;
    else
      low = mid + 1;
  }
  cout << low << endl;
}

void Init() {
}

}

int main() {
#ifdef AZN
  const auto start_time = chrono::system_clock::now();
  freopen("../../input.txt", "r", stdin);
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
