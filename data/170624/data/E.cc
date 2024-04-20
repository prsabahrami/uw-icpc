#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dd;

const int MAX = 16;
int dp[1 << MAX];
int cost[MAX];
vector<int> sub_tree[MAX][1 << MAX];
vector<int> adj[MAX];
int adj_mask[1 << MAX];

int find_subtree(int start, int mask) {
  int sub = 1 << start;
  while (true) {
    const int new_sub = (sub | adj_mask[sub]) & mask;
    if (new_sub == sub)
      break;
    sub = new_sub;
  }
  return sub;
}

void solve(int test_num) {
  (void) test_num;
  int V;
  cin >> V;
  for (int v = 0; v < V; ++v)
    cin >> cost[v];
  memset(adj_mask, 0, sizeof(adj_mask));
  for (int a = 1, b; a < V; ++a) {
    cin >> b;
    --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    adj_mask[1 << a] |= 1 << b;
    adj_mask[1 << b] |= 1 << a;
  }
  for (int mask = 1; mask < (1 << V); ++mask)
    for (int v = 0; v < V; ++v)
      if (mask >> v & 1)
        adj_mask[mask] |= adj_mask[mask ^ 1 << v];
  for (int mask = 1; mask < (1 << V); ++mask) {
    for (int root = 0; root < V; ++root) {
      if (~mask >> root & 1)
        continue;
      for (int start : adj[root]) {
        if (~mask >> start & 1)
          continue;
        sub_tree[root][mask].push_back(find_subtree(start, mask ^ 1 << root));
      }
//      pln(root, mask, sub_tree[root][mask]);
    }
  }
  memset(dp, 0x7F, sizeof(dp));
  for (int v = 0; v < V; ++v)
    dp[1 << v] = 0;
  for (int mask = 1; mask < (1 << V); ++mask) {
    if (__builtin_popcount(mask) == 1)
      continue;
    for (int root = 0; root < V; ++root) {
      if (~mask >> root & 1)
        continue;
      int now = 0;
      for (int sub : sub_tree[root][mask])
        now = max(now, dp[sub]);
      now += cost[root];
      dp[mask] = min(dp[mask], now);
    }
  }
  printf("%d\n", dp[(1 << V) - 1]);
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
  for (int test = 1; test <= tests; ++test) {
    solve(test);
  }
#ifdef AZN
  cerr << "Took: " << ((chrono::system_clock::now() - start_time).count() / 1e9) << " s" << endl;
#endif
  return 0;
}
