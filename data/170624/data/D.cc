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

void solve(int test_num) {
  (void) test_num;
  int N, X;
  scanf("%d %d", &N, &X);
  if (X > N - 1) {
    printf("-1\n");
    return;
  }
  vector<vector<int>> p(N), s(N);
  for (int i = 0, dog = 1; i < N; ++i) {
    for (int j = 1; j <= X; ++j) {
      p[i].push_back(dog);
      s[(i + j) % N].push_back(dog);
      ++dog;
    }
  }
  vector<int> perm(X * N + 1);
  for (int i = 1; i <= X * N; ++i)
    perm[i] = i;
  random_shuffle(perm.begin() + 1, perm.end());
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < X; ++j)
      printf("%d ", perm[p[i][j]]);
    for (int j = 0; j < X; ++j)
      printf("%d%c", perm[s[i][j]], " \n"[j == X - 1]);
  }
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
