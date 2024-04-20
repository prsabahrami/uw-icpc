#include <bits/stdc++.h>

using namespace std;

const int MAX = 100128;

int res = 0;

struct Laser {
  int x_score[2], y_score[2];
  int score, points;

  void recompute() {
    res -= points;
    points = max(x_score[0], x_score[1]) + max(y_score[0], y_score[1]);
    res += points;
  }
};

unordered_map<int, set<pair<int, Laser*>>> by_x, by_y; // coord1, coord2, id
Laser laser[MAX];

void solve(int test_num) {
  (void) test_num;
  int N;
  scanf("%d", &N);
  memset(laser, 0, sizeof(laser));
  for (int ii = 0, x, y; ii < N; ++ii) {
    scanf("%d %d %d", &x, &y, &laser[ii].score);
    auto it1 = by_x.find(x);
    if (it1 != by_x.end()) {
      auto it = it1->second.upper_bound({y, nullptr});
      if (it != it1->second.end()) {
        it->second->x_score[0] = laser[ii].score;
        it->second->recompute();
        laser[ii].x_score[1] = it->second->score;
      }
      if (it != it1->second.begin()) {
        --it;
        it->second->x_score[1] = laser[ii].score;
        it->second->recompute();
        laser[ii].x_score[0] = it->second->score;
      }
    }
    it1 = by_y.find(y);
    if (it1 != by_y.end()) {
      auto it = it1->second.upper_bound({x, nullptr});
      if (it != it1->second.end()) {
        it->second->y_score[0] = laser[ii].score;
        it->second->recompute();
        laser[ii].y_score[1] = it->second->score;
      }
      if (it != it1->second.begin()) {
        --it;
        it->second->y_score[1] = laser[ii].score;
        it->second->recompute();
        laser[ii].y_score[0] = it->second->score;
      }
    }
    by_x[x].insert({y, laser + ii});
    by_y[y].insert({x, laser + ii});
    laser[ii].recompute();
    printf("%d\n", res);
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
  for (int test = 1; test <= tests; ++test) {
    solve(test);
  }
#ifdef AZN
  cerr << "Took: " << ((chrono::system_clock::now() - start_time).count() / 1e9) << " s" << endl;
#endif
  return 0;
}
