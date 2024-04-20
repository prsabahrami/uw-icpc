#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
  registerTestlibCmd(argc, argv);
  const int N = inf.readInt();
  const int X = inf.readInt();
  if (X > N - 1) {
    ouf.readInt(-1, -1, "impossible should print -1");
    quit(_ok, "");
  }
  const int M = X * N;
  unordered_map<int, int> pri, sec;
  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j < X; ++j) {
      const int p = ouf.readInt(1, M, "P_{i,j}");
      if (pri.count(p) > 0)
        quitif(pri.count(p) > 0, _wa, "Dog %d has primary home %d and %d", p, pri[p], i);
      pri[p] = i;
    }
    for (int j = 0; j < X; ++j) {
      const int s = ouf.readInt(1, M, "S_{i,j}");
      if (sec.count(s) > 0)
        quitif(sec.count(s) > 0, _wa, "Dog %d has secondary home %d and %d", s, sec[s], i);
      sec[s] = i;
    }
  }
  set<pair<int, int>> all_edges;
  for (int dog = 1; dog <= M; ++dog) {
    quitif(pri[dog] == sec[dog], _wa, "Dog %d has same primary and secondary home", dog);
    quitif(all_edges.count({pri[dog], sec[dog]}) > 0, _wa, "Two dogs with same primary and secondary home");
    all_edges.insert({pri[dog], sec[dog]});
  }
  quit(_ok, "");
}
